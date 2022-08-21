#ifndef MAP_H_
#define MAP_H_
#include<map>
#include "def"
using namespace std;
class Map{
	private:
		map<int,map<int,int>> a;
	public:
		void print(int,int);
		void change(int,int,int);
		bool issave(int,int);
};
#include "Map.cpp"
#endif
