//include STL
//�����׼�� 
#include<iostream>
#include<windows.h>
//include custom library
//�����Զ���� 
#include "defines\def"
#include "defines\init.h"
#include "defines\Map.h"
#include "defines\People.h"
using namespace std;
int main(){
	Map G;
	People p;
	init(p,G);
	while(1){
		p.put_xy(G);
		print_helper();
		p.set_f(G);
//		p.save(G);
		Sleep(10);
	}
	return 0;
}


