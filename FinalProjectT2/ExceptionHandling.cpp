#ifndef FILENOTFOUNDEXCEPTION_H
#define FILENOTFOUNDEXCEPTION_H

//#pragma once
#include <iostream>
using namespace std;

class NotFoundException : public exception {
public:
    const char* what() const throw() {
        return "not found\n";
    }
};

#endif