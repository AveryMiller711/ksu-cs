#include "stack.hpp"
#include "./string_ADT/string.hpp"
#include <iostream>
#include <string>

String infix_to_postfix(const char expr[]) {
    stack<String> S;
    int i = 0;
    String left, right, op, token;

    while(expr[i] != 0) {
        token = expr[i];
        if(token == ")") {
            right = S.pop();
            op = S.pop();
            left = S.pop();
            S.push(left + right + op);
        } else if (token != "(") S.push(token);
        ++i;
    }
    return S.pop();
}

String infix_to_prefix(const char expr[]) {
    return expr;
}
