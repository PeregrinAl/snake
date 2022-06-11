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
    void New(int N, int M, int scale);
    void DrawApple(int scale);
};

