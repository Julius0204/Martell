#include <curses.h>
#include <stdlib.h>
#include <ncurses/panel.h>
#include <time.h>
#include "map.h"
#include "figure.h"
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

//draw obstacles
int x_values[COL-2];
place_obstacles(sub1, x_values);

/*call move_figure to place it, and to move it*/
move_figure(sub1, x_values);
/*figure place*/

/*refreshing the panel*/
update_panels();
doupdate();
getch();
//terminating the programm
endwin();
exit(0);
}




//This function places obstacles, so that the figure has to jump and climb over them
void place_obstacles(WINDOW *win, int arr[]){
//the principle here is that the obstacles are placed pseudo-randomly
srand(time(NULL));

//An array in which the position of the obstacles are saved
short ran_hei=0, x_pos=10;
for(int i=0;i<COL-2;++i){
ran_hei = (rand()%5)+1;
for(int j=0;j<ran_hei&&x_pos<COL-2;++j){
mvwaddch(win, (LIN-2)-j, x_pos,ACS_CKBOARD);
}
arr[i] = x_pos;
x_pos+=5;
}
}

void draw_ground(WINDOW *win){
mvwhline(win, LIN-1, 0, ACS_HLINE, COL-1);
}
