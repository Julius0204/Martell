/*
Copyright 2021, 2022 denotavail

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

#include "mapgen.h"
#include <stdlib.h>

// Heightmap:

const short mapLength = defMapLength;
// maximal height discrepancy from y=0:
const short maxHeightDiff = 10;

void genHeightmap() {
	// length of the flat area at the beginning (left side) of the map:
	const short entryLength = 10;
	srand(0); // set seed for rand()
	// x = horizontal position; y = vertical position
	for (short x = 0, y = 0; x < mapLength; x++) {
		// y changes with a 50% chance:
		if (x >= entryLength && rand() % 2 == 0) {
			// the chance of y getting higher or lower depends on the previous
			// height:
			if (rand() % (2 * maxHeightDiff) >= maxHeightDiff + y)
				y++;
			else
				y--;
		}
		heightmap[x] = y;
	}
}

// Pad:

short padHeight;
WINDOW *map;

void genPad() {
	padHeight = 2 * maxHeightDiff + 1;
	map = newpad(padHeight, mapLength);
	for (short x = 0; x < mapLength; x++) {
		mvwvline(map, maxHeightDiff - heightmap[x], x, '@',
				 maxHeightDiff + 1 + heightmap[x]);
	}
}

// show and refresh pad at position x:
void refPad(short x) {
	short xMax, yMax;
	getmaxyx(stdscr, yMax, xMax);
	prefresh(map, 0, x - xMax / 2, yMax - padHeight, xMax / 2 - x, yMax - 1,
			 xMax - 1);
}

void mvPadaddch(int y, int x, const chtype ch) {
	mvwaddch(map, maxHeightDiff - 1 + y, x, ch);
}
