//
// Created by vpangul on 2019-04-12.
//
#include <iostream>
#include "doublyLinkedList.h"
using namespace std;

template <class Type>
doublyLinkedList<Type>::doublyLinkedList() {
    first=NULL;
    last=NULL;
    count=0;
}

template <class Type>
doublyLinkedList<Type>::~doublyLinkedList() {
    nodeType<Type> *tmp=first;
    if( first != NULL){
        tmp=first;
        first=first->next;
        delete tmp;
    }
    first=NULL;
    last=NULL;
    count=0;
}

template <class Type>
doublyLinkedList<Type>&  doublyLinkedList<Type>::operator=(
        const doublyLinkedList<Type> &other) {
    if(this != &other){
        nodeType<Type> *current;

       count=other.count;
       first=other.first;
       last=other.last;
       current=first;

       if(current != NULL){
           nodeType<Type> *newNode=new nodeType<Type>;
           newNode->info=other.first->info;
           newNode->next=other.first->next;
           newNode->back=other.first->back;

           current= current->next;

       }
       return *this;
    }
}

template <class Type>
void doublyLinkedList<Type>::copyList(const doublyLinkedList<Type> &other) {
    if(this != &other){
        copyList(other);
    }
}

template <class Type>
bool doublyLinkedList<Type>::isEmpty() {
   if(count ==0 && first==NULL)
       return true;
   else
       return false;
}

template <class Type>
Type doublyLinkedList<Type>::length() {
    return count;
}

template <class Type>
void doublyLinkedList<Type>::insert(Type& elem) {
    nodeType<Type> *current, *trailCurrent;
    nodeType<Type>* newNode=new nodeType<Type>;
    newNode->info=elem;
    newNode->next=NULL;
    newNode->back=NULL;

    if(first == NULL){
        first=newNode;
        last=newNode;
        count++;
    }else{
        bool found = false;
        current=first;
        while(!found && current != NULL ){
            if(current->info >= elem)
                found=true;
            else{
                trailCurrent = current;
                current = current->next;
            }
        }

        if(current == first ){
            newNode->next=current;
            current->back=newNode;
            first=newNode;
            count++;
        }else if(current == NULL){
            trailCurrent->next=newNode;
            newNode->back=trailCurrent;
            last=newNode;
            count++;
        }else{
            trailCurrent->next=newNode;
            newNode->next=current;
            newNode->back=trailCurrent;
            current->back=newNode;
            count++;
        }
    }
}

template <class Type>
void doublyLinkedList<Type>::print() {
    nodeType<Type> *current=first;
    while(current != NULL){
        cout<<current->info<<" "<<endl;
        current=current->next;
    }
}

template <class Type>
bool doublyLinkedList<Type>::search(Type &elem) {
    if(first==NULL)
        return false;

    bool found=false;
    nodeType<Type> *current=first;
    while(current != NULL && !found){
        if(current->info >= elem){
            found=true;
        }else{
            current=current->next;
        }
    }
    if(found){
        if(current != NULL && current->info == elem) {
            return true;
        }else{
            return false;
        }
    }else{
        return false;
    }

}

template <class Type>
void doublyLinkedList<Type>::deleteElem(Type &elem) {
    if(first==NULL) return;
    nodeType<Type> *current=first;
    nodeType<Type> *trailCurrent;
    bool found=false;

    while(current != NULL && !found){
        if(current->info >= elem)
            found=true;
        else{
            trailCurrent=current;
            current=current->next;
        }


        if(found){
            if(current->info == elem){
                if(current == first){
                    if(current->next == NULL){
                        first = NULL;
                        last = NULL;
                        count=0;
                        delete current;
                    }else{
                        first=current->next;
                        current->next->back=NULL;
                        delete current;
                        count--;
                    }
                }
                else if(current->next == NULL) {
                    trailCurrent->next = NULL;
                    last=trailCurrent;
                    delete current;
                    count--;
                }else {
                    trailCurrent->next = current->next;
                    current->next->back=trailCurrent;
                    delete current;
                    count--;
                }
            }
        }

    }
}