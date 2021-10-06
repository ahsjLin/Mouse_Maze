//---------------------------------------------------------------------------

#include <System.hpp>
#pragma hdrstop

#include "findExitThread.h"
#pragma package(smart_init)

#define ROW 32
#define COLUMN 32
#define MAX_STACK 1000
extern int ori[ROW][COLUMN];
extern int maze[ROW][COLUMN];
extern int in_x;
extern int in_y;
extern int out_x;
extern int out_y;
extern int top;
void push(int x, int y, int direction);
void pop();
void showMaze();
void reDrawPath();
int checkCanRun(int go);
void sendPush(int direction);
void findEixt();
//---------------------------------------------------------------------------

//   Important: Methods and properties of objects in VCL can only be
//   used in a method called using Synchronize, for example:
//
//      Synchronize(&UpdateCaption);
//
//   where UpdateCaption could look like:
//
//      void __fastcall findExitThread::UpdateCaption()
//      {
//        Form1->Caption = "Updated in a thread";
//      }
//---------------------------------------------------------------------------

__fastcall findExitThread::findExitThread(bool CreateSuspended)
	: TThread(CreateSuspended)
{
}
//---------------------------------------------------------------------------
void __fastcall findExitThread::Execute()
{
	//---- Place thread code here ----
    findEixt();
}
//---------------------------------------------------------------------------
