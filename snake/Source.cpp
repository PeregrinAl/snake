#include <time.h>
#include <stdlib.h>
#include  <GL/glut.h>
#include "Fruits.h"
#include "PointSnake.h"
#include "Snake.h"
#include "StaticDrawService.h"
#include "PointSnake.h"

#pragma region variables

const int cellsHorizontalCount = 30;
const int cellsVerticalCount = 20;
const int cellSize = 30;

const int unsigned windowWidth = cellSize * cellsHorizontalCount;
const int unsigned windowHeight = cellSize * cellsVerticalCount;

int unsigned direction;

PointSnake s[cellsHorizontalCount * cellsVerticalCount];
Snake snake(100);
Fruits fruits[10];

#pragma endregion

#pragma region game methods

void drawSnake()
    {
    glColor3f(0.4, 0.4, 0.8);
    for (int i = 0; i < snake.currentLength; i++)
        {
        glRectf(snake.body[i].getX() * cellSize,
            snake.body[i].getY() * cellSize,
            (snake.body[i].getX() + 0.9) * cellSize,
            (snake.body[i].getY() + 0.9) * cellSize);
        }
    glColor3f(0.3, 0.3, 0.7);

    glRectf(snake.head().getX() * cellSize,
        snake.head().getY() * cellSize,
        (snake.head().getX() + 0.9) * cellSize,
        (snake.head().getY() + 0.9) * cellSize);
    }
#pragma endregion

#pragma region base methods opengl

void tick()
    {
    snake.moveBody(direction, cellsHorizontalCount, cellsVerticalCount);

    //едим фрукт
    for (int i = 0; i < 10; i++) 
        {
        if ((snake.head().getX() == fruits[i].x) && (snake.head().getY() == fruits[i].y))
            {
            snake.currentLength++;
            for (int j = 0; j < snake.currentLength; j++) 
                {
                while (snake.body[j].getX() == fruits[i].x && snake.body[j].getY() == fruits[i].y) 
                    {
                    fruits[i].newFruit(cellsHorizontalCount, cellsVerticalCount);
                    }
                }
            }
        }
    }

void display() 
    {

    glClear(GL_COLOR_BUFFER_BIT);
    StaticDrawService::DrawField(windowWidth, windowHeight, cellSize);
    drawSnake();

    for (int i = 0; i < 10; i++) 
        {
        fruits[i].drawFruit(cellSize);
        }

    glFlush();
    glutSwapBuffers();
    }

void keyboardEvent(int key, int a, int b)
{
    switch (key)
    {
    case GLUT_KEY_LEFT:
        direction = DIRECTION_LEFT;
        break;
    case GLUT_KEY_UP:
        direction = DIRECTION_UP;
        break;
    case GLUT_KEY_RIGHT:
        direction = DIRECTION_RIGHT;
        break;
    case GLUT_KEY_DOWN:
        direction = DIRECTION_DOWN;
        break;
    }
}

void timer(int = 0)
    {
    display();
    tick();
    glutTimerFunc(50, timer, 0);
    }

#pragma endregion

int main(int argc, char** argv) 
    {

    srand(time(0));

    for (int i = 0; i < 10; i++) 
        {
        fruits[i].newFruit(cellsHorizontalCount, cellsVerticalCount);
        }
    
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(windowWidth, windowHeight);
    glutCreateWindow("RelaxSnake");
    glClearColor(0.8, 0.8, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, windowWidth, 0, windowHeight);

    glutDisplayFunc(display);
    glutSpecialFunc(keyboardEvent);
    glutTimerFunc(50, timer, 0);

    glutMainLoop();
    }