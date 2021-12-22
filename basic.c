#include <curses.h>
#include <stdlib.h>
#include "basic.h"
WINDOW *sub1;

void init_screen(){
    int input;
    do {
        input = getch();
        initscr();
        keypad(stdscr, TRUE);
        cbreak();
        raw();
        noecho();
        start_color();
        init_pair(BASIC_WINDOW, COLOR_BLUE, COLOR_BLACK);
        bkgd(COLOR_PAIR(BASIC_WINDOW));
        sub1 = newwin(25,100,5,10);
        init_pair(SUB_WINDOW, COLOR_YELLOW, COLOR_GREEN);
        wbkgd(sub1, COLOR_PAIR(SUB_WINDOW));
        draw_map();
        refresh();
        wrefresh(sub1);
    }while((input!='q') && (input!='Q'));
    endwin();
    exit(0);
}
void draw_map(){
    for(int i=0;i<=108;++i){
        mvwaddch(sub1, 20, i, ACS_HLINE);
    }
}


void move_figure(){

}







