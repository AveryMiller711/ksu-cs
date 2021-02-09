//
//
//
//

#include "set.hpp"

bool isValid(int x) {
    return (0 <= x) && (x < domain);
}

// set a;
set::set() {
    for (int i = 0; i < domain; ++i) {
        element[i] = false;
    }
}

//REQURES: 0 <= x < domain
//set a(2);
set::set(int x) : set() {    //Call default const first, then exe body
    if (isValid(x)) element[x] = true;
}

//set a(2, 3);
set::set(int x, int y) : set() {
    if (isValid(x)) element[x] = true;
    if (isValid(y)) element[y] = true;
}

//set a = {2, 3, 4, 7};
set::set(std::initializer_list<int> lst) : set() {
    for (int i : lst) {
        if (isValid(i)) element[i] = true;
    }
}

//a.card()
int set::card() const {
    int result = 0;
    for (int i=0; i<domain; ++i) {
        if (element[i]) ++result;
    }
    return result;
}

//if (a[4]) then 4 is in the set a
bool set::operator[](int i) const {
    if (isValid(i)) 
        return element[i];
    else
        return false;
}

//Union
set set::operator+(const set& rhs) const {
    set result;
    for (int i=0; i<domain; ++i) {
        result.element[i] = element[i] || rhs.element[i];
    }
    return result;
}

set operator+(int lhs, const set& rhs) { return set(lhs) + rhs; }

set set::operator*(const set& rhs) const {
    set result;
    for (int i=0; i<domain; ++i) {
        result.element[i] = element[i] && rhs.element[i];
    }
    return result;
}

set operator+(int lhs, const set& rhs) { return set(lhs) * rhs; }

bool set::operator==(const set& rhs) const {
    for (int i=0; i<domain; ++i) {
        if (element[i] != rhs.element[i]) return false;
    }
    return true;
}

bool operator==(int lhs, const set& rhs) { return set(lhs) == rhs; }
bool operator!=(const set& lhs, const set& rhs) { return !(lhs==rhs); }
bool operator<(const set& lhs, const set& rhs) { return lhs != rhs && lhs <= rhs; }

std::ostream& operator<<(std::ostream& out, const set& rhs) {
    bool printComma = true;
    out << "{";
    for (int i=0; i<domain; ++i) {
        if (rhs[i])  {
            if (printComma) out << ", ";
            out << i;
            printComma = true;
        }
    }
    out << "}";
    return out;
}