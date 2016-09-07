/****************************************************************
 * Author: Jacob Wilson
 * Date: 7/23/15
 * Description: Assignment 5 (Graphing calculator). Two classes
 * are used to create and measure attributes of a line: distance
 * between two points, length of a line created by two points,
 * and slope of a line created by two points.
 ****************************************************************/

#ifndef LINESEGMENT_HPP
#define LINESEGMENT_HPP
#include "Point.hpp"    // require this reference due to the use of Point class objects

// The LineSegment class consists of two Point class objects representing
// endpoints on a line, a function which calculates the length of a line
// when given two points, and a function which calculates the slope of a
// line created by two points.

class LineSegment
{
private:
    Point End1;
    Point End2;
  
public:
    LineSegment(Point, Point);      // constructor accepts two Point arguments
    void setEnd1(Point);            // SET function for first endpoint
    void setEnd2(Point);            // SET function for second endpoint
    Point getEnd1();                // GET function for first endpoint
    Point getEnd2();                // GET function for second endpoint
    double length();    // calculates the length of a line between two points
    double slope();     // calculate the slope of a line created by two points
};

#endif
