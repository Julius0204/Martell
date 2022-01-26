#include "movement.h"
#include <sys/time.h>
#include <ncurses.h>

long long lastTime_usec = 0;
long long currentTime_usec = 0;
float posX = 0, posY = 0,
	  velocityX = 0, velocityY = 0;
long long accelerationTimeout_usec[4];
const char directionLeft = 0;
const char directionRight = 1;
const char directionUp = 2;
const char directionDown = 3;

void initialMovementSetup() {
	for (int i = 0; i < 4; i++)
		accelerationTimeout_usec[i] = 0;
}

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
	return (int) pos;
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

void acceleration(int inputKey) {
	char direction;
	if (inputKey == KEY_LEFT) {
		direction = directionLeft;
	} else if (inputKey == KEY_RIGHT) {
		direction = directionRight;
	} else if (inputKey == KEY_UP) {
		direction = directionUp;
	} else if (inputKey == KEY_DOWN) {
		direction = directionDown;
	} else return;
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

void movement() {
	int inputKey = getch();
	long long timeDiff_usec = getTimeDiff_usec();
	if (timeDiff_usec == 0) return;
	mvaddch(intPos(posY), intPos(posX), ' ');
	posX = calcPos(timeDiff_usec, posX, velocityX);
	posY = calcPos(timeDiff_usec, posY, velocityY);
	mvaddch(intPos(posY), intPos(posX), '@');
	acceleration(inputKey);
}
