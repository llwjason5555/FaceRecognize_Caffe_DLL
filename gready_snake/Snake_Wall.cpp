#include"Header.h"

Snake::Snake(){}

Wall::Wall(){}

void Snake::init()//��ʼ���ߵ�λ��
{
	head = 0;
	tcs[0][head] = N/2;
	tcs[1][head] = N / 2;
	tcs[0][++head] = N / 2;
	tcs[1][head] = N / 2;
}

void Wall::init()//��ʼ��Χǽ
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

void Wall::pro_random()//�����������
{
	do
	{
		srand((int)time(0));
		x = rand() % (N-1) + 1;
		y = rand() % (N-1) + 1;
	} while (q[x][y] != ' ');

}

void print(Snake &snake, Wall &wall)//��ӡ��ʼ����
{
	for (int j = 0; j<N; j++)
	{
		for (int k = 0; k<N; k++)
			cout << wall.q[j][k];
		if (j == 8)
			cout << "w:up��s��down��a��left��d��right";
		if (j == 10)
			cout << "length:" << snake.head;
		cout << endl;
	}
}