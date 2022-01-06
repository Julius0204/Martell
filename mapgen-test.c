#include "mapgen.h"
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
	initscr();
	cbreak();
	noecho();
	keypad(stdscr, TRUE);
	refresh();
	genPad();
	int x = 0;
	do {
		refPad(x);
		int ch = getch();
		if (ch == KEY_RIGHT) x++;
		else if (ch == KEY_LEFT) x--;
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
