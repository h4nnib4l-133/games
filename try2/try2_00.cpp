#include <ncurses.h>
#include <iostream>
void init(){
	initscr();
	clear();
	noecho();
	cbreak();
	keypad(stdscr, TRUE);
	curs_set(0);

}

void erase(int row, int col){
	mvaddch(row, col, '#');
}

void game_loop(int row, int col, char main_char, int ch){

	if(ch == 'q' || ch == 'Q' ) return;
	mvaddch(row, col, main_char);
	refresh();
	for(;;){
		ch = getch();
		if(ch == KEY_LEFT){
			erase(row, col);
			col = col - 1;
			mvaddch(row, col, main_char);	
		}
		if(ch == KEY_RIGHT){
			erase(row, col);
			col = col + 1;
			mvaddch(row, col, main_char);	
		}
		if(ch == KEY_UP){
			erase(row, col);
			row = row - 1;
			mvaddch(row, col, main_char);	
		}
		if(ch == KEY_DOWN){
			erase(row, col);
			row = row + 1;
			mvaddch(row, col, main_char);	
		}
		if(ch == 'q' || ch == 'Q') break;

	}

}

int main(){

int row = 10, col = 10;
char main_char = '@';
init();
printw("Hello People Welcome to your doom; wanna play enter anything but not q/Q");
int ch = getch();
clear();
game_loop(row, col, main_char, ch);
endwin();
return 0;
}
