//include STL
//导入标准库 
#include<iostream>
#include<windows.h>
#include<conio.h>
//include custom library
//导入自定义库 
#include "defines/def"
#include "defines/Map.h"
#include "defines/People.h"
using namespace std;
int main(){
	system("title 我的地图");
	system(("mode "+to_string(COLS)+","+to_string(LINES+10)).c_str());
	ask:cout << "Please Choose language.\n请设置语言。\n"
			"Press'e'to set the language to English, and press'c' to set the language to Chinese.\n"
			"按'e'键设置语言为英文，按'c'键设置语言为中文。\n";
	int lang=getch();
	if(lang=='c')	lang=Chinese;
	else if(lang=='e')	lang=English;
	else{
		cout << "Error:cannot set this language.\n"
				"错误：不能设置为此语言。\n";
				goto ask;
	}
	system("CLS");
	Map G;
	People p;
	while(1){
		p.put_xy(G);
		if(lang==Chinese){
			//language:Chinese
			//语言：中文 
			cout << "\n.:空地，可走动\n-:岩石，不可走动\n#:你自己\n"
					"WASD移动，按1键将在前进方向上清除岩石，按2键将在前进方向上创建岩石。\n"
					"更多功能拓展中。。。" << endl;
		} else if(lang==English){
			//language:English
			//语言：英文
			cout <<  "\n:open space, movable\n-:rock, not movable\n#:yourself\n"
					"WASD moves, press 1 to clear the rock in the forward direction, and press 2 to create the rock in the forward direction.\n"
					"More function expansion..." << endl;
		}
		p.set_f(G);
		Sleep(10);
	}
	
	return 0;
}


