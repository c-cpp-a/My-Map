namespace{
	int lang=unable;
}
void set_parameters(){
	system("title �ҵĵ�ͼ");
	system(("mode "+to_string(COLS)+","+to_string(LINES+10)).c_str());
}
void set_lang(){
	::lang=unable;
	ask:cout << "Please Choose language.\n���������ԡ�\n"
			"Press'e'to set the language to English, and press'c' to set the language to Chinese.\n"
			"��'e'����������ΪӢ�ģ���'c'����������Ϊ���ġ�\n";
	::lang=getch();
	if(lang=='c')	::lang=Chinese;
	else if(lang=='e')	::lang=English;
	else{
		cout << "Error:cannot set this language.\n"
				"���󣺲�������Ϊ�����ԡ�\n";
				goto ask;
	}
	system("CLS");
}
void print_helper(){
	if(lang==Chinese){
		//language:Chinese
		//���ԣ����� 
		cout << "\n.:�յأ����߶�\n-:��ʯ�������߶�\n#:���Լ�\n"
				"WASD�ƶ�����1������ǰ�������������ʯ�ʹ����ţ���2������ǰ�������ϴ�����ʯ����3������ǰ�������ϴ��������ţ������У���\n"
				"���๦����չ�С�����" << endl;
	} else if(lang==English){
		//language:English
		//���ԣ�Ӣ��
		cout << "\n:open space, movable\n-:rock, not movable\n#:yourself\n"
				"WASD moves, press 1 to clear the rock and the portal in the forward direction, and press 2 to create the rock in the forward direction. Pressing the 3 key will create a portal in the forward direction (under test).\n"
				"More function expansion..." << endl;
	}
}
void create_door_helper(){
	if(lang==Chinese){
		//language:Chinese
		//���ԣ�����
		cout << "\nWASD���ƶ����ո��ȷ�Ϸ��ô����š�\n";
	} else if(lang==English){
		//language:English
		//���ԣ�Ӣ��
		cout << "\nWASD key to move, and space key to confirm to place the transfer door.\n";
	} 
}
