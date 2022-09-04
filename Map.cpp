void Map::print(int x,int y){
	system("CLS");
	if(x>=COLS/2 && y>=LINES/2){
		for(int i=x-LINES/2+1;i<=x+LINES/2;i++){
			for(int j=y-COLS/2+1;j<=y+COLS/2;j++){
				if(i==x && j==y){
					putchar('#');
					continue;
				}
				putchar(print_c[a[i][j]]);
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
				putchar(print_c[a[i][j]]);
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
				putchar(print_c[a[i][j]]);
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
				putchar(print_c[a[i][j]]);
			}
			putchar('\n');
		}
	}
}
void Map::change(int x,int y,int c){
	a[x][y]=c;
	downx=max(downx,x);
	righty=max(righty,y);
}
bool Map::issave(int x,int y){
	return a[x][y]!=rock;
}
void Map::imports(){
	ifstream fin;
	fin.open(SAVE_NAME);
	fin >> downx >> righty;
	for(int i=1;i<=downx;i++){
		for(int j=1;j<=righty;j++){
			char ch;
			fin >> ch;
			a[i][j]=ch;
		}
	}
	fin.close();
}
void Map::save(){
	ofstream fout;
	fout.open(SAVE_NAME);
	fout << downx << ' ' << righty;
	for(int i=1;i<=downx;i++){
		for(int j=1;j<=righty;j++){
			fout << a[i][j] << ' ';
		}
		fout << '\n';
	}
	fout.close();
}
map<int,int> Map::operator[](int i){
	return a[i];
}
