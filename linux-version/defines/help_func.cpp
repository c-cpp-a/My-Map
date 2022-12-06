#ifndef HELP_FUNC_CPP_CPP
#define HELP_FUNC_CPP_CPP
#include <cstddef>
#include<cstdio>
#include<iostream>
#include<unistd.h>
#include "def.h"
#include "help_func.h"
namespace{
	using namespace std;
	void print(const string s){
		for(std::size_t len=s.length(),i=0;i<len;i++){
			putchar(s[i]);
			usleep(300);
		}
	}
	void gotoxy(short x,short y){
    	cout << char(0x1B) << '[' << y << x;
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