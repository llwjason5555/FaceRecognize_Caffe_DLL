#include"Header.h"

vector<int> grade_list(100, 0);

void begin(Snake &snake,Wall &wall)//初始界面
{
	system("cls");
	char s;
	printf("\t\tWelcom to greedy snake!!!\n\n");
	printf("\t\t1:Play game\n\n");
	printf("\t\t2:Check grade\n\n");
	printf("\t\t3:Exit\n\n");
	printf("\t\tPlease make choice\n\n");

	s = getchar();

	switch (s)
	{
	case '1':
		play(snake,wall);
		break;
	case '2':
		grade();
		break;
	case '3':
		end();
		break;
	}
}

void play(Snake &snake,Wall &wall)//开始游戏
{
	system("cls");
	snake.init();//初始化贪吃蛇的参数
	wall.init();//初始化围墙的参数
	wall.pro_random();//随机产生种子
	gotoxy(snake.tcs[0][snake.head], snake.tcs[1][snake.head]);
	color(12);
	cout << '*';
	gotoxy(0, 0);
	color(14);
	print(snake, wall);
	gotoxy(wall.x, wall.y);
	color(12);
	cout << '*';

	while (1)
	{
		//非常重要，清空原位置的‘*’，使蛇发生移动
		color(12);
		gotoxy(snake.tcs[0][0], snake.tcs[1][0]);
		cout << ' ';//精髓所在

		kb_operator(snake);//键盘输入，控制蛇的方向

		//判断是否gameover
		if (snake.tcs[0][snake.head] == 0 || snake.tcs[0][snake.head] == N - 1 || snake.tcs[1][snake.head] == 0 || snake.tcs[1][snake.head] == N - 1)
			break;
		if (snake.tcs[0][snake.head] != wall.x&&snake.tcs[1][snake.head] != wall.y&&wall.q[snake.tcs[0][snake.head]][snake.tcs[1][snake.head]] == '*')
			break;

		if_collision(snake, wall);//判断蛇与种子是否相遇，以及各自清况处理

		gotoxy(N, N / 2);
		color(14);
		cout << "length:" << snake.head;


		Sleep(200 - snake.head * SLEEP_TIME);
	}

	FILE *file = fopen("grade.list", "a");
	if (file != NULL)
	{
		fprintf(file, "%d\n", snake.head);
	}
	fclose(file);

	cout << endl;
	cout << endl;
	cout << endl;
	cout << "You are loser" << endl;
}

void grade()//查看成绩
{
	FILE *file = fopen("grade.list", "r");
	int n = 0;
	if (file != NULL)
	{
		while (fscanf(file, "%d", &n) != EOF)
			grade_list.push_back(n);

	}
	sort(grade_list.begin(), grade_list.end());
	cout << "The grade of top three" << endl;
	for (auto it = grade_list.end() - 1; it != grade_list.end()-4; ++it)
		cout << *it << endl;
	fclose(file);
}

void end()//退出游戏
{
	system("cls");

	system("cls");

	printf("EXIT!!!\n");
}
int main()
{
	Snake snake;
	Wall wall;
	begin(snake,wall);
	return 0;
}
