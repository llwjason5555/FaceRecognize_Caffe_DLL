class Wall;//�����а���Wall�࣬Ҫ������

class Snake
{
public:
	friend class Walll;
	friend void print(Snake &,Wall &);
	friend void kb_operator(Snake &);
	friend void if_collision(Snake &, Wall &);
	friend void play(Snake &, Wall &);

	Snake();
	void init();
private:
	int tcs[2][20];
	int head;
};

