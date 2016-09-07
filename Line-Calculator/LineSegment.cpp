/****************************************************************
 * Author: Jacob Wilson
 * Date: 7/23/15
 * Description: Assignment 5 (Graphing calculator). Two classes
 * are used to create and measure attributes of a line: distance
 * between two points, length of a line created by two points,
 * and slope of a line created by two points.
 ****************************************************************/

#include "LineSegment.hpp"  // reference to appropriate header file
// Point.hpp already referenced in LineSegment.hpp, no reference needed here


// CONSTRUCTOR which uses two Point objects as arguments to initialize and set
// both End1 and End2, which each represent endpoints of a line.

LineSegment::LineSegment(Point p1, Point p2)
{
    setEnd1(p1);
    setEnd2(p2);
}


// SET functions

void LineSegment::setEnd1(Point p1)     // accepts a Point object and sets to End1
{
    End1 = p1;
}
void LineSegment::setEnd2(Point p2)     // accepts a Point object and sets to End2
{
    End2 = p2;
}


// GET functions

Point LineSegment::getEnd1()            // returns End1 as a Point object
{
    return End1;
}

Point LineSegment::getEnd2()            // returns End2 as a Point object
{
    return End2;
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                              length                                       *
 * This function receives two Point objects as arguments and uses them in    *
 * the Point class distanceTo function. The calculated distance is returned  *
 * as a double.                                                              *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

double LineSegment::length()
{
    double distance = End1.distanceTo(End2);
    
    return distance;
}


/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                              slope                                        *
 * This function receives two Point objects as arguments and utlizes the     *
 * Point class get functions to enter the X/Y coordinates into a standard    *
 * formula which will calculate the slope of the line created by the two     *
 * points.                                                                   *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

double LineSegment::slope()
{
    double lineSlope = (End2.getYCoord() - End1.getYCoord()) / (End2.getXCoord() - End1.getXCoord());
    
    return lineSlope;
}
