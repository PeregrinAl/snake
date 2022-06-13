#include "Snake.h"

Snake::Snake()
    {
	snakeHead = PointSnake(10, 10);
    }

Snake::~Snake()
    {
	delete(body);
    }

Snake::Snake(const int length)
    {
	this->body = new PointSnake[length];
	this->body[0] = PointSnake(10, 10);
	this->snakeHead = body[0];
    }

PointSnake Snake::head()
    {
	return body[0];
    }

PointSnake& Snake::operator[](int i)
    {
	return body[i];
    }

void Snake::moveBody(int direction, int cellsHorizontalCount, int cellsVerticalCount)
    {
	for (int i = currentLength; i > 0; i--)
	    {
		body[i].setX(body[i - 1].getX());
		body[i].setY(body[i - 1].getY());
	    }
	moveHead(direction, cellsHorizontalCount, cellsVerticalCount);
    }

void Snake::newLenght()
    {
	for (int i = 1; i < currentLength; i++) 
	    {
		if (body[0].getX() == body[i].getX() && body[0].getY() == body[i].getY()) 
		    {
			currentLength = i;
		    }
	    }
    }

void Snake::moveHead(int direction, int cellsHorizontalCount, int cellsVerticalCount)
    {
	// движение вверх
	if (direction == DIRECTION_UP) 
	    {
		if (body[0].getY() == cellsVerticalCount - 1) 
		    {
			body[0].setY(0);
		    }
		else 
		    {
			body[0].setY(body[0].getY() + 1);
		    }
	    }

	//движение влево
	else if (direction == DIRECTION_LEFT) 
	    {
		if (body[0].getX() == 0) 
		    {
			body[0].setX(cellsHorizontalCount - 1);
		    }
		else 
		    {
			body[0].setX(body[0].getX() - 1);
		    }
	    }

	//движение вправо
	else if (direction == DIRECTION_RIGHT) 
	    {
		if (body[0].getX() == cellsHorizontalCount - 1) 
		    {
			body[0].setX(0);
		    }
		else 
		    {
			body[0].setX(body[0].getX() + 1);
		    }
	    }

	//движение вниз
	else 
	    {
		if (body[0].getY() == 0) 
		    {
			body[0].setY(cellsVerticalCount - 1);
		    }
		else 
		    {
			body[0].setY(body[0].getY() - 1);
		    }
	    }
	newLenght();
    }
