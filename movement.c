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
#include <sys/time.h>
#include <ncurses.h>
#include <stdbool.h>

long long lastTime_usec = 0;
long long currentTime_usec = 0;
float posX = 0, posY = 0,
	  velocityX = 0, velocityY = 0;
long long accelerationTimeout_usec[4];
const char directionLeft = 0;
const char directionRight = 1;
const char directionUp = 2;
const char directionDown = 3;

bool collision();

long long getTimeDiff_usec() {
	struct timeval newTime;
	gettimeofday(&newTime, 0);
	currentTime_usec = (long long) newTime.tv_sec * 1000000 + newTime.tv_usec;
	if (lastTime_usec == 0) {
		lastTime_usec = currentTime_usec;
		return 0;
	}
	long long timeDiff_usec = currentTime_usec - lastTime_usec;
	if (timeDiff_usec == 0) return 0;
	lastTime_usec = currentTime_usec;
	return timeDiff_usec;
}

int intPos(float pos) {
	return (int) (pos + 0.5);
}

int collisionArea(float pos) {
	if (pos < 0) {
		int shift = 1 - (int) pos;
		return (int) (pos + shift) - shift;
	} else
		return (int) pos;
}

bool onGround() {
	if (posY - collisionArea(posY) > 0.9 &&
			collision(collisionArea(posX), collisionArea(posY) + 1))
		return true;
	else
		return false;
}

float calcPos(long long timeDiff_usec, float pos, float velocity) {
	float newPos = pos + velocity * timeDiff_usec;
	int diffCollisionArea = collisionArea(newPos) - collisionArea(pos);
	if (diffCollisionArea > 1) {
		newPos = collisionArea(pos) + 1.99;
	} else if (diffCollisionArea < -1) {
		newPos = collisionArea(pos) - 1.0;
	}
	return newPos;
}

bool isObstacle(int x, int y) {
	if (x < 0 || y < 0)
		return true;
	else {
		int xMax, yMax;
		getmaxyx(stdscr, yMax, xMax);
		if (x >= xMax || y >= yMax)
			return true;
		else
			return false;
	}
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

float resolveCollision(float pos, float *velocity) {
	if (*velocity > 0) {
		pos = collisionArea(pos) + 0.99;
	} else if (*velocity < 0) {
		pos = collisionArea(pos);
	}
	*velocity = 0;
	return pos;
}

void setPos(long long timeDiff_usec) {
	float newPosX = calcPos(timeDiff_usec, posX, velocityX),
		  newPosY = calcPos(timeDiff_usec, posY, velocityY);
	bool sameCollisionAreaX = collisionArea(newPosX) == collisionArea(posX);
	bool sameCollisionAreaY = collisionArea(newPosY) == collisionArea(posY);
	bool sameCollisionArea = sameCollisionAreaX && sameCollisionAreaY;
	if (!sameCollisionArea &&
			collision(collisionArea(newPosX), collisionArea(newPosY))) {
		if (!sameCollisionAreaX)
			newPosX = resolveCollision(posX, &velocityX);
		if (!sameCollisionAreaY)
			newPosY = resolveCollision(posY, &velocityY);
	}
	posX = newPosX;
	posY = newPosY;
}

void acceleration(char direction) {
	if (accelerationTimeout_usec[direction] > currentTime_usec) return;
	long long timeout_usec = 100000;
	accelerationTimeout_usec[direction] = currentTime_usec + timeout_usec;
	float velocityChange = 0.000001;
	if (direction == directionLeft) {
		velocityX -= velocityChange;
	} else if (direction == directionRight) {
		velocityX += velocityChange;
	} else if (direction == directionUp) {
		velocityY -= velocityChange;
	} else if (direction == directionDown) {
		velocityY += velocityChange;
	}
}

void evaluateInput(int inputKey) {
	if (inputKey == KEY_LEFT) {
		acceleration(directionLeft);
	} else if (inputKey == KEY_RIGHT) {
		acceleration(directionRight);
	} else if (inputKey == KEY_UP) {
		acceleration(directionUp);
	} else if (inputKey == KEY_DOWN) {
		acceleration(directionDown);
	}
}

void initialMovementSetup() {
	for (int i = 0; i < 4; i++)
		accelerationTimeout_usec[i] = 0;
	mvaddch(intPos(posY), intPos(posX), '@');
}

long long movement(int inputKey) {
	long long timeDiff_usec = getTimeDiff_usec();
	if (timeDiff_usec > 0 && (velocityX != 0 || velocityY != 0)) {
		mvaddch(intPos(posY), intPos(posX), ' ');
		setPos(timeDiff_usec);
		mvaddch(intPos(posY), intPos(posX), '@');
	}
	evaluateInput(inputKey);
	return timeDiff_usec;
}
