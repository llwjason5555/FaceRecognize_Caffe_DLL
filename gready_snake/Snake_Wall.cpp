#include"Header.h"

Snake::Snake(){}

Wall::Wall(){}

void Snake::init()//初始化蛇的位置
{
	head = 0;
	tcs[0][head] = N/2;
	tcs[1][head] = N / 2;
	tcs[0][++head] = N / 2;
	tcs[1][head] = N / 2;
}

void Wall::init()//初始化围墙
{
	x = y = 0;
	for (int i = 0; i<N; i++)
	{
		for (int j = 0; j<N; j++)
		{
			if (i == 0 || i == N-1 || j == 0 || j == N-1)
				q[i][j] = '#';
			else
				q[i][j] = ' ';
		}
	}
}

void Wall::pro_random()//随机产生种子
{
	do
	{
		srand((int)time(0));
		x = rand() % (N-1) + 1;
		y = rand() % (N-1) + 1;
	} while (q[x][y] != ' ');

}

void print(Snake &snake, Wall &wall)//打印初始界面
{
	for (int j = 0; j<N; j++)
	{
		for (int k = 0; k<N; k++)
			cout << wall.q[j][k];
		if (j == 8)
			cout << "w:up，s：down，a：left，d：right";
		if (j == 10)
			cout << "length:" << snake.head;
		cout << endl;
	}
}