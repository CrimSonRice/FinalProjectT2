#pragma once
#include <iostream>
using namespace std;

template <typename T>
class DynamicArray {
private:
    int size;
    int max;
    T* arrayHolder;
public:
    //constructor
    DynamicArray() {
        this->size = 0;
        this->max = 5;
        this->arrayHolder = new T[5];
    }
    //destructor
    ~DynamicArray() {
        delete[] this->arrayHolder;
    }

    int getSize() {
        return this->size;
    }

    T& operator[](int i) {
        return this->arrayHolder[i];
    }

    void add(T n) {
        if (this->max < this->size + 1) {
            this->max *= 2;
            T* tmp = new T[this->max];
            for (size_t i = 0; i < this->size; i++) {
                tmp[i] = this->arrayHolder[i];
            }
            delete[] this->arrayHolder;
            this->arrayHolder = tmp;
            this->arrayHolder[this->size] = n;
            this->size += 1;
        }
        else {
            this->arrayHolder[this->size] = n;
            this->size += 1;
        }
    }



};