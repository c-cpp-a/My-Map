void Map::print(int x,int y){
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
void Map::change(int x,int y,int c){
	a[x][y]=c;
}
bool Map::issave(int x,int y){
	return a[x][y]!=rock;
}
