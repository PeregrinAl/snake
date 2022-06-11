#pragma once
#include  <GL/glut.h>
#include "Snake.h"

static class StaticDrawService
{
public:
    static void DrawField(int width, int height, int cellSize);
};

