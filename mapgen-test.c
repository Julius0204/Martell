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
#include "customCurses.h"
#include <stdio.h>
#include <string.h>

void printHeightmap() {
	genHeightmap();
	for (int x=0; x<mapLength; x++) {
		for (int y=0; y < 2*(maxHeightDiff+1); y++) {
			if (y < heightmap[x] + maxHeightDiff+1)
				printf("@");
			else
				printf(" ");
		}
		printf("%d\n", heightmap[x]);
	}
}

void padHeightmap() {
	genHeightmap();
	initialize();
	refresh();
	genPad();
	refresh();
	int x = 0;
	int y = 20;
	do {
		refPad(x);
		WINDOW* windows;
        	int height,length, x_start, input;
        	initscr();
        	cbreak();
        	height = 1;
        	length = 1;
        	x_start = 20;
        	keypad(stdscr, TRUE);
        	noecho();
		curs_set(0);
        	windows = init_new_win(height, length, y, x_start);
		wrefresh(windows);
		int ch = getch();
		if (right(ch)) x++;
		else if (left(ch)) x--;
		else if (up(ch)){
			y--;
			mvwin(windows, y,x_start);
		}
		else if (down(ch)){
			y++;
			mvwin(windows,y,x_start);

		}
		else if (ch != KEY_RESIZE) break;
	} while (true);
	endwin();
}

int main(int argc, char *argv[]) {
	if (argc == 2) {
		if (strcmp(argv[1], "print") == 0) {printHeightmap(); return 0;}
		else if (strcmp(argv[1], "pad") == 0) {padHeightmap(); return 0;}
	}
	printf("You must specify exactly one argument which can be either 'print' or 'pad'.\n");
	return 0;
}
