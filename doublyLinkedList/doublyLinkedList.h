//
// Created by vpangul on 2019-04-12.
//

#ifndef DOUBLYLINKEDLIST_DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_DOUBLYLINKEDLIST_H

#include <iostream>
using namespace std;

template <class Type>
struct nodeType{
    Type info;
    nodeType<Type> *next;
    nodeType<Type> *back;
};


template <class Type>
class doublyLinkedList{
public:
    doublyLinkedList<Type>& operator=(const doublyLinkedList<Type>& other);

    bool isEmpty();
    Type length();
    void print();

    void insert(Type& elem);
    bool search(Type& elem);
    void deleteElem(Type& elem);

    doublyLinkedList();
    ~doublyLinkedList();
protected:
    int count;
    nodeType<Type> *first;
    nodeType<Type> *last;
private:
    void copyList(const doublyLinkedList<Type>& other);

};
#endif //DOUBLYLINKEDLIST_DOUBLYLINKEDLIST_H
