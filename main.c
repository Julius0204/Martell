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

int usec_without_sec(char leadingZeroes[], long long inputTime_usec) {
	int outputTime = inputTime_usec - inputTime_usec / sec_in_usec * sec_in_usec;
	int leadingZeroesCount = 0;
	for (int compare = sec_in_usec / 10; compare > outputTime; compare /= 10) {
		leadingZeroes[leadingZeroesCount] = '0';
		leadingZeroesCount++;
	}
	leadingZeroes[leadingZeroesCount] = 0;
	return outputTime;
}

void printTime(char name[], long long time_usec) {
	char leadingZeroes[7];
	int time_usec_without_sec = usec_without_sec(leadingZeroes, time_usec);
	printf("%s: %lld.%s%d s\n", name, time_usec / sec_in_usec, leadingZeroes, time_usec_without_sec);
}

int main(int argc, char *argv[]) {
	genHeightmap();
	initialize();
	refresh();
	genPad();
	initialMovementSetup();
	long long fullTimeDiff_usec = 0;
	long counter = 0;
	for (int inputKey = getch(); inputKey != 'q'; inputKey = getch()) {
		fullTimeDiff_usec += movement(inputKey);
		counter++;
	}
	endwin();
	long long averageTimeDiff_usec = fullTimeDiff_usec / counter;
	printTime("Full gameplay time", fullTimeDiff_usec);
	printTime("Average tick time", averageTimeDiff_usec);
	printf("Tick count: %ld\n", counter);
	return 0;
}
