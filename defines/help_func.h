#ifndef HELP_FUNC_H_H_
#define HELP_FUNC_H_H_
//include STL
//导入标准库
#include<string>
#include<windows.h>
#include<iostream>
#include "def"
namespace{
	using namespace std;
	int lang=unable;
	int mode=normal;
	void print(const string s);
	void gotoxy(short x,short y);
	int ach_print(const string s,short starty);
	void map_print(const char &ch);
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
	void map_print(const char &ch){
		switch(::mode){
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
}
#endif
