#include<iostream>
#include<windows.h>
#include<conio.h>
#include<time.h>
#include<vector>
#include<algorithm>
#include<ctype.h>

#include"Snake.h"
#include"Wall.h"

#define N 21
#define SLEEP_TIME 5

using namespace std;

void begin(Snake &, Wall &);
void grade();
void end();

void gotoxy(int x, int y);
void color(int a);
