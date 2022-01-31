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
#include <stdio.h>
#include <ncurses.h>

void initialize() {
	initscr();
	cbreak();
	noecho();
	keypad(stdscr, TRUE);
	nodelay(stdscr, TRUE);
	curs_set(0);
}

int main(int argc, char *argv[]) {
	initialize();
	initialMovementSetup();
	long long fullTimeDiff_usec = 0;
	long counter = 0;
	for (int inputKey = getch(); inputKey != 'q'; inputKey = getch()) {
		fullTimeDiff_usec += movement(inputKey);
		refresh();
		counter++;
	}
	endwin();
	long long averageTimeDiff_usec = fullTimeDiff_usec / counter;
	printf("averageTimeDiff_usec: %lld\n", averageTimeDiff_usec);
	return 0;
}
