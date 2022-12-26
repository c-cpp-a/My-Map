void set_parameters(){
	system("title �ҵĵ�ͼ");
	system(("mode "+to_string(COLS)+","+to_string(LINES+ADD_LINE)).c_str());
}
void set_lang(){
	system("CLS");
	::lang=unable;
	ask:cout << "Please Choose language.\n���������ԡ�\n"
			"Press'e'to set the language to English, and press'c' to set the language to Chinese.\n"
			"��'e'����������ΪӢ�ģ���'c'����������Ϊ���ġ�\n";
	::lang=getch();
	if(lang=='c')	::lang=Chinese;
	else if(lang=='e')	::lang=English;
	else if(lang==224)	::lang=unable;
	else{
		cout << "Error:cannot set this language.\n"
				"���󣺲�������Ϊ�����ԡ�\n";
				goto ask;
	}
}
void set_import(People &p,Map &h,Egg &egg){
	int ifimport=0;
	if(lang==Chinese){
		//language:Chinese
		//���ԣ����� 
		cout << "�������Ƿ�Ҫ����浵����������룬�浵���ܶ�ʧ���������ܲ����У�\n";
		cout << "��'y'������浵��";
		ifimport=getch();
		if(ifimport=='y'){
			ifstream fin(SAVE_NAME);
			h.imports(fin);
			p.imports(fin);
			egg.imports(fin);
			fin.close();
		}
//		cout << "�˹�����ʱ��ȱ���������������\n";
//		getch();
		system("CLS");
	} else{
		cout << "Do you want to import the archive? If you do not import, the archive may be lost.(in this function test)\n";
		cout << "Press the 'y' key to import the archive.";
		if(ifimport=='y'){
			ifstream fin(SAVE_NAME);
			h.imports(fin);
			p.imports(fin);
			egg.imports(fin);
			fin.close();
		}
//		cout << "This function is temporarily unavailable. Press any key to continue...\n";
//		getch();
		system("CLS");
	}
	system("CLS");
}
void screen_helper(){
	using namespace std;
	if(lang==Chinese){
		//language:Chinese
		//���ԣ����� 
		cout << "\n��H������������\n��T���������á�" << endl;
	} else if(lang==English){
		//language:English
		//���ԣ�Ӣ��
		cout << "\nPress the H key to pop up the help.\nPress the T key to pop up the settings." << endl;
	}
} 
void print_helper(){
	using namespace std;
	if(lang==Chinese){
		//language:Chinese
		//���ԣ����� 
		cout << "\n :�յأ����߶�\t-:��ʯ�������߶�\t@:������\to:С��\t#:���Լ�\n"
				"WASD�ƶ�����1������ǰ�����������һ�У�"
				"��2������ǰ�������ϴ�����ʯ��"
				"��3������ǰ�������ϴ��������š�" 
				"��4������ǰ�������ϴ�����\n"
				"��l��ѡ�����ԡ�\n"
				"���๦����չ�С��������밴H���رհ�����" << endl;
	} else if(lang==English){
		//language:English
		//���ԣ�Ӣ��
		cout << "\n :open space, movable\t-: rock, not movable\t@: portal\to: ball\t#: yourself\n"
				"WASD moves, pressing the 1 key will clear everything in the forward direction,"
				"Press 2 to create the rock in the forward direction." 
				"Pressing the 3 key will create a portal in the forward direction."
				"Pressing the 4 key creates a ball in the forward direction.\n"
				"Press l to select the language.\n"
				"More function expansion...(Press H to close the help)" << endl;
	}
	char a;
	do{
		a=getch();
		if(a=='l' || a=='L')	set_lang(); 
	}while(a!='H' && a!='h');
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
void settings(){
	int choose;
	do{
		system("CLS");
		if(lang==Chinese){
			//language:Chinese
			//���ԣ�����
			cout << "ģʽ��";
		} else if(lang==English){
			//language:English
			//���ԣ�Ӣ��
			cout << "pattern:";
		}
		cout << mode_content[lang][::mode];
		if(lang==Chinese){
			//language:Chinese
			//���ԣ�����
			cout << "\n�����Ҽ�ѡ�񣬰�q���˳���";
		} else if(lang==English){
			//language:English
			//���ԣ�Ӣ��
			cout << "\nPress the left and right keys to select, and press the q key to exit.";
		}
		choose=getch();
		if(choose==224){
			choose=getch();
		}
		switch(choose){
			case 77://�Ҽ�
				::mode=(::mode+1)%MODE_COUNT; 
				break;
			case 75://��� 
				::mode=(::mode-1+MODE_COUNT)%MODE_COUNT;
				break;
		}
	} while(choose!='q' && choose!='Q');
}
void save(People &p,Map &h,Egg &egg){
	ofstream fout(SAVE_NAME);
	h.save(fout);
	p.save(fout);
	egg.save(fout);
	fout.close();
}
