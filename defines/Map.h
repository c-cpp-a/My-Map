#ifndef MAP_H_
#define MAP_H_
#include<map>
#include "def"
using namespace std;
class Map{
	private:
		map<int,map<int,int>> a;
	public:
		void print(int x,int y);
		void change(int x,int y,int c);
		bool issave(int x,int y);
};
#include "Map.cpp"
#endif
