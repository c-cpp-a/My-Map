/*
 *	���ߣ�c_cpp_a(Github) 
 *	������£�2022/12/28
 *	���ܼ���������������Ϸ�����岿�֣�����������Ϸ�� 
 */ 
/*
 *	Author: c_ cpp_ a(Github)
 *	Last updated: 2022/12/26
 *	Function description: This is the main part of the whole game, responsible for running the game.
 */
//include STL
//�����׼��
#include<windows.h>
#include<string>
//include custom library
//�����Զ����
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
	//ʵ�������� 
	Map G;
	People p;
	Egg egg; 
	init(p,G,egg);//���ó�ʼ������(Call initialization function)
	//��Ϸѭ��(Game cycle)
	//��Ϸ��ˢ���ٶ�=100��/��(Running speed of the game=100ticks/second)
	while(true){
		save(p,G,egg);//������Ϸ
		p.put_xy(G);//���(print) 
		screen_helper();//�ṩ����(Help)
		if(egg.is_ach())	egg.print_ach();//��������˳ɾ�ϵͳ������������ɾ�(If the achievement system is triggered, run the output achievement)
		Sleep(10);//��Ϸ��ˢ��ʱ�� 
		p.set_f(G,egg);//����(input)
		egg.check_run(::lang,p,G);//����Ƿ񴥷��ʵ�(Check whether the egg is triggered)
	}
	return 0;
}

