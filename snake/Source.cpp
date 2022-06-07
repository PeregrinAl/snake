#include <time.h>
#include <stdlib.h>
#include  <GL/glut.h>
#include "Fruits.h"
#include "PointSnake.h"
#include "Snake.h"
#include "Game.h"
#include "StaticDrawService.h"
#include "Snake.cpp"
#include "PointSnake.h"

#pragma region variables

const int cellsHorizontalCount = 30;
const int cellsVerticalCount = 20;
const int cellSize = 30;

int unsigned windowWidth = cellSize * cellsHorizontalCount;
int unsigned windowHeight = cellSize * cellsVerticalCount;

int unsigned dir;
int unsigned currentLength = 4;

PointSnake s[cellsHorizontalCount * cellsVerticalCount];
PointSnake snakeHead = s[0];
Snake snake(100);
Fruits fruits[10];

const int unsigned DIRECTION_LEFT = 1;
const int unsigned DIRECTION_RIGHT = 2;
const int unsigned DIRECTION_DOWN = 3;
const int unsigned DIRECTION_UP = 4;


#pragma endregion

#pragma region game methods

void DrawSnake()
{
    glColor3f(0.4, 0.4, 0.8);
    for (int i = 0; i < currentLength; i++)
    {
        glRectf(snake[i].GetX() * cellSize,
            snake[i].GetY() * cellSize,
            (snake[i].GetX() + 0.9) * cellSize,
            (snake[i].GetY() + 0.9) * cellSize);
    }
    glColor3f(0.3, 0.3, 0.7);

    glRectf(snake[0].GetX() * cellSize,
        snake[0].GetY() * cellSize,
        (snake[0].GetX() + 0.9) * cellSize,
        (snake[0].GetY() + 0.9) * cellSize);
}

void EasyMove() {
    //���� ������� �� ������� ������ - ���� �����
    if (snake[0].GetX() > cellsHorizontalCount - 1) {
        snake[0].SetX(0);
    }

    //���� ������� �� ������� ����� - ���� ������
    else if (snake[0].GetX() < 0) {
        snake[0].SetX(cellsHorizontalCount);
    }

    //���� ������� �� ������� ������ - ���� �����
    else if (snake[0].GetY() > cellsVerticalCount - 1) {
        snake[0].SetY(0);
    }

    //���� ������� �� ������� ����� - ���� ������
    else if (snake[0].GetY() < 0) {
        snake[0].SetY(cellsVerticalCount);
    }
    
}

void HardMove() {
    //���� ������� �� ������� ������ - ���� ������
    if (snake[0].GetX() > cellsHorizontalCount - 1) {
        dir = DIRECTION_LEFT;
    }

    //���� ������� �� ������� ����� - ���� ������
    else if (snake[0].GetX() < 0) {
        dir = DIRECTION_RIGHT;
    }

    //���� ������� �� ������� ������ - ���� ����
    else if (snake[0].GetY() > cellsVerticalCount - 1) {
        dir = DIRECTION_DOWN;
    }

    //���� ������� �� ������� ����� - ���� �����
    else if (snake[0].GetY() < 0) {
        dir = DIRECTION_UP;
    }
}

#pragma endregion

#pragma region base methods opengl

void Tick()
{
    snake.MoveBody(currentLength, dir);

    //���� �����
    for (int i = 0; i < 10; i++) {
        if ((snake[0].GetX() == fruits[i].x) && (snake[0].GetY() == fruits[i].y))
        {
            currentLength++;
            fruits[i].New(cellsHorizontalCount, cellsVerticalCount, cellSize);
        }
    }

    EasyMove();
    currentLength = snake.NewLenght(currentLength);
}

void display() {

    glClear(GL_COLOR_BUFFER_BIT);
    StaticDrawService::DrawField(windowWidth, windowHeight, cellSize);
    DrawSnake();

    for (int i = 0; i < 10; i++) {
        fruits[i].DrawApple(cellSize);
    }

    glFlush();
    glutSwapBuffers();
}

void KeyboardEvent(int key, int a, int b)
{
    switch (key)
    {
    case 100:
        dir = 1;
        break;
    case 101:
        dir = 0;
        break;
    case 102:
        dir = 2;
        break;
    case 103:
        dir = 3;
        break;
    }
}

void timer(int = 0)
{
    display();
    Tick();
    glutTimerFunc(50, timer, 0);
}

#pragma endregion

int main(int argc, char** argv) {

    srand(time(0));

    for (int i = 0; i < 10; i++) {
        fruits[i].New(cellsHorizontalCount, cellsVerticalCount, cellSize);
        snake[i].SetX(10);
        snake[i].SetY(10);
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
    glutSpecialFunc(KeyboardEvent);
    glutTimerFunc(50, timer, 0);

    glutMainLoop();
}