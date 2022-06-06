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

    void New(int N, int M, int scale)
    {
        x = rand() % N;
        y = rand() % M;
    }

    void DrawApple(int scale)
    {
        glColor3f(0.7 + rand() % 2, 1.0, 1.0);
        glRectf(x * scale, y * scale, (x + 1) * scale, (y + 1) * scale);
    }
};

