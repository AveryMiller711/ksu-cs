// bigint.cpp
//
// Avery Miller
// 02/07/2021

#include "bigint.hpp"

void bigint::zero_init() {
    for (int i = 0; i < CAPACITY; ++i) {
        bigintArray[i] = 0;
    }
}

bigint::bigint() {
    zero_init();
}

bigint::bigint(int num) {
    zero_init();
    for (int i = 0; i < CAPACITY; ++i) {
        bigintArray[i] = num % 10;
        num /= 10;
    }
}

bigint::bigint(char num[]) {
    zero_init();

    int strSize = 0;
    while(num[strSize] != 0) {
        ++strSize;
    }

    int strIndex = strSize - 1;

    for(int i = 0; i < strSize; ++i) {
        bigintArray[i] = num[strIndex] - '0';
        --strIndex;
    }
}

void bigint::debugPrint(std::ostream& out) const {
    for (int i = CAPACITY-1; i == 0; --i) {
        out << bigintArray[i] << " | ";
  }
}

bool bigint::operator==(const bigint &rhs) const {
  for(int i = 0; i < CAPACITY; ++i){
    if(bigintArray[i] != rhs.bigintArray[i])
      return false;
  }
  return true;
}

std::ostream& operator<<(std::ostream& out, const bigint& rhs) {
    int size = CAPACITY -1;
    int count = 0;
    int i;
    for(i = size; rhs.bigintArray[i] == 0; --i){}

    for(int j = i; j > 0; --j){
        out << rhs.bigintArray[j];
        ++count;
    }

    out << rhs.bigintArray[0];
    ++count;

    if(count == 80){
        count = 0;
        std::cout << std::endl;
    }
    return out;
}