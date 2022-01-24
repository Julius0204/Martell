#include "movement.h"
#include <stdio.h>
#include <ncurses.h>

void initialize() {
	initscr();
	cbreak();
	noecho();
	keypad(stdscr, TRUE);
	nodelay(stdscr, TRUE);
}

int main() {
	initialize();
	while (1) {
		movement();
		refresh();
	}
	endwin();
	return 0;
}
