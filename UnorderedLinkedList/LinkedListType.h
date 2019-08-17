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

    LinkedListType<Type>& operator=(LinkedListType<Type>& other);
    bool isEmptyList();
    int getLength();
    void print();
    void destroyList();
    void initializeList();
    Type front();
    Type back();

    //copyConstructor

    virtual bool search(Type& node)=0;
    virtual void insertFirst(Type& node)=0;
    virtual void insertLast(Type& node)=0;
    virtual void deleteNode(Type& node)=0;

    LinkedListType();
    ~LinkedListType();
protected:
    int count;
    nodeType<Type> *first;
    nodeType<Type> *last;

private:
    void copyList(LinkedListType<Type>& other);
};
#endif //LINKEDLISTTYPE_LINKEDLISTTYPE_H
