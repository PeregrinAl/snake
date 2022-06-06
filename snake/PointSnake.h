#pragma once
class PointSnake
{
public:
	PointSnake() {
		this->xCoordinate = 0;
		this->yCoordinate = 0;
	}

	PointSnake(int x, int y) {
		this->xCoordinate = x;
		this->yCoordinate = y;
	}

	int GetX() {
		return xCoordinate;
	}

	int GetY() {
		return yCoordinate;
	}

	void SetX(int x) {
		xCoordinate = x;
	}

	void SetY(int y) {
		yCoordinate = y;
	}

private:
	int xCoordinate;
	int yCoordinate;
};

