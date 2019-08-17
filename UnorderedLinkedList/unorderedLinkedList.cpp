//
// Created by vpangul on 2019-04-09.
//

#include <iostream>
#include "LinkedListType.h"
#include "unorderedLinkedList.h"

using  namespace std;

template <class Type>
void unorderedLinkedList<Type>::insertFirst(Type& node) {
    nodeType<Type> *newNode= new nodeType<Type>;
    if(newNode == NULL)
        assert("Unable to allocate node to insert");


    newNode->val=node;
    newNode->link=LinkedListType<Type>::first;
    if(LinkedListType<Type>::first == NULL)
        LinkedListType<Type>::last=newNode;

    LinkedListType<Type>::first=newNode;
    LinkedListType<Type>::count++;
}

template <class Type>
void unorderedLinkedList<Type>::insertLast(Type& node) {
    nodeType<Type> *newNode= new nodeType<Type>;
    if(newNode == NULL)
        assert("Unable to allocate node to insert");

    newNode->val=node;
    newNode->link=NULL;
    LinkedListType<Type>::last->link=newNode;
    LinkedListType<Type>::last=newNode;
    LinkedListType<Type>::count ++;
}


template <class Type>
void unorderedLinkedList<Type>::deleteNode(Type &node) {
    if(LinkedListType<Type>::first==NULL)assert("List is empty");

    // If first itself is a match
    if(LinkedListType<Type>::first->val == node){
        if(LinkedListType<Type>::first->link != NULL) {
            nodeType<Type> *tmp=LinkedListType<Type>::first;
            LinkedListType<Type>::first = LinkedListType<Type>::first->link;
            delete tmp;
            LinkedListType<Type>::count--;

        }else{
            delete LinkedListType<Type>::first;
            LinkedListType<Type>::first = NULL;
            LinkedListType<Type>::last = NULL;
            LinkedListType<Type>::count = 0;
        }
    }
    else{
        nodeType<Type> *current, *currentTail;
        current=LinkedListType<Type>::first->link;
        currentTail=LinkedListType<Type>::first;
        bool found=false;
        while(current != NULL && !found) {
            if(current->val == node){
                found=true;
                break;
            }
            currentTail = current;
            current = current->link;
        }
        if(found){
            if(current->link == NULL) {
                LinkedListType<Type>::last = currentTail;
            }
                currentTail->link=current->link;
                delete current;
                LinkedListType<Type>::count--;
        }else{
            cout<<"Item is not found in the list"<<endl;
        }
    }
}


template <class Type>
bool unorderedLinkedList<Type>::search(Type &node) {
    if(LinkedListType<Type>::first == NULL)return false;
    nodeType<Type> *current;
    current=LinkedListType<Type>::first;
    bool found=false;
    while(current != NULL & !found){
        if(current->val == node){
            found=true;
            break;
        }
        current=current->link;
    }

    return found;
}

template <class Type>
void unorderedLinkedList<Type>::oddEvenList() {
    unorderedLinkedList<Type> *current=LinkedListType<Type>::first, *slow=LinkedListType<Type>::first, *fast=LinkedListType<Type>::first, *prev=NULL;

    while(unorderedLinkedList<Type>::fast && unorderedLinkedList<Type>::fast->next){
        if(fast->link)
            prev=fast->link;
        else
            prev=fast;

        slow=slow->next;
        fast=fast->next->next;
    }

    LinkedListType<Type> *tmp=prev;
    while(current != tmp){
        prev->next=current->next;
        current->next=current->next->next;
        prev=prev->next;
    }

    LinkedListType<Type>::print();
}
