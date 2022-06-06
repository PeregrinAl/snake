#pragma once
#include "PointSnake.h"
class Snake
{
public:
	Snake() {
		snakeHead = PointSnake(0, 0);
	}

	~Snake() {
		delete(body);
	}

	Snake(const int length) {
		this->body = new PointSnake[length];
		this->snakeHead = body[0];
	}

	PointSnake Head() {
		return body[0];
	}

	PointSnake& operator[](int i) {
		return body[i];
	}

private:
	PointSnake snakeHead;
	bool isAlive = true;
	PointSnake* body = new PointSnake;
};

