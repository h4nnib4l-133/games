#include<iostream>
#include<ncurses.h>
#include<string>


int main(int argv, char** argc){
	
	move(5,5);

	std::string text = "Hello World!!";
	initscr();
	cbreak();
	noecho();
	clear();

	for(int i = 0; i < text.size(); ++i){
		addch(text[i]);
		addch(' ');
	}
	
	refresh();
	while(1);
	
	return 0;
}
