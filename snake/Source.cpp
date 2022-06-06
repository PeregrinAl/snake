#include <time.h>
#include <stdlib.h>
#include  <GL/glut.h>
#include "Fruits.h"
#include "PointSnake.h"
#include "Snake.h"

const int width = 30;
const int height = 20;
int Scale = 30;

int w = Scale * width;
int h = Scale * height;

int dir;
int num = 4;

PointSnake s[width * height];
PointSnake snakeHead = s[0];
Snake snake(100);
Fruits fruits[10];

void DrawSnake()
{
    glColor3f(0.6, 0.4, 0.8); // змея цвет
    for (int i = 0; i < num; i++)
    {
        glRectf(snake[i].GetX() * Scale, snake[i].GetY() * Scale, (snake[i].GetX() + 0.9) * Scale, (snake[i].GetY() + 0.9) * Scale);
    }
}

void EasyMove() {

    // движение вверх
    if (dir == 0) {
        snake[0].SetY(snake[0].GetY() + 1);
    }

    //движение влево
    else if (dir == 1) {
        snake[0].SetX(snake[0].GetX() - 1);
    }

    //движение вправо
    else if (dir == 2) {
        snake[0].SetX(snake[0].GetX() + 1);
    }

    //движение вниз
    else if (dir == 3) {
        snake[0].SetY(snake[0].GetY() - 1);
    }
}

void HardMove() {
    if (s[0].GetX() > width - 1) {
        dir = 1;
    }

    //если за границы слева - идем вправо
    else if (s[0].GetX() <= 0) {
        dir = 2;
    }

    //если за границы сверху - идем вниз
    else if (s[0].GetY() > height - 1) {
        dir = 3;
    }

    //если за границы снизу - идем вверх
    else if (s[0].GetY() <= 0) {
        dir = 0;
    }
}

void Tick()
{
    for (int i = num; i > 0; --i)
    {
        snake[i].SetX(snake[i - 1].GetX());
        snake[i].SetY(snake[i - 1].GetY());
    }

    EasyMove();

    //едим фрукт
    for (int i = 0; i < 10; i++) {
        if ((snake[0].GetX() == fruits[i].x) && (snake[0].GetY() == fruits[i].y))
        {
            num++; 
            fruits[i].New(width, height, Scale);
        }
    }

    //если за границы справа - идем из левого
    if (snake[0].GetX() > width - 1) {
        snake[0].SetX(0);
    }

    //если за границы слева - идем справа
    else if (snake[0].GetX() < 0) {
        snake[0].SetX(width );
    }

    //если за границы сверху - идем вниз
    else if (snake[0].GetY() > height - 1) {
        snake[0].SetY(0);
    }

    //если за границы снизу - идем вверх
    else if (snake[0].GetY() < 0) {
        snake[0].SetY(height);
    }

    for (int i = 1;i < num;i++) {
        if (snake[0].GetX() == snake[i].GetX() && snake[0].GetY() == snake[i].GetY()) {
            num = i;
        }
    }
}



void DrawField()
{
    glColor3f(0.7, 0.7, 0.8); // Грид
    glBegin(GL_LINES);
    for (int i = 0; i < w; i += Scale)
    {
        glVertex2f(i, 0); glVertex2f(i, h);
    }
    for (int j = 0; j < h; j += Scale)
    {
        glVertex2f(0, j); glVertex2f(w, j);
    }
    glEnd();
}


void display() {

    glClear(GL_COLOR_BUFFER_BIT);

    DrawField();

    DrawSnake();

    for (int i = 0; i < 10; i++) {
        fruits[i].DrawApple(Scale);
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

int main(int argc, char** argv) {

    srand(time(0));

    for (int i = 0; i < 10;i++) {
        fruits[i].New(width, height, Scale);

        snake[i].SetX(10);
        snake[i].SetY(10);
    }

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(w, h);
    glutCreateWindow("Test");
    glClearColor(0.8, 0.8, 1.0, 1.0);  //цвет фона
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, w, 0, h);

    glutDisplayFunc(display);
    glutSpecialFunc(KeyboardEvent);
    glutTimerFunc(50, timer, 0);

    glutMainLoop();
}