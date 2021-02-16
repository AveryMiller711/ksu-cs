//String.cpp
//
//Avery Miller
//String ADT
//02/10/2021

#include "string.hpp"

String::String() {
    str[0] = 0;
}

//String a('x');
String::String(char ch) {
    str[0] = ch;
    str[1] = 0;
}

//String a("abcd");
String::String(const char value[]) {
    int i = 0;
    while (value[i] != 0) {
        str[i] = value[i];
        ++i;
        if (i == capacity()) break;
    }
    str[i] = 0;
}

//a.length()
int String::length() const {
    int len = 0;
    while (str[len] != 0) ++len;
    return len;
}

char String::operator[](int i) const {
    assert((i < 0) || (i > length()));
    return str[i];
}

char& String::operator[](int i) {
    assert((i < 0) || (i > length()));
    return str[i];
}

String String::operator+(const String& rhs) const {
    String result(str);
    int offset = length();  //(*this).length()
    int i = 0;
    while (rhs.str[i] != 0) {
        if (offset+i == capacity()) break;
        result.str[offset+i] = rhs.str[i];
        ++i;
    }
    result.str[offset+i] = 0;
    return result;

}

String operator+(char lhs, const String& rhs) { return String(lhs) + rhs; }

String operator+(const char lhs[], const String& rhs) { return String(lhs) + rhs; }

String& String::operator+=(const String& rhs) {
    int offset = length();
    int i = 0;
    while (rhs.str[i] != 0) {
        if (offset+i == capacity()) break;
        str[offset+i] = rhs.str[i];
        ++i;
    }
    str[offset+i] = 0;
    return *this;
}

//"abc" == "abc"    i=0 1 2 3   true
//"abc" == "ab"     i=0 1 2     false
//"abc" == "abcd"   i=0 1 2 3   false
//"" == ""          i=0         true

//a == b
//a.length == b.length - a == b up to the length
//a.length != b.length - a == b, a != b
bool String::operator==(const String& rhs) const {
    int i = 0;
    while ((str[i] != 0) && (rhs.str[i] != 0) && (str[i] == rhs.str[i])) ++i;
    return str[i] == rhs.str[i];
}

bool operator==(char lhs, const String& rhs) { return String(lhs) == rhs; }
bool operator==(const char lhs[], const String& rhs) { return String(lhs) == rhs; }

//abc < abcd        i=0 1 2 3   true
//abcd < abce       i=0 1 2 3   true
//a < aa
//abc !< aaa        i=0 1       false
//"abc" !< "abc"    i=0 1 2 3   false
//"a" < "A"
bool String::operator<(const String& rhs) const{
    int i = 0;
    while ((str[i] != 0) && (rhs.str[i] != 0) && (str[i] == rhs.str[i])) ++i;
    return str[i] < rhs.str[i];
}

bool operator<(char lhs, const String& rhs) { return String(lhs) < rhs; }
bool operator<(const char lhs[], const String& rhs) { return String(lhs) < rhs; }

bool operator!=(const String& lhs, const String& rhs) { return !(lhs == rhs); }
bool operator>=(const String& lhs, const String& rhs) { return !(lhs < rhs); }
bool operator>(const String& lhs, const String& rhs) { return !(lhs <= rhs); }
bool operator<=(const String& lhs, const String& rhs) { return !(lhs < rhs) || (lhs == rhs); }


std::ostream& operator<<(std::ostream& out, const String& rhs) {
    out << rhs.str;
    return out;
}

std::istream& operator>>(std::istream& in, String& rhs) {
    char temp[STRING_SIZE];
    temp[0] = 0;
    if (!in.eof()) in >> temp;
    rhs = String(temp);
    return in;
}

// REQUIRES: 0<=start<length() && 0<=end<length() && start<=end
// ENSURES:  RetVal = String(str[start, ..., end])
//
String String::substr(int start, int end) const {
    String result;
    if(start < 0) start = 0;
    if(end >= length()) end = length() -1;
    if(end < 0) return result;
    if(start >= length()) return result;
    if(start > end) return result;

    int j = 0;
    for(int i = start; i <= end; ++i) {
        result.str[j] = str[i];
        ++j;
    }
    result.str[j] = 0;
    return result;
}
// TESTS:       0123456
// String a("abcdefg");
// a.substr(1,3);       start=1,    end=3,     j=0 1 2 3     i=1 2 3 4
// result = "bcd"

// a.substr(0,0);
// a.substr(0,length()-1);

// REQUIRES: 0 <= start < length()
// ENSURES: RetVal == i where str[i] == ch, i == [start, ..., length()-1]
//          RetVal == -1 if ch is not in str
int String::findchar(int start, char ch) const {
    if(start > length() - 1) return -1;
    int i = start;
    if(start < 0) i = 0;
    while((str[i] != 0) && (str[i] != ch)) ++i;
    if(str[i] == ch) return i;  // Found it
    else return -1;             // Didn't find it
}
// TESTS:
// a, e, x, c
// start = 0, 2, 4
// c 0 i=0, 1 2