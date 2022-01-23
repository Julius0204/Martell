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
	posX = posX + velocityX * timeDiff_usec,
	posY = posY + velocityY * timeDiff_usec;
}

void movement() {
	long long timeDiff_usec = getTimeDiff_usec();
	if (timeDiff_usec == 0) return;
	calcPos(timeDiff_usec);
	mvaddch((int) posY, (int) posX, '@');
}
