//

#include "set.hpp"
#include <iostream>

int main(){
    set a, b;
    set c(3);
    set d(2, 30);
    set e = {2, 3, 4, 5};

    int x = e.card();

    a = c * e; //c.operator*(3)

    std::cout << "a= " << a << std::endl;
    std::cout << "b= " << b << std::endl;

    if (c[3]) std::cout << "3 is an element c" << std::endl;

    return 0;
}