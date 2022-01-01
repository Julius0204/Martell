#ifndef MAPGEN_H
#define MAPGEN_H

#define defMapLength 100

const short mapLength;
short heightmap[defMapLength];
const short maxHeightDiff;

void genHeightmap();
void genPad();

#endif // MAPGEN_H
