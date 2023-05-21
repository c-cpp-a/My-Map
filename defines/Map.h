#ifndef MAP_H_
#define MAP_H_
//include STL
//导入标准库 
#include<map>
#include<fstream>
#include<iostream>
#include<vector>
#include<algorithm>
//include custom library
//导入自定义库
using namespace std;
class Screen;
class Map{
	private:
		map<int,map<int,int>> a;
	public:
		void print(const int &,const int &,const int &,Screen &);
		void change(int,int,int);
		bool issave(int,int);
		void imports(ifstream &);
		void save(ofstream &);
		map<int,int> operator[](const int i);
};
#include "Screen.h"
#include "help_func.h"
void Map::print(const int &x,const int &y,const int &direct,Screen &screen){
	::gotoxy(0,0); 
	if(x>=COLS/2 && y>=LINES/2){
		for(int i=x-LINES/2+1;i<=x+LINES/2;i++){
			for(int j=y-COLS/2+1;j<=y+COLS/2;j++){
				if(i==x && j==y){
					::putchar('#');
					continue;
				}
				::map_print(a[i][j],screen);
			}
			putchar('\n');
		}
	} else if(x>=COLS/2){
		for(int i=x-LINES/2+1;i<=x+LINES/2;i++){
			for(int j=1;j<=COLS;j++){
				if(i==x && j==y){
					putchar('#');
					continue;
				}
				::map_print(a[i][j],screen);
			}
			putchar('\n');
		}
	} else if(y>=COLS/2){
		for(int i=1;i<=LINES;i++){
			for(int j=y-COLS/2+1;j<=y+COLS/2;j++){
				if(i==x && j==y){
					putchar('#');
					continue;
				}
				::map_print(a[i][j],screen);
			}
			putchar('\n');
		}
	} else{
		for(int i=1;i<=LINES;i++){
			for(int j=1;j<=COLS;j++){
				if(i==x && j==y){
					putchar('#');
					continue;
				}
				map_print(a[i][j],screen);
			}
			putchar('\n');
		}
	}
	if(screen.get_data().mode==debugger){
		string contents="pos=("+to_string(x)+","+to_string(y)+"),direct="+direct_content[screen.get_data().lang][direct];
		gotoxy(0,COLS);
		cout << contents;
	}
}
void Map::change(int x,int y,int c){
	a[x][y]=c;
}
bool Map::issave(int x,int y){
	return a[x][y]!=rock;
}
void Map::imports(ifstream &fin){
	int x,y,c;
	while(fin >> x >> y >> c){
		if(x==-1 && y==-1 && c==-1){
			break;
		}
		a[x][y]=c;
	}
}
void Map::save(ofstream &fout){
	for(auto it=a.begin();it!=a.end();++it){
		for(auto itj=(it->second).begin();itj!=(it->second).end();++itj){
			if((itj->second)!=floors){
				fout << (it->first) << ' ' << (itj->first) << ' ' << (itj->second) << endl;
			}
		}
	} 
	fout << "-1 -1 -1\n";
}
map<int,int> Map::operator[](const int i){
	return a[i];
}
#endif
