//
// Created by vpangul on 2019-04-09.
//

#ifndef UNORDEREDLINKEDLIST_UNORDEREDLINKEDLIST_H
#define UNORDEREDLINKEDLIST_UNORDEREDLINKEDLIST_H

#include <iostream>
#include "LinkedListType.h"

using namespace std;

template <class Type>
class unorderedLinkedList: public LinkedListType<Type>{
public:
    void insertFirst(Type& node);
};
#endif //UNORDEREDLINKEDLIST_UNORDEREDLINKEDLIST_H
