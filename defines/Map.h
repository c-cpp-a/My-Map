#ifndef MAP_H_
#define MAP_H_
//include STL
//导入标准库 
#include<map>
#include<fstream>
#include<vector>
#include<algorithm>
//include custom library
//导入自定义库
#include "def"
using namespace std;
class Map{
	private:
		struct save_format{
			int x,y,c,t;
			save_format(int _x=0,int _y=0,int _c=0,int _t=0):x(_x),y(_y),c(_c),t(_t){}
			bool operator<(const save_format &a){
				if(x!=a.x){
					return x<a.x;
				} else if(y!=a.y){
					return y<a.y;
				} else{
					return t<a.t;
				}
			}
			bool operator==(const save_format &a){
				return (x==a.x && y==a.y);
			}
		};
	private:
		map<int,map<int,int>> a;
		vector<save_format> save_message;
		int nowt=0;
	public:
		void print(int,int,const int &);
		void change(int,int,int);
		bool issave(int,int);
		void imports(ifstream &);
		void save(ofstream &);
		map<int,int> operator[](const int i);
};
#endif
