#pragma once
#include <windows.h>
#include <gl/GL.h>
#include <stdlib.h>
#include <math.h>
/*!
\file
\brief Header file describing the Fruits class

This file contains the definition of the Fruits class, the methods and variables contained in it
*/

/*!
    \brief A class that generates the fruit objects

   The class is necessary to form a fruit that has its own coordinates and methods
*/
class Fruits
{
public:
    int y; ///< Y coordinate of the current fruit
    int x; ///< X coordinate of the current fruit

    /*!
    Function to generate new fruit coordinates
    \param[in] cellsHorizontalCount number of cells horizontally
    \param[in] cellsVerticalCount number of cells vertically
    */
    void newFruit(int cellsHorizontalCount, int cellsVerticalCount);

    /*!
    Function for drawing fruit on the screen
    \param[in] scale the size of the cell in which the fruit will be drawn
    */
    void drawFruit(int scale);
};

