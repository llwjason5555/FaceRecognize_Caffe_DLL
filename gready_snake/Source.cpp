#include"Header.h"

char qq = ' ';//��������

void gotoxy(int x, int y)//λ�ú���  
{
	COORD pos;

	pos.X = x;

	pos.Y = y;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void color(int a)//��ɫ����  

{

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), a);

}

void kb_operator(Snake &snake)//�������ƶ�����
{
	if (_kbhit())
	{
		qq = _getch();
	}

	if (isupper(qq))
		qq = qq + 'a' - 'A';
	switch (qq)
	{
	case 'w':
		snake.tcs[1][snake.head]--;
		break;
	case 's':
		snake.tcs[1][snake.head]++;
		break;
	case 'a':
		snake.tcs[0][snake.head]--;
		break;
	case 'd':
		snake.tcs[0][snake.head]++;
		break;
	}
}

void if_collision(Snake &snake, Wall &wall)//�ж����������Ƿ��������Լ������������
{
	if (snake.tcs[0][snake.head] == wall.x&&snake.tcs[1][snake.head] == wall.y)
	{
		snake.tcs[0][++snake.head] = wall.x;
		snake.tcs[1][snake.head] = wall.y;
		gotoxy(snake.tcs[0][snake.head], snake.tcs[1][snake.head]);
		cout << '*';
		for (int i = 0; i<snake.head; i++)//��������
		{
			snake.tcs[0][i] = snake.tcs[0][i + 1];
			snake.tcs[1][i] = snake.tcs[1][i + 1];
			gotoxy(snake.tcs[0][snake.head], snake.tcs[1][snake.head]);
			cout << '*';
		}
		wall.pro_random();
		gotoxy(wall.x, wall.y);
		cout << '*';
	}
	else
	{
		for (int i = 0; i<snake.head; i++)//��������
		{
			snake.tcs[0][i] = snake.tcs[0][i + 1];
			snake.tcs[1][i] = snake.tcs[1][i + 1];
			gotoxy(snake.tcs[0][snake.head], snake.tcs[1][snake.head]);
			cout << '*';
		}
	}
}