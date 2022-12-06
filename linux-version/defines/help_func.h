#ifndef HELP_FUNC_H_H_
#define HELP_FUNC_H_H_
//include STL
//导入标准库
#include<string>
#include<unistd.h>
//include custom library
//导入自定义库
#include "def.h"
namespace{
	using namespace std;
	int lang=unable;
	int mode=normal;
	void print(const string s);
	void gotoxy(short x,short y);
	int ach_print(const string s,short starty);
	void map_print(const char &ch);
}
#endif
