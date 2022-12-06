#ifndef INIT_H_
#define INIT_H_
//include STL
//导入标准库 
#include<string>
#include<cstdlib>
#include<cstdio>
#include<iostream>
#include<unistd.h>
using namespace std;
//include custom library
//导入自定义库
#include "def.h"
#include "People.h"
#include "Map.h"
void create_door_helper();
void set_parameters();
void set_lang();
void set_import(People &,Map &);
void screen_helper();
void print_helper();
inline void init(People &p,Map &h){
	set_parameters();
	set_lang();
	system("clear");
	set_import(p,h);
}
void settings();
#endif
