#include <time.h>
#include <stdlib.h>
#include  <GL/glut.h>
#include "Fruits.h"
#include "PointSnake.h"
#include "Snake.h"
#include "StaticDrawService.h"
#include "PointSnake.h"
/*!
\file
\brief The file contains an entry point and some methods needed to update the screen, draw elements, and track keystrokes.
*/

#pragma region variables

const int cellsHorizontalCount = 30; ///< number of cells horizontally
const int cellsVerticalCount = 20; ///< number of cells vertically
const int cellSize = 30; ///< size of the cell

const int unsigned windowWidth = cellSize * cellsHorizontalCount; ///< window width
const int unsigned windowHeigth = cellSize * cellsVerticalCount; ///< window heigth

const int fruitsCount = 10; ///< size of the cell

int unsigned direction; ///< direction of movement

const int MAX_LENGTH = cellsHorizontalCount * cellsVerticalCount;
Snake snake(MAX_LENGTH); ///< snake object
Fruits fruits[fruitsCount]; ///< fruits array

#pragma endregion

#pragma region game methods

/*!
Snake drawing method
*/
void drawSnake()
    {
    double indent = 0.9;
    glColor3f(0.4, 0.4, 0.8);
    for (int i = 0; i < snake.currentLength; i++)
        {
        glRectf(snake.body[i].getX() * cellSize,
            snake.body[i].getY() * cellSize,
            (snake.body[i].getX() + indent) * cellSize,
            (snake.body[i].getY() + indent) * cellSize);
        }
    glColor3f(0.3, 0.3, 0.7);

    glRectf(snake.head().getX() * cellSize,
        snake.head().getY() * cellSize,
        (snake.head().getX() + indent) * cellSize,
        (snake.head().getY() + indent) * cellSize);
    }
#pragma endregion

#pragma region base methods opengl

/*!
This method describing what happens every time the screen is refreshed
*/
void tick()
    {
    snake.moveBody(direction, cellsHorizontalCount, cellsVerticalCount);

    for (int i = 0; i < fruitsCount; i++) 
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

/*!
Method that draws graphics on the screen
*/
void display() 
    {

    glClear(GL_COLOR_BUFFER_BIT);
    StaticDrawService::DrawField(windowWidth, windowHeigth, cellSize);
    drawSnake();

    for (int i = 0; i < fruitsCount; i++)
        {
        fruits[i].drawFruit(cellSize);
        }

    glFlush();
    glutSwapBuffers();
    }

/*
Method that captures keystrokes
param[in] key ASCII code of the pressed key
param[in] provide the position of the mouse cursor when a key is pressed, relative to the upper left corner of the window's client area
param[in] provide the position of the mouse cursor when a key is pressed, relative to the upper left corner of the window's client area
*/
void keyboardEvent(int key, int x, int y)
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

/*
Method that sets the timer for glutTimerFunc
*/
void timer(int = 0)
    {
    display();
    tick();
    glutTimerFunc(50, timer, 0);
    }

#pragma endregion

/*
Point of entry
*/
int main(int argc, char** argv) 
    {

    srand(time(0));

    for (int i = 0; i < fruitsCount; i++)
    {
        for (int j = 0; j < snake.currentLength; j++)
        {
            while (snake.body[j].getX() == fruits[i].x && snake.body[j].getY() == fruits[i].y)
            {
                fruits[i].newFruit(cellsHorizontalCount, cellsVerticalCount);
            }
        }
    }
    
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(windowWidth, windowHeigth);
    glutCreateWindow("RelaxSnake");
    glClearColor(0.8, 0.8, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, windowWidth, 0, windowHeigth);

    glutDisplayFunc(display);
    glutSpecialFunc(keyboardEvent);
    glutTimerFunc(50, timer, 0);

    glutMainLoop();
    }