//
//
//

#include <iostream>
#include <cassert>

#ifndef CS2_STRING_HPP
#define CS2_STRING_HPP

const int STRING_SIZE = 256;    //String capacity+1 (for null terminator)

//CLASS INV:    0 <= length() <= capacity() &&
//              capacity() == STRING_SIZE-1 &&
//              str[length()] ==0
//              Can only access str[0, ... , length()-1]

class String {
public:
            String();
            String(char);
            String(const char[]);
    int     capacity() const { return STRING_SIZE-1; }
    int     length() const;
    char    operator[](int) const;
    char&   operator[](int);
    String  operator+(const String&) const;
    String& operator+=(const String&);
    bool    operator==(const String&) const;
    bool    operator<(const String&) const;
    String  substr(int, int) const;
    int     findchar(int, char) const;

    friend  std::ostream& operator<<(std::ostream&, const String&);

private:
    char str[STRING_SIZE];
};

std::istream& operator>>(std::istream&, String&);
String  operator+   (char,          const String&);
String  operator+   (const char[],  const String&);
bool    operator==  (char,          const String&);
bool    operator==  (const char[],  const String&);
bool    operator<   (char,          const String&);
bool    operator<   (const char[],  const String&);
bool    operator!=  (const String&, const String&);
bool    operator>   (const String&, const String&);
bool    operator>=  (const String&, const String&);
bool    operator<=  (const String&, const String&);

#endif