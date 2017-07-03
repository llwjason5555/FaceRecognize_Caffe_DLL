class Snake;//此类中包含Snake类，所以要先声明

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