#ifndef SCREEN_H_H
#define SCREEN_H_H
#include<windows.h>
#include<string>
class Egg;
class Map;
class People;
class Screen{
private:
	Egg &egg;
	Map &map;
	People &people;
	HANDLE handle;
	void title(const std::string &s){
		system(("title "+s).c_str());
	}
public:
	Screen(Egg &_egg,Map &_m,People &_p,bool isedit):egg(_egg),map(_m),people(_p){
		handle=GetStdHandle(STD_OUTPUT_HANDLE);
		title("我的地图(My-Map)");
	}
};
#endif
