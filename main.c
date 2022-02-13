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

#include "customCurses.h"
#include "mapgen.h"
#include "movement.h"
#include <ncurses.h>
#include <stdio.h>

#define sec_in_usec 1000000

void initialCursesSetup() {
	genHeightmap();
	initialize();
	refresh();
	genPad();
}

void printStats(long long fullTimeDiff_usec, long long counter) {
	double fullTimeDiff_sec = (double)fullTimeDiff_usec / sec_in_usec;
	double averageTimeDiff_sec = fullTimeDiff_sec / counter;
	printf("Full gameplay time: %f s\n", fullTimeDiff_sec);
	printf("Average tick time: %E s\n", averageTimeDiff_sec);
	printf("Tick count: %lld\n", counter);
}

void mainLoop(long long *fullTimeDiff_usec, long long *counter) {
	long long time_usec = 0;
	long long accelerationTimeout_usec[4];
	double pos[2], velocity[2];
	initialMovementSetup(accelerationTimeout_usec, pos, velocity);
	for (int inputKey = getch(); inputKey != 'q'; inputKey = getch()) {
		*fullTimeDiff_usec += movement(&time_usec, accelerationTimeout_usec,
									   pos, velocity, inputKey);
		(*counter)++;
	}
}

int main(int argc, char *argv[]) {
	initialCursesSetup();
	long long fullTimeDiff_usec = 0, counter = 0;
	mainLoop(&fullTimeDiff_usec, &counter);
	endwin();
	printStats(fullTimeDiff_usec, counter);
	return 0;
}
