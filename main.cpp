//include STL
//�����׼�� 
#include<iostream>
#include<windows.h>
#include<conio.h>
//include custom library
//�����Զ���� 
#include "defines/def"
#include "defines/Map.h"
#include "defines/People.h"
using namespace std;
int main(){
	system("title �ҵĵ�ͼ");
	system(("mode "+to_string(COLS)+","+to_string(LINES+10)).c_str());
	ask:cout << "Please Choose language.\n���������ԡ�\n"
			"Press'e'to set the language to English, and press'c' to set the language to Chinese.\n"
			"��'e'����������ΪӢ�ģ���'c'����������Ϊ���ġ�\n";
	int lang=getch();
	if(lang=='c')	lang=Chinese;
	else if(lang=='e')	lang=English;
	else{
		cout << "Error:cannot set this language.\n"
				"���󣺲�������Ϊ�����ԡ�\n";
				goto ask;
	}
	system("CLS");
	Map G;
	People p;
	while(1){
		p.put_xy(G);
		if(lang==Chinese){
			//language:Chinese
			//���ԣ����� 
			cout << "\n.:�յأ����߶�\n-:��ʯ�������߶�\n#:���Լ�\n"
					"WASD�ƶ�����1������ǰ�������������ʯ����2������ǰ�������ϴ�����ʯ��\n"
					"���๦����չ�С�����" << endl;
		} else if(lang==English){
			//language:English
			//���ԣ�Ӣ��
			cout <<  "\n:open space, movable\n-:rock, not movable\n#:yourself\n"
					"WASD moves, press 1 to clear the rock in the forward direction, and press 2 to create the rock in the forward direction.\n"
					"More function expansion..." << endl;
		}
		p.set_f(G);
		Sleep(10);
	}
	
	return 0;
}


