//
// Created by vpangul on 2019-04-09.
//

#ifndef UNORDEREDLINKEDLIST_UNORDEREDLINKEDLIST_H
#define UNORDEREDLINKEDLIST_UNORDEREDLINKEDLIST_H

#include <iostream>
#include "LinkedListType.h"
#include "LinkedListType.cpp"

using namespace std;

template <class Type>
class unorderedLinkedList: public LinkedListType<Type>{
public:
    bool search(Type& node);
    void insertFirst(Type& node);
    void insertLast(Type& node);
    void deleteNode(Type& node);
    void oddEvenList();

};
#endif //UNORDEREDLINKEDLIST_UNORDEREDLINKEDLIST_H
