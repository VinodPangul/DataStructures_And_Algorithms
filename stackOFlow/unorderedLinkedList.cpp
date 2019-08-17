//
// Created by vpangul on 2019-04-09.
//

#include <iostream>
#include "unorderedLinkedList.h"

using  namespace std;

template <class Type>
void unorderedLinkedList<Type>::insertFirst(Type& node) {
    nodeType<Type> *newNode= new nodeType<Type>;
    if(newNode == NULL)
        assert("Unable to allocate node to insert");
    newNode->val=node;
    newNode->link=first;
    first=newNode;
    count++;
}
