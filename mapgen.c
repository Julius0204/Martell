#include "mapgen.h"
#include <stdlib.h>

const short mapLength = 100;
short heightmap[mapLength];

void genHeightmap() {
	// length of the flat area at the beginning (left side) of the map:
	const short entryLength = 10;
	// maximal height discrepancy from y=0:
	const short maxHeightDiff = 10;
	srand(0); // set seed for rand()
	// x = horizontal position; y = vertical position
	for (short x, y = 0; x < mapLength; x++) {
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
