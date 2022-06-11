#include <time.h>
#include <stdlib.h>
#include  <GL/glut.h>
#include "Fruits.h"
#include "PointSnake.h"
#include "Snake.h"
#include "Game.h"
#include "StaticDrawService.h"
#include "PointSnake.h"

#pragma region variables

const int cellsHorizontalCount = 30;
const int cellsVerticalCount = 20;
const int cellSize = 30;

int unsigned windowWidth = cellSize * cellsHorizontalCount;
int unsigned windowHeight = cellSize * cellsVerticalCount;

int unsigned direction;
int unsigned currentLength = 4;

PointSnake s[cellsHorizontalCount * cellsVerticalCount];
Snake snake(100);
Fruits fruits[10];

const int unsigned DIRECTION_UP = 0;
const int unsigned DIRECTION_LEFT = 1;
const int unsigned DIRECTION_RIGHT = 2;
const int unsigned DIRECTION_DOWN = 3;

#pragma endregion

#pragma region game methods

void DrawSnake()
{
    glColor3f(0.4, 0.4, 0.8);
    for (int i = 0; i < currentLength; i++)
    {
        glRectf(snake.body[i].GetX() * cellSize,
            snake.body[i].GetY() * cellSize,
            (snake.body[i].GetX() + 0.9) * cellSize,
            (snake.body[i].GetY() + 0.9) * cellSize);
    }
    glColor3f(0.3, 0.3, 0.7);

    glRectf(snake.Head().GetX() * cellSize,
        snake.Head().GetY() * cellSize,
        (snake.Head().GetX() + 0.9) * cellSize,
        (snake.Head().GetY() + 0.9) * cellSize);
}

/*void HardMove() {
    //если заходим за границы справа - идем налево
    if (snake[0].GetX() > cellsHorizontalCount - 1) {
        direction = DIRECTION_LEFT;
    }

    //если заходим за границы слева - идем вправо
    else if (snake[0].GetX() < 0) {
        direction = DIRECTION_RIGHT;
    }

    //если заходим за границы сверху - идем вниз
    else if (snake[0].GetY() > cellsVerticalCount - 1) {
        direction = DIRECTION_DOWN;
    }

    //если заходим за границы снизу - идем вверх
    else if (snake[0].GetY() < 0) {
        direction = DIRECTION_UP;
    }
}*/

#pragma endregion

#pragma region base methods opengl

void Tick()
{
    snake.MoveBody(currentLength, direction, cellsHorizontalCount, cellsVerticalCount);

    //едим фрукт
    for (int i = 0; i < 10; i++) {
        if ((snake.Head().GetX() == fruits[i].x) && (snake.Head().GetY() == fruits[i].y))
        {
            currentLength++;
            fruits[i].New(cellsHorizontalCount, cellsVerticalCount, cellSize);
        }
    }

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