/*
Copyright 2022 denotavail

This file is part of SuperCursey.

SuperCursey is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

#include "movement.h"
#include "customCurses.h"
#include "mapgen.h"
#include <ncurses.h>
#include <stdbool.h>
#include <sys/time.h>

const char Xcoordinate = 0, Ycoordinate = 1;
const char directionLeft = 0, directionRight = 1, directionUp = 2,
		   directionDown = 3;

bool collision();

long long getTimeDiff_usec(long long *lastTime_usec) {
	struct timeval newTime;
	gettimeofday(&newTime, 0);
	long long currentTime_usec =
		(long long)newTime.tv_sec * 1000000 + newTime.tv_usec;
	if (*lastTime_usec == 0) {
		*lastTime_usec = currentTime_usec;
		return 0;
	}
	long long timeDiff_usec = currentTime_usec - *lastTime_usec;
	if (timeDiff_usec == 0)
		return 0;
	*lastTime_usec = currentTime_usec;
	return timeDiff_usec;
}

int posToInt(double pos, double shift) {
	double shiftPos = pos + shift;
	if (shiftPos < 0) {
		int tmpShift = 1 - (int)shiftPos;
		return (int)(shiftPos + tmpShift) - tmpShift;
	} else
		return (int)shiftPos;
}

int intPos(double pos) { return posToInt(pos, 0.5); }

int collisionArea(double pos) { return posToInt(pos, 0); }

bool onGround(double pos[]) {
	if (pos[Ycoordinate] - collisionArea(pos[Ycoordinate]) > 0.9 &&
		collision(collisionArea(pos[Xcoordinate]),
				  collisionArea(pos[Ycoordinate]) + 1))
		return true;
	else
		return false;
}

double calcPos(long long timeDiff_usec, double pos, double *velocity,
			   bool gravity) {
	double newPos = pos + *velocity * timeDiff_usec;
	if (gravity) {
		double gravitationalAcceleration = 0.00000000002;
		newPos +=
			0.5 * gravitationalAcceleration * timeDiff_usec * timeDiff_usec;
		*velocity += gravitationalAcceleration * timeDiff_usec;
	}
	int diffCollisionArea = collisionArea(newPos) - collisionArea(pos);
	if (diffCollisionArea > 1) {
		newPos = collisionArea(pos) + 1.99;
	} else if (diffCollisionArea < -1) {
		newPos = collisionArea(pos) - 1.0;
	}
	return newPos;
}

bool isObstacle(int x, int y) {
	if (x < 0 || x >= mapLength || -y < heightmap[x])
		return true;
	else
		return false;
}

bool collision(int collisionAreaX, int collisionAreaY) {
	if (isObstacle(collisionAreaX, collisionAreaY) ||
		isObstacle(collisionAreaX, collisionAreaY + 1) ||
		isObstacle(collisionAreaX + 1, collisionAreaY) ||
		isObstacle(collisionAreaX + 1, collisionAreaY + 1))
		return true;
	else
		return false;
}

double resolveCollision(double pos, double newPos, double *velocity) {
	int currentCollisionArea = collisionArea(pos);
	int newCollisionArea = collisionArea(newPos);
	if (newCollisionArea > currentCollisionArea) {
		pos = currentCollisionArea + 0.99;
	} else if (newCollisionArea < currentCollisionArea) {
		pos = currentCollisionArea;
	}
	*velocity = 0;
	return pos;
}

void setPos(long long timeDiff_usec, double pos[], double velocity[]) {
	double newPos[2];
	newPos[Xcoordinate] =
		calcPos(timeDiff_usec, pos[Xcoordinate], &velocity[Xcoordinate], false),
	newPos[Ycoordinate] =
		calcPos(timeDiff_usec, pos[Ycoordinate], &velocity[Ycoordinate],
				!onGround(pos) || velocity[Ycoordinate] < 0);
	bool sameCollisionAreaFor[2];
	for (int i = 0; i < 2; i++)
		sameCollisionAreaFor[i] =
			collisionArea(newPos[i]) == collisionArea(pos[i]);
	bool sameCollisionArea =
		sameCollisionAreaFor[Xcoordinate] && sameCollisionAreaFor[Ycoordinate];
	if (!sameCollisionArea && collision(collisionArea(newPos[Xcoordinate]),
										collisionArea(newPos[Ycoordinate]))) {
		for (int i = 0; i < 2; i++) {
			if (!sameCollisionAreaFor[i])
				newPos[i] = resolveCollision(pos[i], newPos[i], &velocity[i]);
		}
	}
	for (int i = 0; i < 2; i++)
		pos[i] = newPos[i];
}

void acceleration(char direction, long long time_usec,
				  long long accelerationTimeout_usec[], double velocity[]) {
	if (accelerationTimeout_usec[direction] > time_usec)
		return;
	long long timeout_usec = 100000;
	accelerationTimeout_usec[direction] = time_usec + timeout_usec;
	double velocityChange = 0.000002;
	if (direction == directionLeft) {
		velocity[Xcoordinate] -= velocityChange;
	} else if (direction == directionRight) {
		velocity[Xcoordinate] += velocityChange;
	} else if (direction == directionUp) {
		velocity[Ycoordinate] = -0.000015;
	}
}

void evaluateInput(int inputKey, long long time_usec,
				   long long accelerationTimeout_usec[], double pos[],
				   double velocity[]) {
	if (left(inputKey)) {
		acceleration(directionLeft, time_usec, accelerationTimeout_usec,
					 velocity);
	} else if (right(inputKey)) {
		acceleration(directionRight, time_usec, accelerationTimeout_usec,
					 velocity);
	} else if (up(inputKey) && onGround(pos)) {
		acceleration(directionUp, time_usec, accelerationTimeout_usec,
					 velocity);
	}
}

bool isMoving(double pos[], double velocity[]) {
	return velocity[Xcoordinate] != 0 || velocity[Ycoordinate] != 0 ||
		   !onGround(pos);
}

void updateScreen(int oldIntPos[], double pos[]) {
	if (oldIntPos[Xcoordinate] != intPos(pos[Xcoordinate]) ||
		oldIntPos[Ycoordinate] != intPos(pos[Ycoordinate])) {
		mvPadaddch(oldIntPos[Ycoordinate], oldIntPos[Xcoordinate], ' ');
		mvPadaddch(intPos(pos[Ycoordinate]), intPos(pos[Xcoordinate]), 'A');
		refPad(intPos(pos[Xcoordinate]));
	}
}

void initialTimeoutSetup(long long accelerationTimeout_usec[]) {
	for (int i = 0; i < 4; i++)
		accelerationTimeout_usec[i] = 0;
}

void initialPosSetup(double pos[]) {
	pos[Xcoordinate] = 0;
	pos[Ycoordinate] = -0.01;
}

void initialVelocitySetup(double velocity[]) {
	velocity[Xcoordinate] = 0;
	velocity[Ycoordinate] = 0;
}

void initialMovementSetup(long long accelerationTimeout_usec[], double pos[],
						  double velocity[]) {
	initialTimeoutSetup(accelerationTimeout_usec);
	initialPosSetup(pos);
	initialVelocitySetup(velocity);
	mvPadaddch(intPos(pos[Ycoordinate]), intPos(pos[Xcoordinate]), 'A');
	refPad(intPos(pos[Xcoordinate]));
}

long long movement(long long *time_usec, long long accelerationTimeout_usec[],
				   double pos[], double velocity[], int inputKey) {
	long long timeDiff_usec = getTimeDiff_usec(time_usec);
	if (timeDiff_usec > 0 && isMoving(pos, velocity)) {
		int oldIntPos[2];
		for (int i = 0; i < 2; i++)
			oldIntPos[i] = intPos(pos[i]);
		setPos(timeDiff_usec, pos, velocity);
		updateScreen(oldIntPos, pos);
	}
	evaluateInput(inputKey, *time_usec, accelerationTimeout_usec, pos,
				  velocity);
	return timeDiff_usec;
}
