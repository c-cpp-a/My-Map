#ifndef PEOPLE_H_
#define PEOPLE_H_
//include STL
//导入标准库 
#include<conio.h>
#include<map>
#include<fstream>
//include custom library
//导入自定义库
#include "def"
using namespace std;
class Map;
class Egg;
class Screen;
class People{
	public:
		friend class Egg;
	public:
		struct node{
			int x,y;
			node(int xx=-1,int yy=-1):x(xx),y(yy){}
			bool operator!=(const node a) const;
			bool operator==(const node a) const;
			bool check();
			node &operator=(const node &)=default;
		};
		static const node default_node;
	private:
		bool canedit;
		int move_f=defaults;
		node pos;
		map<int,map<int,node> > doors;
		node check_xy(node x,const int &func); 
		const int back(const int &);
	public:
		People(bool _edit=true):canedit(_edit),move_f(defaults),pos({1,1}){}
		void move(Map &h,Egg &egg,Screen &screen,const char &command);
		inline const node &at(int x,int y){
			return doors[x][y];
		}
		inline const node &get_pos() const{
			return pos;
		}
		inline const int &get_movef() const{
			return move_f;
		}
		inline const bool &edit() const{
			return canedit;
		}
		void save(ostream &);
		void imports(istream &);
};
#include "Map.h"
#include "Eggs.h"
//#include "init.h"
#include "Screen.h"
const People::node People::default_node={-1,-1};
bool People::node::operator!=(const People::node a) const{
	return x!=a.x || y!=a.y;
}
bool People::node::operator==(const People::node a) const{
	return x==a.x && y==a.y;
}
bool People::node::check(){
	return x>=1 && y>=1;
}
People::node People::check_xy(node x,const int &func){
	node res=x;
	switch(func){
	case ups:
		res.x--;
		break;
	case downs:
		res.x++;
		break;
	case lefts:
		res.y--;
		break;
	case rights:
		res.y++;
		break;
	}
	return (res.check()?res:x);
}
const int People::back(const int &func){
	switch(func){
	case ups:
		return downs;
	case downs:
		return ups;
	case lefts:
		return rights;
	case rights:
		return lefts;
	}
	return func;
}
void People::move(Map &h,Egg &egg,Screen &screen,const char &command){
	if(pos.x<=0 || pos.y<=0)	egg.set_ach(8,1);
	if(egg[8] && pos.y>0 && pos.x>0){
		egg.set_ach(9,1);
	}
	switch(command){
	case 'W':case 'w':
		if(!h.issave(pos.x-1,pos.y))	break;
		if(pos.x>1){
			pos.x--;
			move_f=ups;
		}
		break;
	case 'A':case 'a':
		if(!h.issave(pos.x,pos.y-1))	break;
		if(pos.y>1){
			pos.y--;
			move_f=lefts;
		}
		break;
	case 'S':case 's':
		if(!h.issave(pos.x+1,pos.y))	break;
		pos.x++;
		move_f=downs;
		break;
	case 'D':case 'd':
		if(!h.issave(pos.x,pos.y+1))	break;
		pos.y++;
		move_f=rights;
		break;
	case 'H':case 'h':
		screen.clear();
		print_helper(screen);
		break;
	case 'L':case 'l':
		screen.clear();
		screen.init_lang(screen.get_data().lang);
		break; 
	case 'T':case 't':
		screen.clear();
		screen.setting();
		break;
	}
	if(canedit){
		switch(command){
			case '1':
			{
				auto tmp=check_xy(pos,move_f);
				h.change(tmp.x,tmp.y,floors);
				doors[tmp.x][tmp.y]=default_node;
				if(egg.is_ach())	egg.set_ach(0,1);
			}
			break;
			case '2':
			{
				auto tmp=check_xy(pos,move_f);
				h.change(tmp.x,tmp.y,rock);
				doors[tmp.x][tmp.y]=default_node;
				if(egg.is_ach())	egg.set_ach(1,1);
			}
			break;
			case '3':
			{
				int input=0;
				auto tmp=check_xy(pos,move_f),tmp2=tmp;
				h.change(tmp.x,tmp.y,door);
				while(input!=' '){
					h.print(tmp2.x,tmp2.y,move_f,screen);
					create_door_helper(screen.get_data().lang);
					input=getch();
					switch(input){
					case 'W':case 'w':
						if(tmp2.x>1)	tmp2.x--;
						break;
					case 'A':case 'a':
						if(tmp2.y>1)	tmp2.y--;
						break;
					case 'S':case 's':
						tmp2.x++;
						break;
					case 'D':case 'd':
						tmp2.y++;
						break;
					}
				}
				doors[tmp.x][tmp.y]=tmp2;
				if(egg.is_ach())	egg.set_ach(2,1);
			}
			break; 
			case '4':
			{
				auto tmp=check_xy(pos,move_f);
				h.change(tmp.x,tmp.y,ball);
				doors[tmp.x][tmp.y]=default_node;
				if(egg.is_ach())	egg.set_ach(3,1);
			}
			break;
		}
	}
	
	if(doors[pos.x][pos.y]!=default_node){
		auto tmp=pos;
		pos.x=doors[tmp.x][tmp.y].x;
		pos.y=doors[tmp.x][tmp.y].y;
		if(egg.is_ach())	egg.set_ach(4,1);
	} else if(h[pos.x][pos.y]==ball){
		auto tmp=pos;
		bool flag=true;
		while(h[tmp.x][tmp.y]!=floors){
			if(h[tmp.x][tmp.y]==rock || !tmp.check()){
				flag=false;
				break;
			}
			tmp=check_xy(tmp,move_f);
		}
		if(flag){
			h.change(tmp.x,tmp.y,ball);	
			h.change(pos.x,pos.y,floors);
			if(egg.is_ach())	egg.set_ach(5,1);
		} else{
			pos=check_xy(pos,back(move_f));
		}
	}
}
void People::save(ostream &fout){
	fout << pos.x << ' ' << pos.y << ' ' << move_f << endl;
	for(auto it=doors.begin();it!=doors.end();++it){
		for(auto itj=(it->second).begin();itj!=(it->second).end();++itj){
			if((itj->second)!=default_node){
				fout << (it->first) << ' ' << (itj->first) << ' ' << (itj->second).x << ' ' << (itj->second).y << endl;
			}
		}
	} 
	fout << "-1 -1 -1 -1 \n";
}
void People::imports(istream &fin){
	fin >> pos.x >> pos.y >> move_f;
	int xi,yi,xv,yv;
	while(fin >> xi >> yi >> xv >> yv){
		if(xi==-1 && yi==-1 && xv==-1 && yv==-1){
			break;
		} else{
			doors[xi][yi]=node({xv,yv});
		}
	}
}
#endif
