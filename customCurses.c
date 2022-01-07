#include "customCurses.h"

void initialize() {
	initscr();
	cbreak();
	noecho();
	keypad(stdscr, TRUE);
}

char left(int ch) {
	if ( 0
			|| ch == KEY_LEFT
			|| ch == 'a'
			|| ch == 'h'
			) return 1;
	else return 0;
}

char right(int ch) {
	if ( 0
			|| ch == KEY_RIGHT
			|| ch == 'd'
			|| ch == 'l'
			) return 1;
	else return 0;
}

char up(int ch) {
	if ( 0
			|| ch == KEY_UP
			|| ch == 'w'
			|| ch == 'k'
			|| ch == ' '
			) return 1;
	else return 0;
}

char down(int ch) {
	if ( 0
			|| ch == KEY_DOWN
			|| ch == 's'
			|| ch == 'j'
			) return 1;
	else return 0;
}
