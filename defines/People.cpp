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
		case 'C':case 'c':
			lang=Chinese;
			break;
		case 'E':case 'e':
			lang=English;
			break;
	}
}
void People::put_xy(Map &h){
	h.print(x,y);
}
