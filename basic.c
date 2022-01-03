#include <curses.h>
#include "figure.h"
#include "map.h"
#include "basic.h"
WINDOW *sub1;
void start_game(){	
	/*call init_screen, initialize curses in terminal*/
	init_screen();
}
