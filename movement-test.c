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

int main(int argc, char *argv[]) {
	initialize();
	initialMovementSetup();
	long long fullTimeDiff_usec = 0;
	long counter = 0;
	while (1) {
		fullTimeDiff_usec += movement();
		refresh();
		counter++;
	}
	endwin();
	long long averageTimeDiff_usec = fullTimeDiff_usec / counter;
	printf("averageTimeDiff_usec: %lld\n", averageTimeDiff_usec);
	return 0;
}
