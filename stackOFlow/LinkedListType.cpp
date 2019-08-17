//
// Created by vpangul on 2019-04-08.
//
#include <iostream>
#include "LinkedListType.h"

using namespace std;

template <class Type>
void LinkedListType<Type>::destroyList() {
    if (firstElem == NULL)cout<<"LinkedList is empty"<<endl;

    nodeType<Type> *tmp;
    while(tmp != NULL){
        tmp=first;
        first=first->link;
        delete tmp;
    }
    last=NULL;
    count =0;
}



template <class Type>
LinkedListType<Type>::LinkedListType() {
    first=NULL;
    last=NULL;
    count=0;
}


template <class Type>
LinkedListType<Type>::~LinkedListType() {
    destroyList();
}

