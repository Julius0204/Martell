#include <curses.h>
#include <stdlib.h>
#include "map.h"
#include "figure.h"
WINDOW *sub1;

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
sub1 = newwin(25,100,5,10);
init_pair(SUB_WINDOW1,COLOR_BLUE,COLOR_GREEN);
wbkgd(sub1, COLOR_PAIR(SUB_WINDOW1));
/*initialized sub1*/

/*call draw_ground to draw a ground*/
draw_ground();
/*ground is drawn*/

/*call move_figure to place it, and to move it*/
move_figure();
/*figure place*/

/*refresh*/
refresh();
wrefresh(sub1);

}

void draw_ground(){
    for(int i=0;i<=108;++i){
        mvwaddch(sub1, 20, i, '^');
    }
}
