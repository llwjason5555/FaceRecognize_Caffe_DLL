#include"Header.h"

vector<int> grade_list(100, 0);

void begin(Snake &snake,Wall &wall)//��ʼ����
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

void play(Snake &snake,Wall &wall)//��ʼ��Ϸ
{
	system("cls");
	snake.init();//��ʼ��̰���ߵĲ���
	wall.init();//��ʼ��Χǽ�Ĳ���
	wall.pro_random();//�����������
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
		//�ǳ���Ҫ�����ԭλ�õġ�*����ʹ�߷����ƶ�
		color(12);
		gotoxy(snake.tcs[0][0], snake.tcs[1][0]);
		cout << ' ';//��������

		kb_operator(snake);//�������룬�����ߵķ���

		//�ж��Ƿ�gameover
		if (snake.tcs[0][snake.head] == 0 || snake.tcs[0][snake.head] == N - 1 || snake.tcs[1][snake.head] == 0 || snake.tcs[1][snake.head] == N - 1)
			break;
		if (snake.tcs[0][snake.head] != wall.x&&snake.tcs[1][snake.head] != wall.y&&wall.q[snake.tcs[0][snake.head]][snake.tcs[1][snake.head]] == '*')
			break;

		if_collision(snake, wall);//�ж����������Ƿ��������Լ������������

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

void grade()//�鿴�ɼ�
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

void end()//�˳���Ϸ
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
