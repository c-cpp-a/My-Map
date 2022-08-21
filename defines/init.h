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
void set_parameters();
void set_lang();
void print_helper();
inline void init(){
	set_parameters();
	set_lang();
}
void create_door_helper();
#include "init.cpp"
#endif
