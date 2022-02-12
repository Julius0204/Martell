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

int main(int argc, char *argv[]) {
	genHeightmap();
	initialize();
	refresh();
	genPad();
	initialMovementSetup();
	long long fullTimeDiff_usec = 0;
	long long counter = 0;
	for (int inputKey = getch(); inputKey != 'q'; inputKey = getch()) {
		fullTimeDiff_usec += movement(inputKey);
		counter++;
	}
	endwin();
	double fullTimeDiff_sec = (double)fullTimeDiff_usec / sec_in_usec;
	double averageTimeDiff_sec = fullTimeDiff_sec / counter;
	printf("Full gameplay time: %f s\n", fullTimeDiff_sec);
	printf("Average tick time: %E s\n", averageTimeDiff_sec);
	printf("Tick count: %lld\n", counter);
	return 0;
}
