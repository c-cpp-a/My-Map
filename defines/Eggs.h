#ifndef EGGS_H_
#define EGGS_H_
//include STL
//�����׼�� 
#include<string>
//include custom library
//�����Զ����
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
