#ifndef INIT_H_
#define INIT_H_
//include STL
//�����׼�� 
#include<cstdlib>
#include<string>
#include<conio.h>
//include custom library
//�����Զ����
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
