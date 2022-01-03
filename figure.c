#include <curses.h>
#include <stdlib.h>
#include "map.h"
#include "figure.h"
#include <unistd.h>
WINDOW *sub1;

void move_figure(WINDOW *win){
int x_pos, y_pos, input;
x_pos=0;
y_pos=18;
input=0;
nodelay(stdscr, TRUE);
curs_set(0);
//First, add a figure into the subwindow one
mvwaddch(win,y_pos, x_pos, ACS_DIAMOND);
//use constants instead of "magic numbers"
const short space = 32;
const int sleep_num = 100000;

//here comes a do-while loop
//within this loop, the movement of the figure is implemented. 
//as long as the user is not typing q or Q, the user can move the figure on the map
do{
move(y_pos, x_pos);
refresh();
wrefresh(win);
input = getch();
if (input != ERR) {
  while (getch() == input);
}
switch(input){
	case ' ':
		if(y_pos>=18){
		mvwaddch(win, y_pos, x_pos,space);
		y_pos = jump(y_pos);
		mvwaddch(win, y_pos, x_pos,ACS_DIAMOND);
		wrefresh(win);
		usleep(sleep_num);
		mvwaddch(win, y_pos, x_pos,space);
                y_pos = jump(y_pos);
                mvwaddch(win, y_pos, x_pos,ACS_DIAMOND);
                wrefresh(win);
                usleep(sleep_num*4);
		mvwaddch(win, y_pos,x_pos,space);
                y_pos = move_down(y_pos);
                mvwaddch(win, y_pos,x_pos,ACS_DIAMOND);
		wrefresh(win);
		usleep(sleep_num);
		mvwaddch(win, y_pos,x_pos,space);
                y_pos = move_down(y_pos);
                mvwaddch(win, y_pos,x_pos,ACS_DIAMOND);
		wrefresh(win);
		usleep(sleep_num);
		}
	break;
	case KEY_LEFT:
		if(x_pos>0){
		mvwaddch(win, y_pos, x_pos,space);
		x_pos = move_left(x_pos);
		mvwaddch(win, y_pos,x_pos,ACS_DIAMOND);
		}
	break;
	case KEY_RIGHT:
		if(x_pos < COLS-1){
		mvwaddch(win, y_pos, x_pos,space);
		x_pos = move_right(x_pos);
		mvwaddch(win, y_pos,x_pos,ACS_DIAMOND);
		}
	break;
}
}while((input!='q') && (input!='Q'));
}

int jump(int y){
return y-=2;
}

int move_down(int y){
return y+=2;
}

int move_left(int x){
return --x;
}

int move_right(int x){
return ++x;
}
