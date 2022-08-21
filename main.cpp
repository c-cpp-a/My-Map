#include<iostream>
#include<windows.h>
#include<conio.h>
#include<map>
using namespace std;
const int COLS=100,LINES=50;
enum{
	defaults,
	ups,
	downs,
	lefts,
	rights
};
enum{
	floor,
	rock
};
int move_f=defaults,x=1,y=1;
class Map{
	private:
		map<int,map<int,int>> a;
	public:
		
	public:
		void print(int x,int y){
			system("CLS");
			if(x>=COLS/2 && y>=LINES/2){
				for(int i=x-LINES/2+1;i<=x+LINES/2;i++){
					for(int j=y-COLS/2+1;j<=y+COLS/2;j++){
						if(i==x && j==y){
							putchar('#');
							continue;
						}
						switch(a[i][j]){
							case floor:
								putchar(' ');
								break;
							case rock:
								putchar('-');
						}
					}
					putchar('\n');
				}
			} else if(x>=COLS/2){
				for(int i=x-LINES/2+1;i<=x+LINES/2;i++){
					for(int j=1;j<=COLS;j++){
						if(i==x && j==y){
							putchar('#');
							continue;
						}
						switch(a[i][j]){
							case floor:
								putchar(' ');
								break;
							case rock:
								putchar('-');
						}
					}
					putchar('\n');
				}
			} else if(y>=COLS/2){
				for(int i=1;i<=LINES;i++){
					for(int j=y-COLS/2+1;j<=y+COLS/2;j++){
						if(i==x && j==y){
							putchar('#');
							continue;
						}
						switch(a[i][j]){
							case floor:
								putchar('.');
								break;
							case rock:
								putchar('-');
						}
					}
					putchar('\n');
				}
			} else{
				for(int i=1;i<=LINES;i++){
					for(int j=1;j<=COLS;j++){
						if(i==x && j==y){
							putchar('#');
							continue;
						}
						switch(a[i][j]){
							case floor:
								putchar('.');
								break;
							case rock:
								putchar('-');
						}
					}
					putchar('\n');
				}
			}
		}
		void change(int x,int y,int c){
			a[x][y]=c;
		}
		bool issave(int x,int y){
			return a[x][y]!=rock;
		}
};
void set_f(Map &h){
	int a=getch();
	switch(a){
		case 'W':case 'w':
			if(!h.issave(x-1,y))	break;
			if(x>1){
				x--;
				move_f=ups;
			}
			break;
		case 'A':case 'a':
			if(!h.issave(x,y-1))	break;
			if(y>1){
				y--;
				move_f=lefts;
			}
			break;
		case 'S':case 's':
			if(!h.issave(x+1,y))	break;
			x++;
			move_f=downs;
			break;
		case 'D':case 'd':
			if(!h.issave(x,y+1))	break;
			y++;
			move_f=rights;
			break;
		case '1':
			switch(move_f){
				case ups:
					h.change(x-1,y,floor);
					break;
				case downs:
					h.change(x+1,y,floor);
					break;
				case lefts:
					h.change(x,y-1,floor);
					break;
				case rights:
					h.change(x,y+1,floor);
			}
			break;
		case '2':
			switch(move_f){
				case ups:
					h.change(x-1,y,rock);
					break;
				case downs:
					h.change(x+1,y,rock);
					break;
				case lefts:
					h.change(x,y-1,rock);
					break;
				case rights:
					h.change(x,y+1,rock);
			}
			break;
	}
}
int main(){
	system("title 我的地图");
	system(("mode "+to_string(COLS)+","+to_string(LINES+10)).c_str());
	Map G;
	while(1){
		G.print(x,y);
		cout << "\n.:空地，可走动\n-:岩石，不可走动\n#:你自己\n"; 
		cout << "WASD移动，按1键将在前进方向上清除岩石，按2键将在前进方向上创建岩石。\n";
		cout << "更多功能拓展中。。。" << endl;
		set_f(G);
		Sleep(10);
	}
	
	return 0;
}

//language:Chinese
//语言：中文
