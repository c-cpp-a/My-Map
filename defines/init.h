#ifndef INIT_H_
#define INIT_H_
//include STL
//导入标准库 
#include<cstdlib>
#include<string>
#include<conio.h>
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
#include "init.cpp"
#endif
