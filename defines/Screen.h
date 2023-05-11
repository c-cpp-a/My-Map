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
	HANDLE hins;
	void title(const std::string &s){
		
	}
public:
	Screen(Egg &_egg,Map &_m,People &_p):egg(_egg),map(_m),people(_p){
		hins=GetStdHandle(STD_OUTPUT_HANDLE);
		
	}
};
#endif
