#include "mazeFunction.h"

// function
void push(int x, int y, int direction){
	maze[in_x][in_y] = 3;
	in_x += x;
	in_y += y;


	top++;
	POS[top].di = in_x;
	POS[top].dj = in_y;
	POS[top].direction = direction;
}
void pop(){
	maze[in_x][in_y] = 9;
	POS[top].direction = 0;
	top--;
	in_x = POS[top].di;
	in_y = POS[top].dj;
	maze[in_x][in_y] = 0;
}
void showMaze(){
	int limit_up, limit_down;
	if(init){
		limit_up = in_x+2;
		limit_down = in_x-1;
	}
	else{
	   limit_up = ROW;
	   limit_down = 0;
	}
	for(int i=limit_down; i<limit_up; i++){
		if(init && (i<0 || i>ROW)) continue;
		String row = "";
		if(Form1->CheckBox1->Checked){
			for(int j=0; j<COLUMN; j++){
				switch(maze[i][j]){
					case 0: // unknown path
						row += "0";
						break;
					case 1: // wall
						row += "1";
						break;
					case 3: // survey
						row += "5";
						break;
					case 9: // wrong way
						row += "4";
						break;
				}
			}
		}
		else{
			for(int j=0; j<COLUMN; j++){
				switch(maze[i][j]){
					case 0: // unknown path
						row += " ";
						break;
					case 1: // wall
						row += "=";
						break;
					case 3: // survey
						row += "x";
						break;
					case 9: // wrong way
						row += "-";
						break;
				}
			}
		}
		if(init){
			//Form1->Memo1->Lines->Delete(i);
			//Form1->Memo1->Lines->Insert(i,row);
			if(row!=Form1->Memo1->Lines->Strings[i])
				Form1->Memo1->Lines->Strings[i]= row;
		}
		else{
			Form1->Memo1->Lines->Add(row);
		}
	}
}
void reDrawPath(){
	if(init==0)	Form1->Memo1->Lines->Clear();
	showMaze();
	int delay_time;

	if(Form1->Edit1->Text == ""){
		delay_time = 0;
		Form1->Edit1->Text = "0";
	}
	else{
		delay_time = StrToInt(Form1->Edit1->Text);
	}
	sleep_for(std::chrono::milliseconds(delay_time));
}
int checkCanRun(int go){
		int temp_x = POS[top].di;
		int temp_y = POS[top].dj;
		switch(go){
			case N:
				temp_x+=-1;
				temp_y+=0;
				break;
			case E:
				temp_x+=0;
				temp_y+=1;
				break;
			case S:
				temp_x+=1;
				temp_y+=0;
				break;
			case W:
				temp_x+=0;
				temp_y+=-1;
				break;
		}
		if(maze[temp_x][temp_y]==0) return 0;
		else return 1;
}
void sendPush(int direction){
	switch(direction){
		case N:
			push(-1,0,N);
			break;
		case E:
			push(0,1,E);
			break;
		case S:
			push(1,0,S);
			break;
		case W:
			push(0,-1,W);
			break;
		default:
			pop();
			break;
	}
}
void findEixt(){
	init = 1;
	  while(in_x!=out_x && in_y!=out_y){
		  int next_top = top+1;
		  for(int i=POS[next_top].direction; i<=W+1; i++){
			if(checkCanRun(i)==0) { sendPush(i); break;}
		}
		reDrawPath();
	  }
	  maze[POS[top].di][POS[top].dj] = 3;
	  reDrawPath();
	  ShowMessage("Success");
	  isfinding = false;
}
