//
// Created by vpangul on 2019-04-06.
//

#ifndef SAFEARRAY_SAFEARRAY_H
#define SAFEARRAY_SAFEARRAY_H

#include "iostream"
using namespace std;

template <class elemType>
class safeArray{
    friend ostream& operator<<(ostream& obj, safeArray<elemType>& other);
    friend istream& operator>>(ostream& obj, safeArray<elemType>& other);
public:
    safeArray();
    safeArray(int rb);
    safeArray(int lb, int rb);
    ~safeArray();

    // Copy constructor
    safeArray(const safeArray<elemType>& other);

    // Overload asignment operator
    safeArray<elemType>& operator=(const safeArray<elemType>& other);
    int& operator[](int index);

    void print();

    bool operator!=(const safeArray<elemType>& other);
    bool operator==(const safeArray<elemType>& other);

private:
    int lowerb;
    int rightb;
    elemType* arr;

};


#endif //SAFEARRAY_SAFEARRAY_H
