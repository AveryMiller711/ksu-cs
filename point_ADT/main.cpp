//

#include <iostream>
#include "point.hpp"

int main() {
    point a;    //point a();
    point b(3, 5), c;

    c = point(1, 2);

    std::cout << a.getx();

    a.setx(5);

    c = a + b;
    c = a - b;

    double x = a.dist(b);

    a.print(std::cout);

    //ofstream file1("output.txt");

    //a.print(file1);

    return 0;
}