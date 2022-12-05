int Egg::isegg(const int &lang,People &p,Map &h){
	if(lang==English && 
		h[EGG_POS[English][0][0]][EGG_POS[English][0][1]]==rock){
		has_ach=true;
		system(("mode "+to_string(COLS+ADD_COLS)+","+to_string(LINES+ADD_LINE)).c_str());
	} else if(lang==Chinese && 
		p.at(EGG_POS[Chinese][0][0],EGG_POS[Chinese][0][1])==
		People::node(EGG_POS[Chinese][0][0],EGG_POS[Chinese][0][1])
	   	&& p.get_pos().x==EGG_POS[Chinese][0][0] && p.get_pos().y==EGG_POS[Chinese][0][1])	return CHI_egg_1;
	else if(lang==unable && 
			p.get_pos().x==EGG_POS[unable][0][0] && p.get_pos().y==EGG_POS[unable][0][1]
		&& h[EGG_POS[unable][0][0]][EGG_POS[unable][0][1]]==ball
		&& p.move_f==rights)	return UNABLE_egg_1;
	return empty_egg;
}
void Egg::check_run(const int &lang,People &p,Map &h){
	system("CLS");
	switch(isegg(lang,p,h)){
		case CHI_egg_1:
			{
			achs[6]=true;
			::print("��ϲ���������˲ʵ���\n");
			::print(">>>");
			string s;
			while(getline(cin,s) && s!="quit"){
				if(s=="creater"){
					::print("c_cpp_a,Github��ַ:www.github.com/c-cpp-a/My-Map\n");
				} else if(s=="lgker"){
					::print("��������ϲ�����������صĲʵ���\n����˺ţ�c_cpp_a�����UID��346332��\n");
				} else if(s=="Snake"){
					::print("����̰������Ϸ�С���\n");
					Sleep(1000);//�������Ժ��ٲ� 
					::print("����ʧ�ܣ�\n");
				} else{
					::print("�Բ���������Ĳ����κ�ָ�\n");
				}
				::print(">>>");
			}
			::print("���˳���");
			}
			break;
		case UNABLE_egg_1:
			{
			achs[7]=true;
			::print("��ϲ���������˲ʵ���\n");
			::print("Congratulations, you found the egg!\n");
			::print("<<<");
			string s;
			while(getline(cin,s) && s!="quit"){
				if(s=="D o D o oooo"){
					::print(s);
					::print("\nͦ���������ʵ������ҵ��ˣ�\n");
					::print("Very good. It's hard to find this egg!\n");
					::print("�ʵ���ʾ�����ġ�10�������š�\n");
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
void Egg::print_ach(){
	auto y=0;
	y=ach_print("achievement",y);
	if(achs[0]){
		y=ach_print("1.creat your first floor.",y);
	} 
	if(achs[1]){
		y=ach_print("2.creat your first rock.",y);
	}
	if(achs[2]){
		y=ach_print("3.creat your first portal.",y);
	}
	if(achs[3]){
		y=ach_print("4.creat your first ball.",y);
	}
	if(achs[4]){
		y=ach_print("5.first access to the portal",y);
	}
	if(achs[5]){
		y=ach_print("6.move your ball the first time.",y);
	}
	if(achs[6]){
		y=ach_print("7.found Chinese egg 1.",y);
	}
	if(achs[7]){
		y=ach_print("8.found [unable] Egg 1.",y);
	}
}

