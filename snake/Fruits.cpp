#include "Fruits.h"

void Fruits::newFruit(int cellsHorizontalCount, int cellsVerticalCount)
{
	x = rand() % cellsHorizontalCount;
	y = rand() % cellsVerticalCount;
}

void Fruits::drawFruit(int scale)
{
	glColor3f(0.7 + rand() % 2, 1.0, 1.0);
	glRectf(x * scale, y * scale, (x + 1) * scale, (y + 1) * scale);
}
