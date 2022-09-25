namespace{
	void print(const string s){
		for(auto len=s.length(),i=0ULL;i<len;i++){
			putchar(s[i]);
			Sleep(30);
		}
	}
	
}
int Egg::isegg(const int &lang,People &p,Map &h){
	if(lang==Chinese && 
		p.at(EGG_POS[Chinese][0][0],EGG_POS[Chinese][0][1])==
		People::node(EGG_POS[Chinese][0][0],EGG_POS[Chinese][0][1])
	   	&& p.pos.x==EGG_POS[Chinese][0][0] && p.pos.y==EGG_POS[Chinese][0][1])	return CHI_egg_1;
	else if(lang==unable && 
			p.pos.x==EGG_POS[unable][0][0] && p.pos.y==EGG_POS[unable][0][1]
		&& h[EGG_POS[unable][0][0]][EGG_POS[unable][0][1]]==ball
		&& p.move_f==rights)	return UNABLE_egg_1;
	else	return empty_egg;
}
void Egg::check_run(const int &lang,People &p,Map &h){
	system("CLS");
	switch(isegg(lang,p,h)){
		case CHI_egg_1:
			{
			::print("恭喜您，发现了彩蛋！\n");
			::print(">>>");
			string s;
			while(getline(cin,s) && s!="quit"){
				if(s=="creater"){
					::print("c_cpp_a,Github网址:www.github.com/c-cpp-a/My-Map\n");
				} else if(s=="lgker"){
					::print("哈哈，恭喜您发现了隐藏的彩蛋！\n洛谷账号：c_cpp_a，洛谷UID：346332。\n");
				} else if(s=="Snake"){
					::print("加载贪吃蛇游戏中……\n");
					Sleep(1000);//空留着以后再补 
					::print("加载失败！\n");
				} else{
					::print("对不起，您输入的不是任何指令。\n");
				}
				::print(">>>");
			}
			::print("已退出！");
			}
			break;
		case UNABLE_egg_1:
			{
			::print("恭喜您，发现了彩蛋！\n");
			::print("Congratulations, you found the egg!\n");
			::print("<<<");
			string s;
			while(getline(cin,s) && s!="quit"){
				if(s=="D o D o oooo"){
					::print(s);
					::print("\n挺不错嘛，这个彩蛋可难找到了！\n");
					::print("Very good. It's hard to find this egg!\n");
					::print("彩蛋提示：中文、10、传送门。\n");
					::print("Egg tips: Chinese, 10. Transmission gate.\n");
				} else{
					::print(s);
					::print("\n");
				} 
				::print("<<<");
			}
			}
	}
}


