// fileio.cpp
// Implements file input and output in C++
// Avery Miller
// 02/11/2021

#include <iostream>
#include <fstream>

void fileIORead () {
    // Open the file
    std::ifstream file ("fileio-text.txt");

    // Check to see if file is open
    if (!file.is_open()) {
        std::cout << "Unable to open file\n";
    }
    else {
        char ch;
        while(file >> ch) {
            std::cout << ch;
        }
    }

    // Close file
    std::cout << '\n';
    file.close();
}

void fileIOAdd () {
    // Open the file
    std::ifstream file ("fileio-data-1.txt");

    // Check to see if file is open
    if (!file.is_open()) {
        std::cout << "Unable to open file\n";
    }
    else {
        int lhs, rhs;
        char ch;
        if(!file.eof())
            file >> lhs;
        if(!file.eof())
            file.get(ch);
        if(!file.eof())
            file >> rhs;
        std::cout << lhs + rhs << std::endl;
    }

    // Close file
    std::cout << '\n';
    file.close();
}

int main () {
    fileIOAdd();
    fileIORead();
    return 0;
}