#ifndef INIT_H_
#define INIT_H_
//include STL
//导入标准库 
#include<string>
#include<cstdlib>
#include<conio.h>
#include<iostream>
#include<windows.h>
using namespace std;
class People;
class Map;
class Egg;
#include "def"
void create_door_helper();
void set_parameters();
void set_lang();
void import(People &p,Map &h,Egg &egg,char * name=SAVE_NAME);
bool set_import(People &,Map &,Egg &egg);
void screen_helper();
void print_helper();
void init(People &p,Map &h,Egg &egg,int argc,char ** argv);
void settings();
void save(People &,Map &,Egg &,const char * name=SAVE_NAME);
#include "help_func.h"
#include "People.h"
#include "Map.h"
#include "Eggs.h"
void set_parameters(const bool &canedit){
	using namespace std;
	::ShowCursor(false);
	if(canedit)	system("title 我的地图(My-Map)");
	else system("title MapReader[read only]");
	system(("mode "+to_string(COLS)+","+to_string(LINES+ADD_LINE)).c_str());
}
void set_lang(){
	system("CLS");
	::lang=unable;
	ask:cout << "Please Choose language.\n请设置语言。\n"
	"English[E]\tChinese[C]\n"
	"英文[E]\t中文[C]\n";
	::lang=getch();
	if(lang=='c' || lang=='C')	::lang=Chinese;
	else if(lang=='e' || lang=='E')	::lang=English;
	else if(lang==224)	::lang=unable;//egg
	else{
		cout << "Error:cannot set this language.\n"
		"错误：不能设置为此语言。\n";
		goto ask;
	}
}
void import(People &p,Map &h,Egg &egg,char * name){
	ifstream fin(name);
	h.imports(fin);
	p.imports(fin);
	egg.imports(fin);
	fin >> ::mode >> ::lang;
	SAVE_NAME=name;
	fin.close();
}
bool set_import(People &p,Map &h,Egg &egg){
	bool ifimport=false;
	if(lang==Chinese){
		//language:Chinese
		//语言：中文 
		cout << "请问您是否要导入存档？如果不导入，存档可能丢失。（本功能测试中）\n";
		cout << "按'y'键导入存档。";
		char ch=getch();
		if(ch=='y'){
			ifimport=true;
			
		}
		cout << "加载中。。。";
		//		cout << "此功能暂时空缺。按任意键继续…\n";
		//		getch();
	} else{
		cout << "Do you want to import the archive? If you do not import, the archive may be lost.(in this function test)\n";
		cout << "Press the 'y' key to import the archive.";
		char ch=getch();
		if(ch=='y'){
			ifimport=true;
		}
		cout << "loading...";
		//		cout << "This function is temporarily unavailable. Press any key to continue...\n";
		//		getch();
	}
	if(ifimport)	import(p,h,egg);
	system("CLS");
	return ifimport;
}
void screen_helper(){
	using namespace std;
	if(lang==Chinese){
		//language:Chinese
		//语言：中文 
		cout << "\n帮助[H]\t设置[T]\n";
	} else if(lang==English){
		//language:English
		//语言：英文
		cout << "\nHelp[H]\nTools[T]\n";
	}
} 
void print_helper(){
	using namespace std;
	if(::lang==Chinese){
		//language:Chinese
		//语言：中文 
		cout << "\n :空地，可走动\t-:岩石，不可走动\t@:传送门\to:小球\t#:你自己\n"
		"WASD移动。\n"
		"清除物品[1]\t"
		"创建岩石[2]\t"
		"创建传送门[3]\t" 
		"创建小球[4]\n"
		"选择语言[L]\t"
		"关闭帮助[H]\n"
		"更多功能拓展中。。。\n";
	} else if(::lang==English){
		//language:English
		//语言：英文
		cout << "\n :open space, movable\t-: rock, not movable\t@: portal\to: ball\t#: yourself\n"
		"WASD moves.\n"
		"clear everything in the forward direction[1]\t"
		"create a rock in the forward direction[2]\t" 
		"create a portal in the forward direction[3]\t"
		"create a ball in the forward direction[4]\n"
		"select the language[L]\t"
		"close the help content[H]\n"
		"More function expansion...\n";
	}
	char a;
	do{
		a=getch();
		if(a=='l' || a=='L')	set_lang(); 
	}while(a!='H' && a!='h');
}
void create_door_helper(){
	if(::lang==Chinese){
		//language:Chinese
		//语言：中文
		cout << "\nWASD键移动，空格键确认放置传送门。\n";
	} else if(::lang==English){
		//language:English
		//语言：英文
		cout << "\nWASD key to move, and space key to confirm to place the transfer door.\n";
	} 
}
void init(People &p,Map &h,Egg &egg,int argc,char ** argv){
	set_parameters(p.edit());
	if(argc==1){
		set_lang();
		set_import(p,h,egg);
		system("CLS");
	} else{
		import(p,h,egg,argv[1]);
	}
}
void settings(){
	int choose;
	do{
		system("CLS");
		if(lang==Chinese){
			//language:Chinese
			//语言：中文
			cout << "模式：";
		} else if(lang==English){
			//language:English
			//语言：英文
			cout << "pattern:";
		}
		cout << mode_content[lang][::mode];
		if(lang==Chinese){
			//language:Chinese
			//语言：中文
			cout << "\n按左右键选择，按q键退出。";
		} else if(lang==English){
			//language:English
			//语言：英文
			cout << "\nPress the left and right keys to select, and press the q key to exit.";
		}
		choose=getch();
		if(choose==224){
			choose=getch();
		}
		switch(choose){
			case 77://右键
			::mode=(::mode+1)%MODE_COUNT; 
			break;
			case 75://左键 
			::mode=(::mode-1+MODE_COUNT)%MODE_COUNT;
			break;
		}
	} while(choose!='q' && choose!='Q');
}
void save(People &p,Map &h,Egg &egg,const char * name){
	ofstream fout(name);
	h.save(fout);
	p.save(fout);
	egg.save(fout);
	fout << ::mode << ' ' << ::lang << endl;
	fout.close();
}
#endif
