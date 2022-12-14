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
}
bool Map::issave(int x,int y){
	return a[x][y]!=rock;
}
void Map::imports(ifstream &fin){
	int x,y,c;
	while(fin >> x >> y >> c){
		if(x==-1 && y==-1 && c==-1){
			break;
		}
		a[x][y]=c;
	}
}
void Map::save(ofstream &fout){
	for(auto it=a.begin();it!=a.end();++it){
		for(auto itj=(it->second).begin();itj!=(it->second).end();++itj){
			if((itj->second)!=floors){
				fout << (it->first) << ' ' << (itj->first) << ' ' << (itj->second) << endl;
			}
		}
	} 
	fout << "-1 -1 -1\n";
}
map<int,int> Map::operator[](const int i){
	return a[i];
}
