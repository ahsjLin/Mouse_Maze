//---------------------------------------------------------------------------

#ifndef findExitThreadH
#define findExitThreadH
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
#include <System.Classes.hpp>
//---------------------------------------------------------------------------
class findExitThread : public TThread
{
private:
protected:
	void __fastcall Execute();
public:
	__fastcall findExitThread(bool CreateSuspended);
};
//---------------------------------------------------------------------------
#endif
