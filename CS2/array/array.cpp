// Array.cpp
// Avery Miller
// A simple dynamically allocated array
// 02/17/2021

#include "array.hpp"

// REQUIRES: n >= 0
Darray::Darray(int n) {
    assert(n >= 0);
    cap = n;
    ptr = new int[cap];
}

// Copy Constructor
Darray::Darray(const Darray &actual) {
    cap = actual.cap;
    ptr = new int[cap];
    for(int i = 0; i < cap; ++i) {
        ptr[i] = actual.ptr[i];
    }
}

// Destructor
// No parameters
// Can not call exit() - no assert()
Darray::~Darray() {
    delete[] ptr;
}

Darray& Darray::operator=(const Darray& rhs) {
    if(ptr != rhs.ptr) {
    // Clean up this
        delete[] ptr;

    // Allocate new memory for this
        cap = rhs.cap;
        ptr = new int[cap];

    // Copy rhs into this
        for(int i = 0; i < cap; ++i) {
            ptr[i] = rhs.ptr[i];
        }
    }
    return *this;
}

Darray& Darray::operator=(Darray rhs) {
    swap(rhs);
    return *this;
}

void Darray::swap(Darray& rhs) {
    int tcap = rhs.cap;
    rhs.cap = cap;
    cap = tcap;
    int *temp = rhs.ptr;
    rhs.ptr = ptr;
    ptr = temp;
}

// REQUIRES: 0 <= i < cap
int Darray::operator[](int i) const {
    assert(i >= 0 && i < cap);
    return ptr[i];
}

// REQUIRES: 0 <= i < cap
int& Darray::operator[](int i) {
    assert(i >= 0 && i < cap);
    return ptr[i];
}

// REQUIRES: 0 <= newCapacity
void Darray::resize(int newCapacity) {
    // Allocate new memory
    int smaller = cap;
    if(smaller > newCapacity) smaller = newCapacity;

    int *tmp = new int[newCapacity];
    
    // Copy old into new (smaller or larger)
    for(int i = 0; i < smaller; ++i) tmp[i] = ptr[i];
    cap = newCapacity;

    // Clean up old memory
    delete[] ptr;
    ptr = tmp;
}