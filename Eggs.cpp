namespace{
	void print(const string s){
		for(auto len=s.length(),i=0ULL;i<len;i++){
			putchar(s[i]);
			Sleep(30);
		}
	}
	
}
int Egg::isegg(const int &lang,People &p){
	if(lang==Chinese && 
		p.at(EGG_POS[0],EGG_POS[1])==People::node(EGG_POS[0],EGG_POS[1])
	   	&& p.pos.x==EGG_POS[0] && p.pos.y==EGG_POS[1])	return CHI_egg_1;
	else	return empty_egg;
}
void Egg::check_run(const int &lang,People &p){
	system("CLS");
	switch(isegg(lang,p)){
		case CHI_egg_1:
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
			break;
	}
}


