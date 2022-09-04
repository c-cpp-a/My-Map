bool People::node::operator!=(People::node a){
	return x!=a.x || y!=a.y;
}
bool People::node::operator==(People::node a){
	return x==a.x && y==a.y;
}
bool People::node::check(){
	return x>=1 && y>=1;
}
People::node People::check_xy(node x,const int &func){
	node res=x;
	switch(func){
		case ups:
			res.x--;
			break;
		case downs:
			res.x++;
			break;
		case lefts:
			res.y--;
			break;
		case rights:
			res.y++;
			break;
	}
	return (res.check()?res:x);
}
const int People::back(const int &func){
	switch(func){
		case ups:
			return downs;
		case downs:
			return ups;
		case lefts:
			return rights;
		case rights:
			return lefts;
	}
	return func;
}
void People::set_f(Map &h){
	int a=getch();
	switch(a){
		case 'W':case 'w':
			if(!h.issave(pos.x-1,pos.y))	break;
			if(pos.x>1){
				pos.x--;
				move_f=ups;
			}
			break;
		case 'A':case 'a':
			if(!h.issave(pos.x,pos.y-1))	break;
			if(pos.y>1){
				pos.y--;
				move_f=lefts;
			}
			break;
		case 'S':case 's':
			if(!h.issave(pos.x+1,pos.y))	break;
			pos.x++;
			move_f=downs;
			break;
		case 'D':case 'd':
			if(!h.issave(pos.x,pos.y+1))	break;
			pos.y++;
			move_f=rights;
			break;
		case '1':
			{
				auto tmp=check_xy(pos,move_f);
				h.change(tmp.x,tmp.y,floor);
				doors[tmp.x][tmp.y]=default_node;
			}
			break;
		case '2':
			{
				auto tmp=check_xy(pos,move_f);
				h.change(tmp.x,tmp.y,rock);
				doors[tmp.x][tmp.y]=default_node;
			}
			break;
		case '3':
			{
				int input=0;
				auto tmp=check_xy(pos,move_f),tmp2=tmp;
				h.change(tmp.x,tmp.y,door);
				while(input!=' '){
					h.print(tmp2.x,tmp2.y);
					create_door_helper();
					input=getch();
					switch(input){
						case 'W':case 'w':
							if(tmp2.x>1)	tmp2.x--;
							break;
						case 'A':case 'a':
							if(tmp2.y>1)	tmp2.y--;
							break;
						case 'S':case 's':
							tmp2.x++;
							break;
						case 'D':case 'd':
							tmp2.y++;
							break;
					}
				}
				doors[tmp.x][tmp.y]=tmp2;
			}
			break; 
		case '4':
			{
				auto tmp=check_xy(pos,move_f);
				h.change(tmp.x,tmp.y,ball);
				doors[tmp.x][tmp.y]=default_node;
			}
			break;
		case 'C':case 'c':
			lang=Chinese;
			break;
		case 'E':case 'e':
			lang=English;
			break;
	}
	if(doors[pos.x][pos.y]!=default_node){
		auto tmp=pos;
		pos.x=doors[tmp.x][tmp.y].x;
		pos.y=doors[tmp.x][tmp.y].y;
	} else if(h[pos.x][pos.y]==ball){
		auto tmp=pos;
		bool flag=true;
		while(h[tmp.x][tmp.y]!=floor){
			if(h[tmp.x][tmp.y]==rock || !tmp.check()){
				flag=false;
				break;
			}
			tmp=check_xy(tmp,move_f);
		}
		if(flag){
			h.change(tmp.x,tmp.y,ball);	
			h.change(pos.x,pos.y,floor);
		} else{
			pos=check_xy(pos,back(move_f));
		}
	}
}
void People::put_xy(Map &h){
	h.print(pos.x,pos.y);
}
//void People::save(Map &h){
//	ofstream fout;
//	fout.open(SAVE_NAME);
//	h.save();
//	fout << endl << x << ' ' << y << endl;
//	fout.close();
//	
//}
//void People::imports(Map &h){
//	ifstream fin;
//	fin.open(SAVE_NAME);
//	h.imports();
//	fin >> x >> y;
//	fin.close();
//}
