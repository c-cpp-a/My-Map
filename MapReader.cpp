/*
 *	作者：c-cpp-a(Github) 
 *	最近更新：2023/5/21
 *	功能简述：这是整个游戏的主体部分，负责运行游戏。 
 */ 
/*
 *	Author: c-cpp-a(Github)
 *	Last updated: 2023/5/21
 *	Function description: This is the main part of the whole game, responsible for running the game.
 */
//include STL
//导入标准库
#include<windows.h>
#include<stdlib.h>
#include<direct.h>
#include<string>
//include custom library
//导入自定义库
#include "include_files.h"
using namespace std;
int main(int argc,char ** argv){
	//Instantiate Object
	//实例化对象 
	Map G;
	People p;
	Egg egg; 
	Screen screen(egg,G,p,false,argc,argv);
	//	init(p,G,egg,argc,argv);//调用初始化函数(Call initialization function)
	//游戏循环(Game cycle)
	//游戏的刷新速度约为100次/秒(Running speed of the game is about 100 ticks/second)
	while(true){
		//		save(p,G,egg);//保存游戏
		egg.check_run(screen.get_data().lang,p,G);//检测是否触发彩蛋(Check whether the egg is triggered)
		G.print(p.get_pos().x,p.get_pos().y,p.get_movef(),screen);//输出(print) 
		::screen_helper(screen.get_data().lang);//提供帮助(Help)
		if(egg.is_ach())	egg.print_ach();//如果触发了成就系统，就运行输出成就(If the achievement system is triggered, run the output achievement)
		Sleep(10);//游戏的刷新时间 
		char ch=getch();
		if(ch==27)	break;
		p.move(G,egg,screen,ch);//输入(input)
	}
	return 0;
}

