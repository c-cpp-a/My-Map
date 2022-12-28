/*
 *	作者：c_cpp_a(Github) 
 *	最近更新：2022/12/28
 *	功能简述：这是整个游戏的主体部分，负责运行游戏。 
 */ 
/*
 *	Author: c_ cpp_ a(Github)
 *	Last updated: 2022/12/26
 *	Function description: This is the main part of the whole game, responsible for running the game.
 */
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
#include "defines\help_func.h"
#include "defines\Eggs.h" 
#include "defines\Map.h"
#include "defines\People.h"
#include "defines\help_func.cpp"
#include "defines\init.h"
#include "defines\Eggs.cpp"
#include "defines\Map.cpp"
#include "defines\People.cpp"
#include "defines\init.cpp"
using namespace std;
int main(){
	//Instantiate Object
	//实例化对象 
	Map G;
	People p;
	Egg egg; 
	init(p,G,egg);//调用初始化函数(Call initialization function)
	//游戏循环(Game cycle)
	//游戏的刷新速度=100次/秒(Running speed of the game=100ticks/second)
	while(true){
		save(p,G,egg);//保存游戏
		p.put_xy(G);//输出(print) 
		screen_helper();//提供帮助(Help)
		if(egg.is_ach())	egg.print_ach();//如果触发了成就系统，就运行输出成就(If the achievement system is triggered, run the output achievement)
		Sleep(10);//游戏的刷新时间 
		p.set_f(G,egg);//输入(input)
		egg.check_run(::lang,p,G);//检测是否触发彩蛋(Check whether the egg is triggered)
	}
	return 0;
}

