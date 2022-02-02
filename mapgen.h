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

#include <ncurses.h>

#ifndef MAPGEN_H
#define MAPGEN_H

#define defMapLength 500

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

WINDOW *init_new_win(int height, int length, int y_start, int x_start);
void delete_Windows(WINDOW *main_win);
#endif // MAPGEN_H
