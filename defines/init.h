#ifndef INIT_H_
#define INIT_H_
//include STL
//�����׼�� 
#include<string>
#include<cstdlib>
#include<conio.h>
#include<iostream>
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
void create_door_helper();
#include "init.cpp"
#endif
