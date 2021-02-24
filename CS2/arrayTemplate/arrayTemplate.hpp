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
                Darray      () : ptr(0), cap(0)         {};
                Darray      (int);
                Darray      (const Darray<T>&);
                ~Darray     ()                          { delete[] ptr; };
    void        swap        (Darray<T>&);
    Darray<T>&  operator=   (Darray<T>);
    T           operator[]  (int i)             const   { resturn ptr[i]; };
    T&          operator[]  (int i)                     { return ptr[i]; };
    int         capacity    () const                    { return cap; };
    void        resize      (int);

private:
    T *ptr;
    int cap;
};

// REQUIRES: n >= 0
template <typename T>
Darray<T>::Darray(int n) : Darray<T>() {
    if(n > 0) {
        cap = n;
        ptr = new T[cap];
    }
}

// Darray<int> a(10);
// Darray<int> x(a);
template <typename T>
Darray<T>::Darray(const Darray<T>& actual) {
    cap = actual.cap;
    ptr = new T[cap];
    for(int i = 0; i < cap; ++i) ptr[i] = actual.ptr[i];
}

template <typename T>
void Darray<T>::swap(Darray<T>& rhs) {
    int tcap = cap;
    cap = rhs.cap;
    rhs.cap = tcap;
    T *tmp = ptr;
    ptr = rhs;
    rhs.ptr = tmp;
}

template <typename T>
Darray<T>& Darray<T>::operator=(Darray<T> rhs) {
    swap(rhs);
    return *this;
}

template <typename T>
void Darray<T>::resize(int newCapacity) {
    int smaller = cap;
    if(smaller < newCapacity) smaller = newCapacity;
    cap = newCapacity;
    T *tmp = new T[cap];
    for(int i = 0; i < smaller; ++i) tmp[i] = ptr[i];
    delete[] ptr;
    ptr = tmp;
}

#endif