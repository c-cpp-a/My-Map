#ifndef EGGS_H_
#define EGGS_H_
//include STL
//导入标准库 
#include<string>
#include<iostream>
#include<fstream>
//include custom library
//导入自定义库
using namespace std;
class People;
class Map;
class Egg{
	private:
		bool has_ach;
		unsigned int achs;
	public:
		Egg():has_ach(false),achs(0){}
		int isegg(const int &,People &,Map &);
		void check_run(const int &,People &,Map &);
		void print_ach(); 
		void imports(ifstream &);
		void save(ofstream &);
		inline bool is_ach(){
			return has_ach;
		}
		inline bool operator[](size_t i){
			return achs&(1<<i);
		}
		void set_ach(size_t i,bool value);
};
#include "def"
#include "Map.h"
#include "People.h"
#include "help_func.h"
int Egg::isegg(const int &lang,People &p,Map &h){
	if(lang==English && 
		h[EGG_POS[English][0][0]][EGG_POS[English][0][1]]==rock){
		has_ach=true;
		system(("mode "+to_string(COLS+ADD_COLS)+","+to_string(LINES+ADD_LINE)).c_str());
	} else if(lang==Chinese && 
		p.at(EGG_POS[Chinese][0][0],EGG_POS[Chinese][0][1])==
		People::node(EGG_POS[Chinese][0][0],EGG_POS[Chinese][0][1])
		&& p.get_pos().x==EGG_POS[Chinese][0][0] && p.get_pos().y==EGG_POS[Chinese][0][1])	return CHI_egg_1;
	else if(lang==unable && 
		p.get_pos().x==EGG_POS[unable][0][0] && p.get_pos().y==EGG_POS[unable][0][1]
		&& h[EGG_POS[unable][0][0]][EGG_POS[unable][0][1]]==ball
		&& p.move_f==rights)	return UNABLE_egg_1;
	return empty_egg;
}
void Egg::check_run(const int &lang,People &p,Map &h){
	system("CLS");
	int get_egg=isegg(lang,p,h);
	switch(get_egg){
	case CHI_egg_1:
{
	set_ach(6,1);
	::print("恭喜您，发现了彩蛋！\n");
	::print(">>>");
	string s;
	while(getline(cin,s) && s!="quit"){
		if(s=="creater"){
			::print("c_cpp_a,Github网址:www.github.com/c-cpp-a/My-Map\n");
		} else if(s=="lgker"){
			::print("哈哈，恭喜您发现了隐藏的彩蛋！\n洛谷账号：66xyyd，洛谷UID：946515。\n");
		} else if(s=="Snake"){
			::print("加载贪吃蛇游戏中……\n");
			Sleep(1000);//空留着以后再补 
			::print("加载失败！\n");
		} else{
			::print("对不起，您输入的不是任何指令。\n");
		}
		::print(">>>");
	}
	::print("已退出！");
}
		break;
	case UNABLE_egg_1:
{
	set_ach(7,1);
	::print("恭喜您，发现了彩蛋！\n");
	::print("Congratulations, you found the egg!\n");
	::print("<<<");
	string s;
	while(getline(cin,s) && s!="quit"){
		if(s=="D o D o oooo"){
			::print(s);
			::print("\n挺不错嘛，这个彩蛋可难找到了！\n");
			::print("Very good. It's hard to find this egg!\n");
			::print("彩蛋提示：中文、10、传送门。\n");
			::print("Egg tips: Chinese, 10. Transmission gate.\n");
		} else{
			::print(s);
			::print("\n");
		} 
		::print("<<<");
	}
}
	}
}
void Egg::print_ach(){
	auto y=0;
	y=ach_print("achievement",y);
	for(int i=0;i<10;i++){
		if((*this)[i])	y=ach_print(achs_print[i],y);
	}
}
void Egg::imports(ifstream &fin){
	fin >> has_ach;
	fin >> achs;
	if(has_ach){
		system(("mode "+to_string(COLS+ADD_COLS)+","+to_string(LINES+ADD_LINE)).c_str());
	}
}
void Egg::save(ofstream &fout){
	fout << has_ach << endl;
	fout << achs;
	fout << endl;
}
void Egg::set_ach(size_t i,bool value){
	achs|=(1<<i);
}
#endif
