bool People::node::operator!=(People::node a){
	return x!=a.x || y!=a.y;
}
void People::set_f(Map &h){
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
		case '3':
			{
				int xx,yy,nx,ny,input=0;
				switch(move_f){
					case ups:
						h.change(x-1,y,door);
						xx=x-1,yy=y;
						break;
					case downs:
						h.change(x+1,y,door);
						xx=x+1,yy=y;
						break;
					case lefts:
						h.change(x,y-1,door);
						xx=x,yy=y-1;
						break;
					case rights:
						h.change(x,y+1,door);
						xx=x,yy=y+1;
				}
				nx=xx,ny=yy;
				while(input!=' '){
					h.print(nx,ny);
					create_door_helper();
					input=getch();
					switch(input){
						case 'W':case 'w':
							if(nx>1)	nx--;
							break;
						case 'A':case 'a':
							if(ny>1)	ny--;
							break;
						case 'S':case 's':
							nx++;
							break;
						case 'D':case 'd':
							ny++;
							break;
					}
				}
				doors[xx][yy]=node({nx,ny});
			}
			break; 
		case 'C':case 'c':
			lang=Chinese;
			break;
		case 'E':case 'e':
			lang=English;
			break;
	}
	if(doors[x][y]!=default_door){
		int xx=x,yy=y;
		x=doors[xx][yy].x;
		y=doors[xx][yy].y;
	}
}
void People::put_xy(Map &h){
	h.print(x,y);
}
void People::save(Map &h){
	ofstream fout;
	fout.open(SAVE_NAME);
	h.save();
	fout << x << ' ' << y << endl;
	fout.close();
	
}
void People::imports(Map &h){
	ifstream fin;
	fin.open(SAVE_NAME);
	h.imports();
	fin >> x >> y;
	fin.close();
}
