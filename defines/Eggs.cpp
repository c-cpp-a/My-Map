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


