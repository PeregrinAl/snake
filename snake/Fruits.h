#pragma once
#include <windows.h>
#include <gl/GL.h>
#include <stdlib.h>
#include <math.h>
class Fruits
{
public:
    int x;
    int y;
    void New(int cellsHorizontalCount, int cellsVerticalCount);
    void DrawApple(int scale);
};

