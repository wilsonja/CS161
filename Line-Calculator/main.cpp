#include "LineSegment.hpp"
#include <iostream>

int main()
{
    Point p1(-2, 0.0);
    Point p2(1.5, 4.0);
    Point p3(-1.5, 0.0);
    Point p6(2.0, 4.0);
    Point p7(1.0, 8.0);
    double dist = p6.distanceTo(p2);
    
    std::cout << dist << std::endl;
    
    Point p4(4.3, 8.52);
    Point p5(4.3, 7.52);
    LineSegment ls1(p4, p5);
    double length = ls1.length();
    double slope = ls1.slope();
    
    std::cout << length << std::endl;
    std::cout << slope << std::endl;
}
