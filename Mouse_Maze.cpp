//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Mouse_Maze.h"
#include <chrono>
#include <thread>
using namespace std;
using namespace std::this_thread;     // sleep_for, sleep_until
using namespace std::chrono_literals; // ns, us, ms, s, h, etc.
using std::chrono::system_clock;

int maze[12][14] = {
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{1,0,0,0,1,0,0,0,0,0,1,0,1,1},
	{1,1,1,0,1,0,1,1,1,0,1,0,0,1},
	{1,0,1,0,0,0,0,1,0,0,1,0,1,1},
	{1,1,1,0,1,1,0,1,0,1,1,0,1,1},
	{1,1,1,0,1,0,0,1,0,0,0,0,1,1},
	{1,1,1,1,1,0,1,0,0,1,1,1,1,1},
	{1,0,1,1,0,0,1,0,1,1,0,0,0,1},
	{1,0,0,0,0,1,1,0,0,0,0,1,0,1},
	{1,0,1,1,0,0,0,1,0,1,0,1,0,1},
	{1,0,1,1,1,1,0,0,0,0,0,0,0,0},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};
// max stack
#define MAX_STACK 1000
// indoor
int in_x=1, in_y=1;
// outdoor
int out_x=11, out_y=13;

enum direction {N, E, S, W};

struct position{
	int di=in_x, dj=in_y;
	int direction=0;
};
int top = 0;
struct position POS[MAX_STACK];

// push
void push(int x, int y, int direction){
	maze[in_x][in_y] = 3;
	in_x += x;
	in_y += y;


	top++;
	POS[top].di = in_x;
	POS[top].dj = in_y;
	POS[top].direction = direction;
}

// pop
void pop(){
	maze[in_x][in_y] = 9;
	POS[top].direction = 0;
	top--;
	in_x = POS[top].di;
	in_y = POS[top].dj;
	maze[in_x][in_y] = 0;
}
void showMaze(){
	for(int i=0; i<12; i++){
		String row = "";
		for(int j=0; j<14; j++){
			switch(maze[i][j]){
				case 0:
					row += " ";
					break;
				case 1:
					row += "=";
					break;
				case 3:
					row += "x";
					break;
				case 9:
					row += "-";
					break;
			}
		}
		Form1->Memo1->Lines->Add(row);
	}
}
void reDrawPath(){
	Form1->Memo1->Lines->Clear();
	showMaze();
	//sleep_for(500ms);
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
	  while(in_x!=out_x && in_y!=out_y){
		  int next_top = top+1;
		  for(int i=POS[next_top].direction; i<=W+1; i++){
			if(checkCanRun(i)==0) { sendPush(i); break;}
		}
		reDrawPath();
	  }
	  maze[POS[top].di][POS[top].dj] = 3;
	  reDrawPath();
	  ShowMessage("Find Exit");
}


//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------

__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
	showMaze();
}

//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
	findEixt();
}
//---------------------------------------------------------------------------
