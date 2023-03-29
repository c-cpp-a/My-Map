#ifndef INIT_H_
#define INIT_H_
//include STL
//导入标准库 
#include<string>
#include<cstdlib>
#include<conio.h>
#include<iostream>
#include<windows.h>
using namespace std;
//include custom library
//导入自定义库
void create_door_helper();
void set_parameters();
void set_lang();
void set_import(People &,Map &,Egg &egg);
void screen_helper();
void print_helper();
inline void init(People &p,Map &h,Egg &egg){
	set_parameters();
	set_lang();
	system("CLS");
	set_import(p,h,egg);
}
void settings();
void save(People &,Map &,Egg &);
#endif
