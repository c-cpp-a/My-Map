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
