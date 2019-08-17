//
// Created by vpangul on 2019-04-08.
//
#include <iostream>
#include "LinkedListType.h"

using namespace std;

template <class Type>
void LinkedListType<Type>::print() {
    if (first == NULL){
        cout<<"LinkedList is empty"<<endl;
        return ;
    }
    nodeType<Type> *tmp;
    tmp=first;
    while(tmp != NULL){
        cout<<tmp->val<<" ";
        tmp=tmp->link;
    }

}

template <class Type>
void LinkedListType<Type>::destroyList() {
    if (first == NULL)cout<<"LinkedList is empty"<<endl;

    nodeType<Type> *tmp;
    while(first != NULL){
        tmp=first;
        first=first->link;
        delete tmp;
    }
    last=NULL;
    count =0;
}

template <class Type>
void LinkedListType<Type>::initializeList() {
    destroyList();
}

template <class Type>
bool LinkedListType<Type>::isEmptyList() {
    if(count ==0 && first == NULL)
        return true;
    return false;
}

template <class Type>
int LinkedListType<Type>::getLength() {
    return count;
}

template <class Type>
Type LinkedListType<Type>::back() {
    if (first == NULL)assert("LinkedList is empty");

    return first->val;
}

template <class Type>
Type LinkedListType<Type>::front() {
    if (last == NULL)assert("LinkedList is empty");

    return last->val;
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


template <class Type>
void LinkedListType<Type>::copyList(LinkedListType<Type>& other){
    nodeType<Type> *newNode;
    nodeType<Type> *current;

    // Destroy the existing list
    if(first != NULL) destroyList();

    // Check if other list is empty
    if(other.first == NULL){
        first=NULL;
        last=NULL;
        count=0;
    }else{
        count=other.count;
        current=other.first;

        // Set the first Node
        first=new nodeType<Type>;
        first->val=current->val;
        first->link=NULL;
        last=first;
        current=current->link;

        while(current != NULL){
            newNode=new nodeType<Type>;
            newNode->val=current->val;
            newNode->link=NULL;

            last->link=newNode;
            last=newNode;
            current=current->link;
        }
    }
}


template <class Type>
LinkedListType<Type>& LinkedListType<Type>::operator=(LinkedListType<Type> &other) {
    if(this != &other){
       copyList(other);
    }
    return *this;
}


