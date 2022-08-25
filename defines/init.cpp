namespace{
	int lang=unable;
}
void set_parameters(){
	system("title 我的地图");
	system(("mode "+to_string(COLS)+","+to_string(LINES+10)).c_str());
}
void set_lang(){
	::lang=unable;
	ask:cout << "Please Choose language.\n请设置语言。\n"
			"Press'e'to set the language to English, and press'c' to set the language to Chinese.\n"
			"按'e'键设置语言为英文，按'c'键设置语言为中文。\n";
	::lang=getch();
	if(lang=='c')	::lang=Chinese;
	else if(lang=='e')	::lang=English;
	else{
		cout << "Error:cannot set this language.\n"
				"错误：不能设置为此语言。\n";
				goto ask;
	}
	system("CLS");
}
void set_import(People &p,Map &h){
//	int ifimport=0;
	if(lang==Chinese){
		//language:Chinese
		//语言：中文 
//		cout << "请问您是否要导入存档？如果不导入，存档可能丢失。（本功能测试中）\n";
//		cout << "按'y'键导入存档。";
//		ifimport=getch();
//		if(ifimport=='y'){
//			p.imports(h);
//		}
		cout << "此功能暂时空缺。\n";
		getch();
		system("CLS");
	} else{
//		cout << "Do you want to import the archive? If you do not import, the archive may be lost.(in this function test)\n";
//		cout << "Press the 'y' key to import the archive.";
//		if(ifimport=='y'){
//			p.imports(h);
//		}
		cout << "This function is temporarily unavailable.\n";
		getch();
		system("CLS");
	}
	system("CLS");
}
void print_helper(){
	if(lang==Chinese){
		//language:Chinese
		//语言：中文 
		cout << "\n.:空地，可走动\n-:岩石，不可走动\n#:你自己\n"
				"WASD移动，按1键将在前进方向上清除一切，"
				"按2键将在前进方向上创建岩石。"
				"按3键将在前进方向上创建传送门。" 
				"按4键将在前进方向上创建球。\n"
				"更多功能拓展中。。。" << endl;
	} else if(lang==English){
		//language:English
		//语言：英文
		cout << "\n:open space, movable\n-:rock, not movable\n#:yourself\n"
				"WASD moves, pressing the 1 key will clear everything in the forward direction,"
				"Press 2 to create the rock in the forward direction." 
				"Pressing the 3 key will create a portal in the forward direction."
				"Pressing the 4 key creates a ball in the forward direction.\n"
				"More function expansion..." << endl;
	}
}
void create_door_helper(){
	if(lang==Chinese){
		//language:Chinese
		//语言：中文
		cout << "\nWASD键移动，空格键确认放置传送门。\n";
	} else if(lang==English){
		//language:English
		//语言：英文
		cout << "\nWASD key to move, and space key to confirm to place the transfer door.\n";
	} 
}
