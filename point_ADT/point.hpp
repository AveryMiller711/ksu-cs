//File:     point.hpp
//
//Simple 2D point ADT
//Author: Avery Miller
//Date: 1/25/2021

//Include guards

#ifndef CS2_POINT_HPP_
#define CS2_POINT_HPP_

#include <iostream>

class point {
public:

    point(); //Default constructor
    point(double, double);

    double  getx        ();
    double  gety        ();
    void    setx        (double);
    void    sety        (double);
    point   operator+   (point);
    point   operator-   (point);
    point   operator*   (double);
    double  dist        (point);
    void    print       (std::iostream&);

private:
    double x, y;
};

std::ostream& operator<<(std::ostream&, point); //free function to get proper syntax of cout << a;
point operator*(double, point);

#endif