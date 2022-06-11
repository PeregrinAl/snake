#pragma once
class PointSnake
{
public:
	PointSnake();
	PointSnake(int x, int y);
	int GetX();
	int GetY();
	void SetX(int x);
	void SetY(int y);
private:
	int xCoordinate;
	int yCoordinate;
};

