#include "mapgen.h"
#include <stdlib.h>
#include <ncurses.h>

const short mapLength = defMapLength;
// maximal height discrepancy from y=0:
const short maxHeightDiff = 10;

void genHeightmap() {
	// length of the flat area at the beginning (left side) of the map:
	const short entryLength = 10;
	srand(0); // set seed for rand()
	// x = horizontal position; y = vertical position
	for (short x=0, y=0; x < mapLength; x++) {
		// y changes with a 50% chance:
		if (x >= entryLength && rand()%2 == 0) {
			// the chance of y getting higher or lower depends on the previous height:
			if (rand() % (2*maxHeightDiff) >= maxHeightDiff + y)
				y++;
			else
				y--;
		}
		heightmap[x] = y;
	}
}

void genPad() {
	initscr();
	WINDOW *map = newpad(int nlines, int ncols);
	endwin();
}
