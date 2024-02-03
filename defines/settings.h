#ifndef SETTINGS_H_H
#define SETTINGS_H_H
#include<string>
#include<vector>
#include<iostream>
#include<initializer_list>
#include<conio.h>
#include "def"
class Settings{
public:
	struct setting{
		struct option{
			//选项
			std::string opt_name[LANGUAGE_COUNT];//选项名字
			option(std::initializer_list<std::string> init_list){
				int j=0;
				for(std::initializer_list<std::string>::const_iterator it=init_list.begin();it!=init_list.end() && j<LANGUAGE_COUNT;it++){
					opt_name[j++]=*it;
				}
			}
		};
		int * thingset;//被更改的数
		int nowchoose;//当前选项
		std::string settingname[LANGUAGE_COUNT];//设置项名字
		std::vector<option> opts;//选项
		setting(std::initializer_list<std::string> init_name,int * _thing,const std::vector<option> &_opt):thingset(_thing),nowchoose(0),opts(_opt){
			int j=0;
			for(std::initializer_list<std::string>::const_iterator it=init_name.begin();it!=init_name.end() && j<LANGUAGE_COUNT;it++){
				settingname[j++]=*it;
			}
		}
		void onshow(int _Lang) const{
			std::cout << settingname[_Lang] << ":< " << opts[nowchoose].opt_name[_Lang] << " >";
			*thingset=nowchoose;
		}
		void left(){
			--nowchoose;
			if(nowchoose<0)	nowchoose+=opts.size();
			*thingset=nowchoose;
		}
		void right(){
			++nowchoose;
			if(nowchoose>=opts.size())	nowchoose-=opts.size();
			*thingset=nowchoose;
		}
	};
private:
	std::vector<setting> settings;
	int nowchoose;//正在选择的选项
public:
	Settings(const std::vector<setting> &_set={}):settings(_set),nowchoose(0){}
	void screenprint(int _Lang) const{
		for(int i=0,siz=settings.size();i<siz;i++){
			if(i==nowchoose){
				std::cout << "> ";
			}
			settings[i].onshow(_Lang);
			std::cout << '\n';
		}
		if(_Lang==Chinese){
			//language:Chinese
			//语言：中文
			std::cout << "\n按左右键选择，按q键退出。";
		} else if(_Lang==English){
			//language:English
			//语言：英文
			std::cout << "\nPress the left and right keys to select, and press the q key to exit.";
		}
	}
	void show(int _Lang){
		while(true){
			system("cls");
			screenprint(_Lang);
			int op=toupper(getch());
			switch(op){
			case 'Q':
				//quit
				//退出
				return;
			case DIRECT_ASCII:
				op=toupper(getch());
				switch(op){
				case DIRECT_LEFT_ASCII:
					settings[nowchoose].left();
					break;
				case DIRECT_RIGHT_ASCII:
					settings[nowchoose].right();
					break;
				case DIRECT_UP_ASCII:
					if(nowchoose>0){
						--nowchoose;
					}
					break;
				case DIRECT_DOWN_ASCII:
					if(nowchoose<settings.size()-1){
						++nowchoose;
					}
					break;
				}
			}
		}
		
	}
};
#endif
