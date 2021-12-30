#include <curses.h>
#include <stdlib.h>
#include "map.h"
#include "figure.h"
#include <unistd.h>
int move_right(int x);
int move_left(int x);
int jump(int y);
int jump1(int y);
int move_down(int y);
WINDOW *sub1;

void move_figure(){
int x_pos, y_pos, input;
x_pos=0;
y_pos=19;
input=0;
nodelay(stdscr, TRUE);
curs_set(0);
//First, add a figure into the subwindow one
mvwaddch(sub1,y_pos, x_pos, ACS_DIAMOND);

do{
move(y_pos, x_pos);
refresh();
wrefresh(sub1);
input = getch();
if (input != ERR) {
  while (getch() == input);
}
switch(input){
	
	case ' ':
		if(y_pos>=19){
		mvwaddch(sub1, y_pos, x_pos,' ');
		y_pos = jump(y_pos);
		mvwaddch(sub1, y_pos, x_pos,ACS_DIAMOND);
		wrefresh(sub1);
		usleep(100000);
		mvwaddch(sub1, y_pos, x_pos,' ');
                y_pos = jump1(y_pos);
                mvwaddch(sub1, y_pos, x_pos,ACS_DIAMOND);
                wrefresh(sub1);
                usleep(400000);
		mvwaddch(sub1, y_pos,x_pos,' ');
                y_pos = move_down(y_pos);
                mvwaddch(sub1, y_pos,x_pos,ACS_DIAMOND);
		wrefresh(sub1);
		usleep(100000);
		mvwaddch(sub1, y_pos,x_pos,' ');
                y_pos = move_down(y_pos);
                mvwaddch(sub1, y_pos,x_pos,ACS_DIAMOND);
		wrefresh(sub1);
		usleep(100000);
		}
	break;
	case KEY_LEFT:
		if(x_pos>0){
		mvwaddch(sub1, y_pos, x_pos,' ');
		x_pos = move_left(x_pos);
		mvwaddch(sub1, y_pos,x_pos,ACS_DIAMOND);
		}
	break;
	case KEY_RIGHT:
		if(x_pos < COLS-1){
		mvwaddch(sub1, y_pos, x_pos,' ');
		x_pos = move_right(x_pos);
		mvwaddch(sub1, y_pos,x_pos,ACS_DIAMOND);
		}
	break;
}
}while((input!='q') && (input!='Q'));
endwin();
exit(0);
}

int jump(int y){
return y-=2;
}
int jump1(int y){
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
