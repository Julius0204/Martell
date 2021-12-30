#include <curses.h>
#include <stdlib.h>
#include <unistd.h>
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
char figure[] = "*\n|\n/\\";
mvwaddch(sub1,y_pos, x_pos, ACS_DIAMOND);
//mvwaddstr(sub1, y_pos, x_pos, figure);
mvwprintw(sub1, y_pos-5,x_pos+5, figure);
do{
move(y_pos, x_pos);
refresh();
wrefresh(sub1);
input = getch();
<<<<<<< HEAD
<<<<<<< HEAD
switch(input){	
=======
=======
if (input != ERR) {
  while (getch() == input);
}
>>>>>>> 5d302123a6869e284269de2f083900a4caec6e8b
switch(input){
	
>>>>>>> 9fffea41a0ce9e3ae7b48192f0ba19edb9c48758
	case ' ':
<<<<<<< HEAD
		if(y_pos>10){
=======
		if(y_pos>=19){
		mvwaddch(sub1, y_pos, x_pos,' ');
>>>>>>> 5d302123a6869e284269de2f083900a4caec6e8b
		y_pos = jump(y_pos);
		mvwaddch(sub1, y_pos, x_pos,ACS_DIAMOND);
<<<<<<< HEAD
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
=======
		wrefresh(sub1);
		usleep(100000);
		mvwaddch(sub1, y_pos, x_pos,' ');
                y_pos = jump1(y_pos);
                mvwaddch(sub1, y_pos, x_pos,ACS_DIAMOND);
                wrefresh(sub1);
                usleep(400000);
>>>>>>> 9fffea41a0ce9e3ae7b48192f0ba19edb9c48758
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
