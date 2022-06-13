#pragma once
/*!
\file
\brief Header file describing the PointSnake class

This file contains the definition of the PointSnake class, the methods and variables contained in it
*/


/*!
	\brief A class that generates the objects that make up the snake's body

    The purpose of the class is to form a convenient representation of the snake within the playing field, divided into cells. Each
    part of the snake has coordinates.
*/
class PointSnake
{
public:
	/*!
	Base constructor that sets x and y coordinates by default
	*/
	PointSnake();
	/*!
	Constructor that gets X and Y coordinates
	\param[in] x X coordinate of the PointSnake object
	\param[in] y Y coordinate of the PointSnake object
	*/
	PointSnake(int x, int y);
	/*!
    A function that allows you to access the X coordinate of a point
	\return X coordinate of the current point
    */
	int getX();
	/*!
    A function that allows you to access the Y coordinate of a point
	\return Y coordinate of the current point
    */
	int getY();
	/*!
	A function that allows you to set a new value for the X coordinate
	\param[in] x new value of X coordinate of the PointSnake object
	*/
	void setX(int x);
	/*!
    A function that allows you to set a new value for the Y coordinate
	\param[in] y new value of Y coordinate of the PointSnake object
    */
	void setY(int y);
private:
	int xCoordinate; /// X coordinate
	int yCoordinate; /// Y coordinate
};

