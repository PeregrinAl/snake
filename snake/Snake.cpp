#include "Snake.h"

Snake::Snake()
{
	snakeHead = PointSnake(0, 0);
}

Snake::~Snake()
{
	delete(body);
}

Snake::Snake(const int length)
{
	this->body = new PointSnake[length];
	this->snakeHead = body[0];
}

PointSnake Snake::Head()
{
	return body[0];
}

PointSnake& Snake::operator[](int i)
{
	return body[i];
}

void Snake::MoveBody(int curLength, int direction, int cellsHorizontalCount, int cellsVerticalCount)
{
	for (int i = curLength; i > 0; --i)
	{
		body[i].SetX(body[i - 1].GetX());
		body[i].SetY(body[i - 1].GetY());
	}
	MoveHead(direction, cellsHorizontalCount, cellsVerticalCount);
}

int Snake::NewLenght(int curLength)
{
	for (int i = 1; i < curLength; i++) {
		if (body[0].GetX() == body[i].GetX() && body[0].GetY() == body[i].GetY()) {
			return i;
		}
	}
	return curLength;
}


void Snake::MoveHead(int direction, int cellsHorizontalCount, int cellsVerticalCount)
{
	// движение вверх
	if (direction == 0) {
		if (body[0].GetY() >= cellsVerticalCount - 1) {
			body[0].SetY(0);
		}
		else {
			body[0].SetY(body[0].GetY() + 1);
		}
	}

	//движение влево
	else if (direction == 1) {
		if (body[0].GetX() == 0) {
			body[0].SetX(cellsHorizontalCount - 1);
		}
		else {
			body[0].SetX(body[0].GetX() - 1);
		}
	}

	//движение вправо
	else if (direction == 2) {
		if (body[0].GetX() >= cellsHorizontalCount - 1) {
			body[0].SetX(0);
		}
		else {
			body[0].SetX(body[0].GetX() + 1);
		}
	}

	//движение вниз
	else {
		if (body[0].GetY() == 0) {
			body[0].SetY(cellsVerticalCount - 1);
		}
		else {
			body[0].SetY(body[0].GetY() - 1);
		}
	}
}
