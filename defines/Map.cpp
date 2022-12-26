void Map::print(int x,int y,const int &direct){
	gotoxy(0,0); 
	if(x>=COLS/2 && y>=LINES/2){
		for(int i=x-LINES/2+1;i<=x+LINES/2;i++){
			for(int j=y-COLS/2+1;j<=y+COLS/2;j++){
				if(i==x && j==y){
					putchar('#');
					continue;
				}
				map_print(a[i][j]);
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
				map_print(a[i][j]);
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
				map_print(a[i][j]);
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
				map_print(a[i][j]);
			}
			putchar('\n');
		}
	}
	if(::mode==debugger){
		string contents="pos=("+to_string(x)+","+to_string(y)+"),direct="+direct_content[::lang][direct];
		gotoxy(0,COLS);
		cout << contents;
	}
}
void Map::change(int x,int y,int c){
	a[x][y]=c;
	save_message.push_back(save_format(x,y,c,nowt++));
}
bool Map::issave(int x,int y){
	return a[x][y]!=rock;
}
void Map::imports(ifstream &fin){
	int n;
	fin >> n;
	while(n--){
		int x,y,c,t;
		fin >> x >> y >> c >> t;
		a[x][y]=c;
		save_message.push_back(save_format(x,y,c,t));
		nowt=max(nowt,t);
	}
	++nowt;
}
void Map::save(ofstream &fout){
	sort(save_message.begin(),save_message.end());
	for(int i=1,len=save_message.size();i<len;i++){
		if(save_message[i]==save_message[i-1]){
			save_message.erase(save_message.begin()+i-1);
		}
	}
	fout << save_message.size() << endl;
	for(int i=0,len=save_message.size();i<len;i++){
		fout << save_message[i].x << ' ' << save_message[i].y << ' ' << save_message[i].c << ' ' << save_message[i].t << endl;
	}
}
map<int,int> Map::operator[](const int i){
	return a[i];
}
