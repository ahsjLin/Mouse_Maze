#ifndef __MAZEFUNCTION_H_
#define __MAZEFUNCTION_H_

//#include <vcl.h>
#include <chrono>
#include <thread>

#include "Mouse_Maze.h"
//#include "findExitThread.h"


#define ROW 32
#define COLUMN 32
#define MAX_STACK 1000



using namespace std;
using namespace std::this_thread;     // sleep_for, sleep_until
using namespace std::chrono_literals; // ns, us, ms, s, h, etc.
using std::chrono::system_clock;

extern int in_x;
extern int in_y;
extern int out_x;
extern int out_y;
extern int top;
extern bool isfinding;
extern bool init;

enum direction {N, E, S, W};
struct position{
	int di=in_x, dj=in_y;
	int direction=0;
};
struct position POS[MAX_STACK];

extern int ori[ROW][COLUMN];
extern int maze[ROW][COLUMN];


// function
void push(int x, int y, int direction);
void pop();
void showMaze();
void reDrawPath();
int checkCanRun(int go);
void sendPush(int direction);
void findEixt();

#endif
