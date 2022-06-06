#include <time.h>
#include <stdlib.h>
#include  <GL/glut.h>
#include "Fruits.h"
#include "PointSnake.h"
#include "Snake.h"
#include "Game.h"
#include "StaticDrawService.h"

const int width = 30;
const int height = 20;
const int cellSize = 30;
int mode = 0;

int w = cellSize * width;
int h = cellSize * height;

int dir;
int num = 4;

PointSnake s[width * height];
PointSnake snakeHead = s[0];
Snake snake(100);
Fruits fruits[10];

void DrawSnake()
{
    glColor3f(0.6, 0.4, 0.8); // ���� ����
    for (int i = 0; i < num; i++)
    {
        glRectf(snake[i].GetX() * cellSize,
            snake[i].GetY() * cellSize,
            (snake[i].GetX() + 0.9) * cellSize,
            (snake[i].GetY() + 0.9) * cellSize);
    }
}

void EasyMove() {
    //���� �� ������� ������ - ���� �� ������
    if (snake[0].GetX() > width - 1) {
        snake[0].SetX(0);
    }

    //���� �� ������� ����� - ���� ������
    else if (snake[0].GetX() < 0) {
        snake[0].SetX(width);
    }

    //���� �� ������� ������ - ���� ����
    else if (snake[0].GetY() > height - 1) {
        snake[0].SetY(0);
    }

    //���� �� ������� ����� - ���� �����
    else if (snake[0].GetY() < 0) {
        snake[0].SetY(height);
    }
    
}

void HardMove() {

    if (snake[0].GetX() > width - 1) {
        dir = 1;
    }

    //���� �� ������� ����� - ���� ������
    else if (snake[0].GetX() < 0) {
        dir = 2;
    }

    //���� �� ������� ������ - ���� ����
    else if (snake[0].GetY() > height - 1) {
        dir = 3;
    }

    //���� �� ������� ����� - ���� �����
    else if (snake[0].GetY() < 0) {
        dir = 0;
    }
}

void Tick()
{
    snake.MoveBody(num, dir);

    //���� �����
    for (int i = 0; i < 10; i++) {
        if ((snake[0].GetX() == fruits[i].x) && (snake[0].GetY() == fruits[i].y))
        {
            num++; 
            fruits[i].New(width, height, cellSize);
        }
    }

    if (mode == 0) {
        EasyMove();
    }
    else {
        HardMove();
    }

    num = snake.CheckDamage(num);
}

void display() {

    glClear(GL_COLOR_BUFFER_BIT);
    StaticDrawService::DrawField(w, h, cellSize);
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
    if (mode == 0) {
        glutTimerFunc(50, timer, 0);
    }
    else if (mode == 1) {
        glutTimerFunc(20, timer, 0);
    }
}

int main(int argc, char** argv) {

    srand(time(0));

    for (int i = 0; i < 10; i++) {
        fruits[i].New(width, height, cellSize);
        snake[i].SetX(10);
        snake[i].SetY(10);
    }
    
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(w, h);
    glutCreateWindow("RelaxSnake");
    glClearColor(0.8, 0.8, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, w, 0, h);

    glutDisplayFunc(display);
    glutSpecialFunc(KeyboardEvent);
    glutTimerFunc(50, timer, 0);

    glutMainLoop();
}