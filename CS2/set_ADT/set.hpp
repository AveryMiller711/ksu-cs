//File:     set.hpp
//
//Simple set ADT
//Author: Avery Miller
//Date: 2/3/2021

#ifndef CS2_SET_HPP
#define CS2_SET_HPP

#include <iostream>
#include <initializer_list>

const int domain = 6400;

class set{
public:
        set();
        set(int);
        set(int, int);
        set(std::initializer_list<int>);

    int  card()            const;
    bool operator[] (int)  const;
    set  operator+  (const set&)  const;
    set  operator*  (const set&)  const;
    set  operator-  (const set&)  const;
    bool operator== (const set&)  const;
    bool operator<= (const set&)  const;

private:
    bool element[domain];
};

set  operator+ (int, const set&);
set  operator* (int, const set&);
set  operator- (int, const set&);
bool operator!=(const set&, const set&);
bool operator==(int, const set&);
bool operator<=(int, const set&);
bool operator< (const set&, const set&);
bool operator>=(const set&, const set&);
bool operator> (const set&, const set&);

std::ostream& operator<<(std::ostream&, const set&);
std::istream& operator>>(std::istream&, set&);

#endif