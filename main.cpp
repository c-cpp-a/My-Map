//include STL
//�����׼��
#include<windows.h>
//include custom library
//�����Զ���� 
class Egg;
class People;
class Map; 
#include "defines\def"
#include "defines\init.h"
#include "defines\Map.h"
#include "defines\People.h"
#include "defines\Eggs.h" 
using namespace std;
int main(){
	Map G;
	People p;
	Egg egg; 
	init(p,G);
	while(1){
		p.put_xy(G);
		print_helper();
		p.set_f(G);
//		p.save(G);
		egg.check_run(get_lang(),p,G);
		Sleep(10);
	}
	return 0;
}


