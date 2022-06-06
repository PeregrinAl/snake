#pragma once
#include  <GL/glut.h>
#include "Snake.h"

static class StaticDrawService
{
public:
    static void DrawField(int width, int height, int cellSize)
    {
        glColor3f(0.7, 0.7, 0.9);
        glBegin(GL_LINES);
        for (int i = 0; i < width; i += cellSize)
        {
            glVertex2f(i, 0); glVertex2f(i, height);
        }
        for (int j = 0; j < height; j += cellSize)
        {
            glVertex2f(0, j); glVertex2f(width, j);
        }
        glEnd();
    }
};

