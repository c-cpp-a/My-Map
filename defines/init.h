#ifndef INIT_H_
#define INIT_H_
//include STL
//�����׼�� 
#include<string>
#include<cstdlib>
#include<conio.h>
#include<iostream>
#include<windows.h>
using namespace std;
//include custom library
//�����Զ����
#include "def"
void create_door_helper();
void set_parameters();
void set_lang();
void set_import(People &,Map &);
void screen_helper();
void print_helper();
inline void init(People &p,Map &h){
	set_parameters();
	set_lang();
	system("CLS");
	set_import(p,h);
}
const int &get_lang();
void set_lang(const int); 
#endif
