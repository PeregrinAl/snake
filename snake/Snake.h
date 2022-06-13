#pragma once
#include "PointSnake.h"
/*!
\file
\brief Header file describing the Snake class

This file contains the definition of the Snake class, the methods and variables contained in it, and direction constants
*/

const int unsigned DIRECTION_UP = 0; ///< Up direction constant
const int unsigned DIRECTION_LEFT = 1; ///< Left direction constant
const int unsigned DIRECTION_RIGHT = 2; ///< Right direction constant
const int unsigned DIRECTION_DOWN = 3; ///< Down direction constant

/*!
	\brief A class that generates the Snake object

	The class is designed to store the body of the snake and manage it
*/
class Snake
{
public:
	/*!
    Base constructor that sets x and y coordinates of the Head by default
    */
	Snake();

	/*!
    Base destuctor that clears memor
    */
	~Snake();

	/*!
    Constructor that gets the length of the snake and creates PointSnake array
    */
	Snake(const int length);

	/*!
    A function that allows you to get the head of the snake
	\return PointSnake object, which is the head of the snake
    */
	PointSnake head();

	/*!
	Redefining the [] operator, allowing you to get the snake point by referring to the index
	\param[in] i index
	\return PointSnake value
	*/
	PointSnake& operator[](int i);

	/*!
    Function used to move the snake in a given direction
    \param[in] dir direction of movement
	\param[in] cellsHorizontalCount number of cells horizontally
	\param[in] cellsVerticalCount number of cells vertically
    */
	void moveBody(int dir, int cellsHorizontalCount, int cellsVerticalCount);

	/*!
    Function that changes the length of the snake
    */
	void newLenght();

	PointSnake* body = new PointSnake; ///< Pointer to an array containing the body of the snake

	int currentLength = 4; ///< Current length of the snake

private:
	PointSnake snakeHead;
	bool isAlive = true;
	inline void moveHead(int direction, int cellsHorizontalCount, int cellsVerticalCount);
};

