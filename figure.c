#include <curses.h>
#include <stdlib.h>
#include <unistd.h>
#include "map.h"
#include "figure.h"
int move_right(int x);
int move_left(int x);
WINDOW *sub1;

void move_figure(){
int x_pos, y_pos, input;
x_pos=0;
y_pos=19;
input=0;

//First, add a figure into the subwindow one
char figure[] = "*\n|\n/\\";
mvwaddch(sub1,y_pos, x_pos, ACS_DIAMOND);
//mvwaddstr(sub1, y_pos, x_pos, figure);
mvwprintw(sub1, y_pos-5,x_pos+5, figure);
do{
move(y_pos, x_pos);
refresh();
wrefresh(sub1);
input = getch();
switch(input){	
	case ' ':
		if(y_pos>10){
		y_pos = jump(y_pos);
		mvwaddch(sub1, y_pos, x_pos,ACS_DIAMOND);
		usleep(1000);
		mvwaddch(sub1, y_pos, x_pos,ACS_DIAMOND);
		y_pos = move_down(y_pos);
		mvwaddch(sub1, y_pos, x_pos, ACS_DIAMOND);	
		mvwaddch(sub1, y_pos, x_pos, ' ');
		wrefresh(sub1);
		}
	break;
	case KEY_DOWN:
		if(y_pos<19){
		mvwaddch(sub1, y_pos,x_pos,' ');
		y_pos = move_down(y_pos);
		mvwaddch(sub1, y_pos,x_pos,ACS_DIAMOND);
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
		if(x_pos < 100-1){
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

int move_down(int y){
return y+=2;
}

int move_left(int x){
return --x;
}

int move_right(int x){
return ++x;
}
