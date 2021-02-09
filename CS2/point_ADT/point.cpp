//
//
//

#include "point.hpp"

point::point() {
    x = 0.0;
    y = 0.0;
}

point::point(double nx, double ny) {
    x = nx;
    y = ny;
}

double point::getx() {
    return x;
}

double point::gety() { return y; }

void point::setx(double nx) { x = nx; }

point point::operator+(point rhs) {
    point result;
    result.x = x + rhs.x;
    result.y = y + rhs.y;

    return result;
}

point point::operator-(point rhs) {
    point result;
    result.x = x - rhs.x;
    result.y = y - rhs.y;

    return result;
}

point point::operator*(double rhs) {
    return point(x * rhs, y * rhs);
}

point operator*(double lhs, point rhs) { return rhs * lhs; }

double point::dist(point rhs) {
    double result = 0;
    return result;
}

void point::print(std::ostream& out) {
    out << "(" << x << ", " << y << ")";
}

std::ostream& operator<<(std::ostream& out, point rhs) {
    out << "(" << rhs.getx() << ", " << rhs.gety() << ")";
    return out;
}