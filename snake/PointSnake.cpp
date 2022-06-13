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

int PointSnake::getX()
{
	return xCoordinate;
}

int PointSnake::getY()
{
	return yCoordinate;
}

void PointSnake::setX(int x)
{
	xCoordinate = x;
}

void PointSnake::setY(int y)
{
	yCoordinate = y;
}
