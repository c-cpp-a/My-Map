#ifndef INIT_H_
#define INIT_H_
//include STL
//导入标准库 
#include<string>
#include<cstdlib>
#include<conio.h>
#include<iostream>
//include custom library
//导入自定义库
#include "def"
void create_door_helper();
#include "People.h"
void set_parameters();
void set_lang();
void set_import(People &,Map &);
void print_helper();
inline void init(People &p,Map &h){
	set_parameters();
	set_lang();
	set_import(p,h);
}

#include "init.cpp"
#endif
