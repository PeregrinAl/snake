#pragma once
#include "PointSnake.h"
class Snake
{
public:
	Snake();
	~Snake();
	Snake(const int length);
	PointSnake Head();
	PointSnake& operator[](int i);
	void MoveBody(int curLength, int dir, int cellsHorizontalCount, int cellsVerticalCount);
	int NewLenght(int curLength);
	PointSnake* body = new PointSnake;
	void Move(int cellsHorizontalCount, int cellsVerticalCount);

private:
	PointSnake snakeHead;
	bool isAlive = true;
	int currentLength = 0;
	inline void MoveHead(int direction, int cellsHorizontalCount, int cellsVerticalCount);
};

