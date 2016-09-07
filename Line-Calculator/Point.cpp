/****************************************************************
 * Author: Jacob Wilson
 * Date: 7/23/15
 * Description: Assignment 5 (Graphing calculator). Two classes
 * are used to create and measure attributes of a line: distance
 * between two points, length of a line created by two points,
 * and slope of a line created by two points.
 ****************************************************************/

#include "Point.hpp"    // reference to appropriate header file
#include <cmath>        // required for square root and pow functions


// DEFAULT CONSTRUCTOR initializes and sets both coordinates for Point
// objects to zero using the set functions.

Point::Point()
{
    setXCoord(0);
    setYCoord(0);
}


// A second CONSTRUCTOR accepts two doubles as arguments and sets them
// to the X and Y coordinates using the set functions.

Point::Point(double x, double y)
{
    setXCoord(x);
    setYCoord(y);
}


// SET functions

void Point::setXCoord(double x)     // accepts a double and sets to the X coordinate
{   XCoord = x;  }

void Point::setYCoord(double y)     // accepts a double and sets to the Y coordinate
{   YCoord = y;  }


// GET functions

double Point::getXCoord()           // returns the X coordinate as a double
{   return XCoord;  }

double Point::getYCoord()           // returns the Y coordinate as a double
{   return YCoord;  }


/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                              distanceTo                                   *
 * This function receives a Point object by constant reference. The function *
 * accessess the X/Y coordinates of the first object directly, and accessess *
 * the X/Y coordinates of the passed object using the dot operator. It then  *
 * calculates the distance between these points using the standard distance  *
 * formula and returns this value as a double.                               *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

double Point::distanceTo(const Point &p2)
{
    double distance = sqrt(pow(( XCoord - p2.XCoord ), 2.0) + pow(( YCoord - p2.YCoord ), 2.0));
    
    return distance;
}
