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
	void MoveBody(int dir, int cellsHorizontalCount, int cellsVerticalCount);
	void NewLenght();
	PointSnake* body = new PointSnake;

	int currentLength = 4;

private:
	PointSnake snakeHead;
	bool isAlive = true;
	inline void MoveHead(int direction, int cellsHorizontalCount, int cellsVerticalCount);
};

