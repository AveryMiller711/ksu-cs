//
//
//
//

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