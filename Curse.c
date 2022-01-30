#include <stdio.h>
#include <stdlib.h>
#include <curses.h>



WINDOW *create_newwin(int Hohe, int Breite, int ystart, int xstart){

		WINDOW *Character = newwin(Hohe, Breite, ystart, xstart);
		box(Character,0 ,0 );
		return(Character);



}

int main(){
	int input, x = 15, y = 10, H = 8, B = 8;

	initscr(); //clears the screen
		
	
	noecho(); //disables echo mode dh inputs of users are not echoed or not shown in the screen
	keypad(stdscr, TRUE); // keypad() enables reading of function keys like keypads and F1,F2 stdr means that the keypad feature will be enabled
	cbreak; //it makes the characters typed by the users available and executable for the program
	WINDOW* figure = create_newwin(H,B,x,y);




        while ((input=getch())!= 'q')
        {
                switch(input)
                {
                        case KEY_LEFT :
				 if (x>0)
				--x;	 
        			wclear(figure);
        			wprintw(figure, "    o>\n   /|/\n    X\n    \\\\");
        			wrefresh(figure);
        			napms(100);
        			wclear(figure);
        			wprintw(figure, "    o>\n    |\n    X\n    //");
        			wrefresh(figure);
        			napms(100);
				
				
				break;

                        case KEY_RIGHT 	: 
				if (x<(COLS-16)) 
				++x;
				wclear(figure);
                                wprintw(figure, "    o>\n   /|/\n    X\n    \\\\");
                                wrefresh(figure);
                                napms(100);
                                wclear(figure);
                                wprintw(figure, "    o>\n    |\n    X\n    //");
                                wrefresh(figure);
                                napms(100);


				break;

                        case ' ' :
				if (y >= 19) y-=2;
 	                        break;
				
                }
                mvwin(figure, y, x); //move window according to x and y
                wrefresh(figure); // wrefresh copiesthe window to the physical terminal screen
        //wclear(figure); //it clears the screen on the next call
        }
        delwin(figure);
        endwin();
        return 0;
	
}

