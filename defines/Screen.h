#ifndef SCREEN_H_H
#define SCREEN_H_H
#include<windows.h>
#include<string>
#include<conio.h>
#include<iostream>
#include<fstream>
#include<direct.h>
#include "def"
#include "settings.h"
class Egg;
class Map;
class People;
class Screen{
private:
	Egg &egg;
	Map &map;
	People &people;
	Settings sett;
	HANDLE handle;
	std::string gametitle;
public:
	struct Data{
		int lang,mode;
		char * savefile_name;
	};
private:
	Data data;
public:
	inline void title(const std::string &s){
		system(("title "+s).c_str());
	}
	inline void set_length_width(const int &length,const int &width){
		system(("mode "+std::to_string(length)+","+std::to_string(width)).c_str());
	}
	inline void clear(){
		system("CLS");
	}
	inline const std::string defaut_title(bool isedit) const{
		return std::string((isedit?"[My-Map]":"[MapReader]"));
	}
	void init_lang(int &lang);
	void import();
	Screen(Egg &_egg,Map &_m,People &_p,bool isedit,int argc,char ** argv);
	~Screen();
	Data &get_data(){return data;}
	void setting();
	void alert(const std::string &title,const std::string &content);
	void save();
};
#include "Map.h"
#include "People.h"
#include "Eggs.h"
void Screen::init_lang(int &lang){
	clear();
	lang=unable;
	ask:std::cout << "Please Choose language.\n请设置语言。\n"
	"English[E]\tChinese[C]\n"
	"英文[E]\t中文[C]\n";
	lang=getch();
	if(lang=='c' || lang=='C')	lang=Chinese;
	else if(lang=='e' || lang=='E')	lang=English;
	else if(lang==224)	lang=unable;//egg
	else{
		std::cout << "Error:cannot set this language.\n"
		"错误：不能设置为此语言。\n";
		goto ask;
	}
}
void Screen::import(){
	std::ifstream fin(data.savefile_name);
	map.imports(fin);
	people.imports(fin);
	egg.imports(fin);
	fin >> data.mode >> data.lang;
	fin.close();
}
Screen::Screen(Egg &_egg,Map &_m,People &_p,bool isedit,int argc,char ** argv):egg(_egg),map(_m),people(_p),gametitle(defaut_title(isedit)){
	handle=GetStdHandle(STD_OUTPUT_HANDLE);
	sett=Settings(std::vector<Settings::setting>({
		Settings::setting({"","模式","mode"},&data.mode,vector<Settings::setting::option>({
			Settings::setting::option({"","正常的模式","normal"}),
			Settings::setting::option({"","开发者模式","debugger"}),
			Settings::setting::option({"","地狱的模式","infernal"}),
			Settings::setting::option({"","清一色模式","all in one color"})
		}))
	}));
	Argument arg(argc,argv);
	if(arg.find("title").size()){
		gametitle+=arg.find("title");
	}
	title(gametitle);
	set_length_width(COLS,LINES+ADD_LINE);
	string background_music_name=arg.filename();
	if(arg.find("music")!="off"){
		while(background_music_name.back()!='\\'){
			background_music_name.pop_back();
		}
		background_music_name+="defines\\sound\\1st.mp3";
		//	alert("提示","background_music_name="+background_music_name);
		system(("cd \""+std::string(_getcwd(NULL,0))+"\"").c_str());
		system(("start "+background_music_name).c_str());
	}
	if(arg.other_argument().empty() && arg.find("save").empty()){
		data.savefile_name=SAVE_NAME;
		init_lang(data.lang);
		clear();
		if(data.lang==Chinese){
			cout << "请问您是否要导入存档？如果不导入，存档可能丢失。（本功能测试中）\n";
			cout << "按'y'键导入存档。";
			char ch=getch();
			if(ch=='y' || ch=='Y'){
				cout << "加载中……";
				import();
			}
		} else if(data.lang==English){
			cout << "Do you want to import the archive? If you do not import, the archive may be lost.(in this function test)\n";
			cout << "Press the 'y' key to import the archive.";
			char ch=getch();
			if(ch=='y' || ch=='Y'){
				cout << "loading...";
				import();
			}
		}
		
	} else{
		if(arg.other_argument().size())	data.savefile_name=const_cast<char *>(arg.other_argument()[0].c_str());
		if(arg.find("save").size())	data.savefile_name=const_cast<char *>(arg.find("save").c_str());
		import();
	}
	
	clear();
}
Screen::~Screen(){
	save();
}
void Screen::setting(){
//	int choose;
//	do{
//		clear();
//		if(data.lang==Chinese){
//			//language:Chinese
//			//语言：中文
//			std::cout << "模式：";
//		} else if(data.lang==English){
//			//language:English
//			//语言：英文
//			std::cout << "pattern:";
//		}
//		std::cout << mode_content[data.lang][data.mode];
//		if(data.lang==Chinese){
//			//language:Chinese
//			//语言：中文
//			std::cout << "\n按左右键选择，按q键退出。";
//		} else if(data.lang==English){
//			//language:English
//			//语言：英文
//			std::cout << "\nPress the left and right keys to select, and press the q key to exit.";
//		}
//		choose=getch();
//		if(choose==224){
//			choose=getch();
//		}
//		switch(choose){
//			case 77://右键
//			data.mode=(data.mode+1)%MODE_COUNT; 
//			break;
//			case 75://左键 
//			data.mode=(data.mode-1+MODE_COUNT)%MODE_COUNT;
//			break;
//		}
//	} while(choose!='q' && choose!='Q');
	sett.show(data.lang);
}
void Screen::alert(const std::string &title,const std::string &content){
	MessageBox(NULL,content.c_str(),title.c_str(),MB_OK);
}
void Screen::save(){
	std::ofstream fout(data.savefile_name);
	map.save(fout);
	people.save(fout);
	egg.save(fout);
	fout << data.mode << ' ' << data.lang << endl;
	fout.close();
}
#endif
