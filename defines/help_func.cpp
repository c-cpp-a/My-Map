namespace{
	using namespace std;
	void print(const string s){
		for(auto len=s.length(),i=0ULL;i<len;i++){
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
		while(tmp.length()>=19){
			gotoxy(COLS+2,starty+i);
			cout << string(tmp.begin(),tmp.begin()+18);
			tmp.erase(tmp.begin(),tmp.begin()+18);
			i++;
		}
		gotoxy(COLS+2,starty+i);
		cout << tmp;
		return starty+i+1;
	}
}

