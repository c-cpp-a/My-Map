#ifndef MAP_H_
#define MAP_H_
//include STL
//�����׼�� 
#include<map>
#include<fstream>
//include custom library
//�����Զ����
#include "def"
using namespace std;
class Map{
	private:
		map<int,map<int,int>> a;
		int downx=0,righty=0;
	public:
		void print(int,int);
		void change(int,int,int);
		bool issave(int,int);
//		void imports();
//		void save();
		map<int,int> operator[](const int i);
};
#endif
