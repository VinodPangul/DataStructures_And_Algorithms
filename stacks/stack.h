//
// Created by vpangul on 2019-04-27.
//

#ifndef STACKS_STACK_H
#define STACKS_STACK_H

#include <iostream>
using namespace std;

template <class Type>
struct nodeType{
    Type info;
    nodeType<Type> *next;
};

template <class Type>
class linkedStackType{
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

private:
    nodeType<Type> *stackTop;
    void copyStack(const linkedStack<Type> &other);

};
#endif //STACKS_STACK_H
