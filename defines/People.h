#ifndef PEOPLE_H_
#define PEOPLE_H_
//include STL
//�����׼�� 
#include<conio.h>
#include<map>
//include custom library
//�����Զ����
#include "def"
#include "Map.h"
#include "init.h"
class People{
	public:
		struct node{
			int x,y;
			node(int xx=-1,int yy=-1):x(xx),y(yy){}
			bool operator!=(node a);
		}default_door={-1,-1};
	private:
		int move_f=defaults,x,y,lang;
		map<int,map<int,node> > doors;	
	public:
		People():move_f(defaults),x(1),y(1),lang(unable){}
		void set_f(Map &);
		void put_xy(Map &);
//		void save(Map &);
//		void imports(Map &);
};
#include "People.cpp"
#endif
