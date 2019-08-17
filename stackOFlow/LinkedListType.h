//
// Created by vpangul on 2019-04-08.
//

#ifndef LINKEDLISTTYPE_LINKEDLISTTYPE_H
#define LINKEDLISTTYPE_LINKEDLISTTYPE_H

#include <iostream>
using namespace std;

template <class Type>
struct nodeType
{
    int val;
    nodeType<Type> *link;
};

template <class Type>
class LinkedListType{
public:

    virtual void insertFirst(Type& node)=0;

    LinkedListType();
    ~LinkedListType();
    void destroyList();
protected:
    int count;
    nodeType<Type> *first;
    nodeType<Type> *last;
};
#endif //LINKEDLISTTYPE_LINKEDLISTTYPE_H
