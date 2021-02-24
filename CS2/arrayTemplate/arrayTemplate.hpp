// arrayTemplate.hpp
// Avery Miller
// A Template version of dynamically allocated array
// 02/22/2021

#ifndef CS2_TARRAY_H_
#define CS2_TARRAY_H_

#include <cassert>

// CLASS INV:   ptr->T[cap]
// REQUIRES: assignable(T) && copyconstructable(T) && destructable(T)

template <typename T>
class Darray {
public:
    Darray() : ptr(0), cap(0) {};
    Darray(int);
    Darray(const Darray<T>&);
    ~Darray() { delete[] ptr; };
    void swap(Darray<T>&);
    Darray<T>& operator=(Darray<T>);
    T operator[](int i) const { resturn ptr[i]; };
    T& operator[](int i) { return ptr[i]; };
    int capacity() const { return cap; };
    void resize(int);

private:
    T *ptr;
    int cap;
};

template <typename T>
Darray<T>::Darray(int n) {
    
}

#endif