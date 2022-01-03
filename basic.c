#include <curses.h>
#include <stdlib.h>
#include "map.h"
#include "figure.h"
#include "basic.h"
WINDOW *sub1;
void start_game(){	
	/*call init_screen, initialize curses in terminal*/
	init_screen();
	//move_figure();
}
