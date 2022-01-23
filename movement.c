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

int intPos(float pos) {
	return (int) (pos + 0.5);
}

float calcPos(long long timeDiff_usec, float pos, float velocity) {
	float newPos = pos + velocity * timeDiff_usec;
	int diffIntPos = intPos(newPos) - intPos(pos);
	if (diffIntPos > 1) {
		newPos = intPos(pos) + 1.49;
	} else if (diffIntPos < -1) {
		newPos = intPos(pos) - 1.5;
	}
	return newPos;
}

void movement() {
	long long timeDiff_usec = getTimeDiff_usec();
	if (timeDiff_usec == 0) return;
	velocityX = 0.000002; // debug
	velocityY = 0.000001; // debug
	posX = calcPos(timeDiff_usec, posX, velocityX);
	posY = calcPos(timeDiff_usec, posY, velocityY);
	mvaddch(intPos(posY), intPos(posX), '@');
}
