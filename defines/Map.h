#ifndef MAP_H_
#define MAP_H_
//include STL
//�����׼�� 
#include<map>
#include<fstream>
#include<vector>
#include<algorithm>
//include custom library
//�����Զ����
#include "def"
using namespace std;
class Map{
	private:
		map<int,map<int,int>> a;
	public:
		void print(int,int,const int &);
		void change(int,int,int);
		bool issave(int,int);
		void imports(ifstream &);
		void save(ofstream &);
		map<int,int> operator[](const int i);
};
#endif
