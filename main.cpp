//include STL
//导入标准库
#include<windows.h>
#include<string>
//include custom library
//导入自定义库
class Map;
class People;
class Egg;
#include "defines\def"
#include "defines\Eggs.h" 
#include "defines\Map.h"
#include "defines\People.h"
#include "defines\init.h"
#include "defines\Eggs.cpp"
#include "defines\Map.cpp"
#include "defines\People.cpp"
#include "defines\init.cpp"
using namespace std;
int main(){
	Map G;
	People p;
	Egg egg; 
	init(p,G);
	while(1){
//		p.save(G);
		p.put_xy(G);
		print_helper();
		if(egg.is_ach())	egg.print_ach();
		Sleep(10);
		p.set_f(G,egg);
		egg.check_run(get_lang(),p,G);
	}
	return 0;
}

