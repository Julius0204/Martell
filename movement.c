#include "movement.h"
#include <sys/time.h>

// Only for debugging purposes, remove later!
#include <stdio.h>

long long lastTime_usec = 0;
float posX = 0, posY = 0,
	  velocityX = 0, velocityY = 0;

void move() {
	struct timeval newTime;
	gettimeofday(&newTime, 0);
	long long currentTime_usec = (long long) newTime.tv_sec * 1000000 + newTime.tv_usec;
	printf("\n  lastTime_usec    = %lld\n  currentTime_usec = %lld\n", lastTime_usec, currentTime_usec);
	if (lastTime_usec == 0) {
		lastTime_usec = currentTime_usec;
		printf("\n  lastTime_usec    = %lld\n  currentTime_usec = %lld\n", lastTime_usec, currentTime_usec);
		return;
	}
	long long timeDiff_usec = currentTime_usec - lastTime_usec;
	printf("\n  timeDiff_usec = %lld\n", timeDiff_usec);
	if (timeDiff_usec == 0) return;
	lastTime_usec = currentTime_usec;
	printf("\n  lastTime_usec    = %lld\n  currentTime_usec = %lld\n", lastTime_usec, currentTime_usec);
}
