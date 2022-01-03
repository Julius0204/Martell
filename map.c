#include <curses.h>
#include <stdlib.h>
#include <ncurses/panel.h>
#include "map.h"
#include "figure.h"
//WINDOW *sub1 = newwin(20,80,5,10);
void init_screen(){
/*initialize screen*/
initscr();
keypad(stdscr,TRUE);
cbreak();
noecho();
/*screen initialized*/

/*initialize color for the BASIC_WINDOW*/
start_color();
init_pair(BASIC_WINDOW,COLOR_BLUE,COLOR_YELLOW);
bkgd(COLOR_PAIR(BASIC_WINDOW));
/*color initialized for BASIC_WINDOW*/

/*initialize sub1*/
WINDOW *sub1 = newwin(LIN,COL,5,10);
init_pair(SUB_WINDOW1,COLOR_BLUE,COLOR_GREEN);
wbkgd(sub1, COLOR_PAIR(SUB_WINDOW1));
/*initialized sub1*/

/*initialize panel, attach it to the window*/
PANEL *pan1 = new_panel(sub1);
/*panel succesfully created & attached*/

/*call draw_ground to draw a ground*/
draw_ground(sub1);
/*ground is drawn*/

/*call move_figure to place it, and to move it*/
//move_figure();
/*figure place*/

/*refreshing the panel*/
update_panels();
doupdate();
getch();
//terminating the programm
endwin();
exit(0);
}

void draw_ground(WINDOW *win){
mvwhline(win, LIN-1, 0, ACS_HLINE, COL-1);
}
