#pragma once
#include  <GL/glut.h>
#include "Snake.h"
/*!
\file
\brief Header file describing the StaticDrawService class

This file contains the definition of the StaticDrawService class and the methods contained in it
*/

/*!
    \brief A class that provides methods for drawing fixed elements
*/
static class StaticDrawService
{
public:
	/*!
    Function for drawing the playing field
    \param[in] width Window width
    \param[in] height Window height
    \param[in] cellSize Cell size
    */
    static void DrawField(int width, int height, int cellSize);
};

