// bigint.hpp
//
// Avery Miller
// 02/07/2021

#ifndef BIGINT_HPP
#define BIGINT_HPP

#include <iostream>

const int CAPACITY = 200;

class bigint {
public:
        bigint();   // Default Constructor
        bigint(int);
        bigint(char[]);
    
    void zero_init  ();
    void debugPrint (std::ostream&) const;

    bool operator== (const bigint&) const;

    friend std::ostream& operator<<(std::ostream&, const bigint&);
private:
    int bigintArray[CAPACITY];
};

#endif
