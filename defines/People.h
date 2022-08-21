#ifndef PEOPLE_H_
#define PEOPLE_H_
//include STL
//导入标准库 
#include<conio.h>
//include custom library
//导入自定义库
#include "def"
#include "Map.h"
class People{
	private:
		int move_f=defaults,x,y,lang;
	public:
		People():move_f(defaults),x(1),y(1),lang(unable){}
		void set_f(Map &);
		void put_xy(Map &);
};
#include "People.cpp"
#endif
