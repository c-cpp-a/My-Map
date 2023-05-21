#ifndef HELP_FUNC_H_H_
#define HELP_FUNC_H_H_
//include STL
//导入标准库
#include<string>
#include<windows.h>
#include<conio.h>
#include<iostream>
#include "def"
class Screen;
namespace{
	using namespace std;
	void print(const string s);
	void gotoxy(short x,short y);
	int ach_print(const string s,short starty);
	void map_print(const char &ch,Screen &screen);
	void ShowCursor(bool visible);
	void screen_helper(const int &lang);
	void print_helper(Screen &screen);
	void create_door_helper(const int &lang);
}
#include "Screen.h"
namespace{
	void print(const string s){
		for(size_t len=s.length(),i=0U;i<len;i++){
			putchar(s[i]);
			Sleep(30);
		}
	}
	void gotoxy(short x,short y){
		COORD coord = {x, y}; 
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
	}
	int ach_print(const string s,short starty){
		int i=0;
		string tmp=s;
		while(tmp.length()>=ADD_COLS-1){
			gotoxy(COLS+2,starty+i);
			cout << string(tmp.begin(),tmp.begin()+ADD_COLS-2);
			tmp.erase(tmp.begin(),tmp.begin()+ADD_COLS-2);
			i++;
		}
		gotoxy(COLS+2,starty+i);
		cout << tmp;
		return starty+i+1;
	}
	void map_print(const char &ch,Screen &screen){
		switch(screen.get_data().mode){
		case normal:case debugger:
			putchar(print_c[ch]);
			break;
		case infernal:
			if(ch){
				putchar(print_c[ch]);
			}
			break;
		case AIOC:
			if(ch){
				putchar('-');
			} else{
				putchar(' ');
			}
			break;
		}
	}
	void ShowCursor(bool visible){
		CONSOLE_CURSOR_INFO cursor_info={20, visible};
		SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE),&cursor_info);
	}
	void screen_helper(const int &lang){
		using namespace std;
		if(lang==Chinese){
			//language:Chinese
			//语言：中文 
			cout << "\n帮助[H]\t设置[T]\n";
		} else if(lang==English){
			//language:English
			//语言：英文
			cout << "\nHelp[H]\nTools[T]\n";
		}
	} 
	void print_helper(Screen &screen){
		using namespace std;
		if(screen.get_data().lang==Chinese){
			//language:Chinese
			//语言：中文 
			cout << "\n :空地，可走动\t-:岩石，不可走动\t@:传送门\to:小球\t#:你自己\n"
			"WASD移动。\n"
			"清除物品[1]\t"
			"创建岩石[2]\t"
			"创建传送门[3]\t" 
			"创建小球[4]\n"
			"选择语言[L]\t"
			"关闭帮助[H]\n"
			"更多功能拓展中。。。\n";
		} else if(screen.get_data().lang==English){
			//language:English
			//语言：英文
			cout << "\n :open space, movable\t-: rock, not movable\t@: portal\to: ball\t#: yourself\n"
			"WASD moves.\n"
			"clear everything in the forward direction[1]\t"
			"create a rock in the forward direction[2]\t" 
			"create a portal in the forward direction[3]\t"
			"create a ball in the forward direction[4]\n"
			"select the language[L]\t"
			"close the help content[H]\n"
			"More function expansion...\n";
		}
		char a;
		do{
			a=getch();
			if(a=='l' || a=='L')	screen.init_lang(screen.get_data().lang); 
		}while(a!='H' && a!='h');
	}
	void create_door_helper(const int &lang){
		if(lang==Chinese){
			//language:Chinese
			//语言：中文
			cout << "\nWASD键移动，空格键确认放置传送门。\n";
		} else if(lang==English){
			//language:English
			//语言：英文
			cout << "\nWASD key to move, and space key to confirm to place the transfer door.\n";
		} 
	}
}
#endif
