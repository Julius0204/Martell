#include "customCurses.h"

void initialize() {
	initscr();
	cbreak();
	noecho();
	keypad(stdscr, TRUE);
}
