//
// Created by vpangul on 2019-04-11.
//

#ifndef ORDEREDLINKEDLIST_ORDEREDLINKEDLIST_H
#define ORDEREDLINKEDLIST_ORDEREDLINKEDLIST_H

#include <iostream>
#include "LinkedListType.h"
#include "LinkedListType.cpp"
using namespace std;

template <class Type>
class orderedLinkedList: public LinkedListType<Type>{
public:
    void insert(Type& elem);
    void deleteNode(Type& elem);
    bool search(Type& elem);
    void insertFirst(Type& node);
    void insertLast(Type& node);

    void divideMidList(orderedLinkedList<Type> &other);
    void mergeList(orderedLinkedList<Type> &list1, orderedLinkedList<Type>& list2);
private:

};
#endif //ORDEREDLINKEDLIST_ORDEREDLINKEDLIST_H
