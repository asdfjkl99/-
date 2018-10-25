#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

class GameObject
{
private:
	int pos_x;
	int pos_y;
	char shape;
	bool move_flag;

public:
	GameObject(int pos_x, int pos_y, char *shape) : pos_x(pos_x), pos_y(pos_y), move_flag(FALSE)
	{
		this->shape = *shape;
	}

	void move(int inc_x, int inc_y)
	{
		pos_x += inc_x;
		pos_y += inc_y;
	}

	void update()
	{
		srand((unsigned)time(NULL));
		int inc = 0;

		inc = rand() % 3 - 1;
	}

	int getPosition_x() { return pos_x; }
	int getPosition_y() { return pos_y; }
	char getShape() { return shape; }
	bool moveAlert() { return move_flag; }
};

class Monster : public GameObject
{
public:
	Monster() : GameObject(-1, -1, "¡Ø") {};

};

class Goblin : public GameObject
{
public:
	Goblin() : GameObject(-1, -1, "¡×") {};
};

class Star : public GameObject
{
public:
	Star() : GameObject(-1, -1, "¡Ú") {};
};

class Ghost : public GameObject
{
public:
	Ghost() : GameObject(-1, -1, "¢¾") {};
};

class Screen
{
private:
	static const int screen_size_x = 119;
	static const int screen_size_y = 29;
	char screen[screen_size_x + 1][screen_size_y];
	bool is_wall;
	bool is_item;
	int move_count;
	int remain_item;

public:
	Screen() : is_wall(FALSE), is_item(FALSE), move_count(0), remain_item(0)
	{
		for (int i = 0; i <= screen_size_x; i++)
			for (int j = 0; j < screen_size_y; j++)
				screen[i][j] = ' ';
	};

	void draw()
	{
		printf(" [ Monster World (Basic) ] \n");

		for (int i = 0; i <= screen_size_x; i++)
			printf("%s", screen[i]);
	}

	void update()
	{
		for (int i = 0; i < screen_size_y; i++)
			screen[screen_size_x][i] = NULL;
		

	}

	char setScreen (char inc, int x, int y)
	{
		screen[x][y] = inc;
	}

	bool Is_Wall() { return is_wall; }
	bool Is_Item() { return is_item; }

	void MovecountUp(bool alert)
	{
		if (alert == TRUE)
			move_count++;
	}
};

void main()
{
	GameObject obj(-1, -1, " ");
	Screen screen;
	Monster monster;
	Goblin goblin;
	Star star;
	Ghost ghost;

	while (1)
	{
		screen.setScreen(monster.getShape(), monster.getPosition_x(), monster.getPosition_y());
		screen.setScreen(goblin.getShape(), goblin.getPosition_x(), monster.getPosition_y());
		screen.setScreen(star.getShape(), star.getPosition_x(), star.getPosition_y());
		screen.setScreen(ghost.getShape(), ghost.getPosition_x(), ghost.getPosition_y());

		screen.MovecountUp(monster.moveAlert());
		screen.MovecountUp(goblin.moveAlert());
		screen.MovecountUp(star.moveAlert());
		screen.MovecountUp(ghost.moveAlert());


		screen.draw();
	}
}