#include <ncurses.h>
#include <stdlib.h>
#include <ncurses/panel.h>
#include <time.h>
#include "pan_imp.h"
void gen_pan(){
// Determine terminal type, initialize all curses data structures
initscr();
// enable colors
start_color();
// Enable the keypad of the user's terminal
keypad(stdscr,true);
// disable line buffering, making characters immediately available to the program
cbreak();
// disable echoing of characters typed by the user
noecho();
// create window and variables for coordinates
short x_bgn=10,y_bgn=5;
WINDOW *win_1 = newwin(LIN,COL,y_bgn, x_bgn);
// create panel, attach it to the window
PANEL *pan_1 = new_panel(win_1);
//draw an horizontal line, this time with the curses function mvwhline. 
//it requires a pointer to a window, a start point and a length. The length is col-1.
mvwhline(win_1,LIN-1,0,ACS_HLINE,COL-1);
//generating obstacles, pseudo randomly
//starting point is the time
srand(time(NULL));
short ran_hei=0, x_pos=1;
for(int i=0;i<COL-2;++i){
ran_hei = (rand()%5)+1;
for(int j=0;j<ran_hei&&x_pos<COL-2;++j){
mvwaddstr(win_1, (LIN-2)-j,x_pos, "@");
}
x_pos+=2;
}
//refreshing of virtual(!) screen, don't mix this up with refresh()!
update_panels();
//refreshing the physical screen
doupdate();
getch();
//important call of endwin, ending curses
endwin();
//terminating the program, no specified exit number, so set it to 0
exit(0);
}
