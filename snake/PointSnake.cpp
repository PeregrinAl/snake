#include "PointSnake.h"

PointSnake::PointSnake()
{
	this->xCoordinate = 0;
	this->yCoordinate = 0;
}

PointSnake::PointSnake(int x, int y)
{
	this->xCoordinate = x;
	this->yCoordinate = y;
}

int PointSnake::GetX()
{
	return xCoordinate;
}

int PointSnake::GetY()
{
	return yCoordinate;
}

void PointSnake::SetX(int x)
{
	xCoordinate = x;
}

void PointSnake::SetY(int y)
{
	yCoordinate = y;
}
