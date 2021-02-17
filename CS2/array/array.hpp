// Array.hpp
// Avery Miller
// A simple dynamically allocated array
// 02/17/2021

#ifndef CS2_ARRAY_H
#define CS2_ARRAY_H

#include <iostream>
#include <cassert>

//
// CLAS INV:    ptr->int[cap]
//
class Darray {
public:
        Darray  () : ptr(0), cap(0) {};
        Darray  (int);
        Darray  (const Darray&);                        // Copy ctor    (ctor)
        ~Darray ();                                     // Destructor   (dtor)

    void    swap        (Darray&);                      // Constant time swap
    Darray& operator=   (Darray);                       // Copy semantics assignment

    Darray& operator=   (const Darray&);                // Another version of assignment

    int     capacity    ()      const { return cap; }
    int     operator[]  (int)   const;                  // Accessor
    int&    operator[]  (int);                          // Modify and access
    void    resize      (int);

private:
    int *ptr;
    int cap;
};

#endif