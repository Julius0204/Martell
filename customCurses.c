/*
Copyright 2022 denotavail

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
