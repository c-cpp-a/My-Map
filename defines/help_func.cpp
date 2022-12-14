namespace{
	using namespace std;
	void print(const string s){
		for(auto len=s.length(),i=0U;i<len;i++){
			putchar(s[i]);
			Sleep(30);
		}
	}
	void gotoxy(short x,short y){
    	COORD coord = {x, y}; 
    	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
	}
	int ach_print(const string s,short starty){
		int i=0;
		string tmp=s;
		while(tmp.length()>=ADD_COLS-1){
			gotoxy(COLS+2,starty+i);
			cout << string(tmp.begin(),tmp.begin()+ADD_COLS-2);
			tmp.erase(tmp.begin(),tmp.begin()+ADD_COLS-2);
			i++;
		}
		gotoxy(COLS+2,starty+i);
		cout << tmp;
		return starty+i+1;
	}
	void map_print(const char &ch){
		switch(::mode){
			case normal:case debugger:
				putchar(print_c[ch]);
				break;
			case infernal:
				if(ch){
					putchar(print_c[ch]);
				}
				break;
			case AIOC:
				if(ch){
					putchar('-');
				} else{
					putchar(' ');
				}
				break;
		}
	}
}

