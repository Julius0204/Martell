#include "movement.h"
#include <sys/time.h>
#include <ncurses.h>

long long lastTime_usec = 0;
float posX = 0, posY = 0,
	  velocityX = 0, velocityY = 0;

long long getTimeDiff_usec() {
	struct timeval newTime;
	gettimeofday(&newTime, 0);
	long long currentTime_usec = (long long) newTime.tv_sec * 1000000 + newTime.tv_usec;
	if (lastTime_usec == 0) {
		lastTime_usec = currentTime_usec;
		return 0;
	}
	long long timeDiff_usec = currentTime_usec - lastTime_usec;
	if (timeDiff_usec == 0) return 0;
	lastTime_usec = currentTime_usec;
	return timeDiff_usec;
}

void calcPos(long long timeDiff_usec) {
	velocityX = 0.000002; // debug
	velocityY = 0.000001; // debug
	float newPosX = posX + velocityX * timeDiff_usec,
		  newPosY = posY + velocityY * timeDiff_usec;
	int intPosX = (int) (posX + 0.5),
		intPosY = (int) (posY + 0.5),
		intNewPosX = (int) (newPosX + 0.5),
		intNewPosY = (int) (newPosY + 0.5);
	int diffIntPosX = intNewPosX - intPosX;
	int diffIntPosY = intNewPosY - intPosY;
	if (diffIntPosX > 1) {
		newPosX = intPosX + 1.49;
		intNewPosX = intPosX + 1;
	} else if (diffIntPosX < -1) {
		newPosX = intPosX - 1.5;
		intNewPosX = intPosX - 1;
	}
	if (diffIntPosY > 1) {
		newPosY = intPosY + 1.49;
		intNewPosY = intPosY + 1;
	} else if (diffIntPosY < -1) {
		newPosY = intPosY - 1.5;
		intNewPosY = intPosY - 1;
	}
}

void movement() {
	long long timeDiff_usec = getTimeDiff_usec();
	if (timeDiff_usec == 0) return;
	calcPos(timeDiff_usec);
	mvaddch((int) posY, (int) posX, '@');
}
