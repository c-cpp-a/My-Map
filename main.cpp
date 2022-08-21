//include STL
//导入标准库 
#include<iostream>
#include<windows.h>
//include custom library
//导入自定义库 
#include "defines/def"
#include "defines/Map.h"
#include "defines/init.h"
#include "defines/People.h"
using namespace std;
int main(){
	init();
	Map G;
	People p;
	while(1){
		p.put_xy(G);
		print_helper();
		p.set_f(G);
		Sleep(10);
	}
	return 0;
}


