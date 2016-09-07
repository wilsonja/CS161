/****************************************************************
 * Author: Jacob Wilson
 * Date: 7/23/15
 * Description: Assignment 5 (Graphing calculator). Two classes
 * are used to create and measure attributes of a line: distance
 * between two points, length of a line created by two points,
 * and slope of a line created by two points.
 ****************************************************************/

#ifndef POINT_HPP
#define POINT_HPP

// The Point class consists of objects with two double variables representing X/Y coordinates,
// and a function which calculates the distance between two points.

class Point
{
private:
    double XCoord;
    double YCoord;
    
public:
    Point();                               // default constructor
    Point(double, double);                 // constructor which accepts two double arguments
    void setXCoord(double);                // SET function for X coordinate
    void setYCoord(double);                // SET function for Y coordinate
    double getXCoord();                    // GET function for X cooridinate
    double getYCoord();                    // GET function for Y coordinate
    double distanceTo(const Point &);      // function calculates distance between two points
};

#endif
