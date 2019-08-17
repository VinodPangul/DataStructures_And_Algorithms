//
// Created by vpangul on 2019-04-27.
//

#include <iostream>
#include "assert.h"

#include "linkedStackType.h"
using namespace std;

template <class Type>
linkedStackType<Type>::linkedStackType() {
    stackTop = NULL;
}

template <class Type>
bool linkedStackType<Type>::isEmptyStack() {
    if(!stackTop) return true;
    else return false;
}

template <class Type>
bool linkedStackType<Type>::isFullStack() {
    return false;
}


template <class Type>
void linkedStackType<Type>::push(const Type& newElem) {
    nodeType<Type> *newNode = new nodeType<Type>;
    newNode->info = newElem;
    newNode->next = stackTop;
    stackTop = newNode;
}

template <class Type>
void linkedStackType<Type>::pop() {
    if(!stackTop) cout<<"Empty Stack";

    nodeType<Type> *tmp = stackTop;
    stackTop = stackTop->next;
    delete tmp;
}

template <class Type>
Type linkedStackType<Type>::top() {
    if(stackTop) return stackTop->info;
    else assert("Stack is empty");
}

template <class Type>
 void linkedStackType<Type>::copyStack(const linkedStackType<Type> &other) {
//        while(stackTop){
//            nodeType<Type> *tmp= stackTop;
//            stackTop = stackTop->next;
//            delete tmp;
//        }

        if(stackTop) initializeStack();

        if(!other.stackTop)
            stackTop=NULL;
        else {
            nodeType<Type> *current = other.stackTop;
            stackTop = new nodeType<Type>;
            stackTop->info = current->info;
            stackTop->next = NULL;

            current = current->next;
            nodeType<Type> *last=stackTop;

            while (current) {
                nodeType<Type> *newNode = new nodeType<Type>;
                newNode->info = current->info;
                newNode->next = NULL;
                last->next = newNode;
                last = newNode;
                current = current->next;
            }
        }
}


template <class Type>
const linkedStackType<Type> & linkedStackType<Type>::operator=(const linkedStackType<Type> &other) {
    if(this != &other){
        copyStack(other);
    }
    return *this;
}

template <class Type>
linkedStackType<Type>::~linkedStackType() {
    initializeStack();
}

template <class Type>
void linkedStackType<Type>::initializeStack() {

    nodeType<Type> *tmp;

    while (stackTop) {
        tmp = stackTop;
        stackTop = stackTop->next;
        delete tmp;
    }
    stackTop = NULL;
}

template <class Type>
linkedStackType<Type>::linkedStackType(const linkedStackType<Type> &other) {
    stackTop = NULL;
    copyStack(other);
}

template <class Type>
bool linkedStackType<Type>::isEqual(const linkedStackType<Type> &other) {
    if(this == &other) return true;

    nodeType<Type> *current=stackTop;
    nodeType<Type> *otherCurrent=other.stackTop;

    while(current && otherCurrent){
        if(current->info != otherCurrent->info) return false;

        current = current->next;
        otherCurrent = otherCurrent->next;
    }

    if(current || otherCurrent) return false;

    cout<<"Stacks are equal"<<endl;
    return true;
}

template <class Type>
void linkedStackType<Type>::reverseStack( linkedStackType<Type> &other) {
//    if(!stackTop) {
//        other.stackTop = NULL;
//        return;
//    }

    nodeType<Type> *current=other.stackTop, *prev=NULL;
    while(current){
        push(current->info);
        //prev=current;
        current=current->next;
    }

   // stackTop=prev;

}
