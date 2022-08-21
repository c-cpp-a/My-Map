#ifndef PEOPLE_H_
#define PEOPLE_H_
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
