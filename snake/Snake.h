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

	void MoveBody(int curLength, int dir) {
		for (int i = curLength; i > 0; --i)
		{
			body[i].SetX(body[i - 1].GetX());
			body[i].SetY(body[i - 1].GetY());
		}
		MoveHead(dir);
	}

	int NewLenght(int curLength) {
		for (int i = 1; i < curLength; i++) {
			if (body[0].GetX() == body[i].GetX() && body[0].GetY() == body[i].GetY()) {
				return i;
			}
		}
		return curLength;
	}

private:
	PointSnake snakeHead;
	bool isAlive = true;
	PointSnake* body = new PointSnake;
	int currentLength = 0;

	void MoveHead(int direction) {
		// движение вверх
		if (direction == 0) {
			body[0].SetY(body[0].GetY() + 1);
		}

		//движение влево
		else if (direction == 1) {
			body[0].SetX(body[0].GetX() - 1);
		}

		//движение вправо
		else if (direction == 2) {
			body[0].SetX(body[0].GetX() + 1);
		}

		//движение вниз
		else if (direction == 3) {
			body[0].SetY(body[0].GetY() - 1);
		}
	}
};

