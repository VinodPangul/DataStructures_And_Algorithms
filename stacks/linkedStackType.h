//
// Created by vpangul on 2019-04-27.
//

#ifndef STACKS_LINKEDSTACKTYPE_H
#define STACKS_LINKEDSTACKTYPE_H


#include <iostream>
using namespace std;

template <class Type>
struct nodeType{
    Type info;
    nodeType<Type> *next;
};

template <class Type>
class linkedStackType{
public:
    const linkedStackType<Type>& operator=(const linkedStackType<Type>& other );

    void initializeStack();
    bool isEmptyStack();
    bool isFullStack();

    void push(const Type&);
    void pop();
    Type top();

    linkedStackType();
    ~linkedStackType();
    linkedStackType(const linkedStackType<Type> &other);

    bool isEqual(const linkedStackType<Type>& other);

    void reverseStack(linkedStackType<Type>& other);

private:
    nodeType<Type> *stackTop;
    void copyStack(const linkedStackType<Type> &other);

};
#endif //STACKS_LINKEDSTACKTYPE_H
