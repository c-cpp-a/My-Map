#ifndef EGGS_H_
#define EGGS_H_
//include STL
//导入标准库 
#include<string>
//include custom library
//导入自定义库
#include "def"
#include "People.h"
class Egg{
	private:
	public:
		int isegg(const int &,People &,Map &);
		void check_run(const int &,People &,Map &);
};
#include "Eggs.cpp"
#endif
