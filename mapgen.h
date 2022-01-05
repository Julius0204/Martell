#include <ncurses.h>

#ifndef MAPGEN_H
#define MAPGEN_H

#define defMapLength 100

// Heightmap:

const short mapLength;
short heightmap[defMapLength];
const short maxHeightDiff;

void genHeightmap();

// Pad:

short padHeight;
WINDOW *map;

void genPad();
void refPad(short x);

#endif // MAPGEN_H
