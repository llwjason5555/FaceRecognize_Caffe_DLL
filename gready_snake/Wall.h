class Snake;//�����а���Snake�࣬����Ҫ������

class Wall
{
public:
	friend class Snake;
	friend void print(Snake &, Wall &);
	friend void if_collision(Snake &, Wall &);
	friend void play(Snake &, Wall &);

	Wall();
	void init();
	void pro_random();
private:
	char q[21][21];
	int x,y;
};