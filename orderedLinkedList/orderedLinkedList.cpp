//
// Created by vpangul on 2019-04-11.
//

#include <iostream>
#include "orderedLinkedList.h"
using namespace std;

template <class Type>
bool orderedLinkedList<Type>::search(Type &elem) {
    /*
     * This is ordered linked list , so elements are are arranged in ascending order
     *      Search until given node element is less than elem
     *      If not found, return false else return true
     */

    nodeType<Type> *current;
    current=LinkedListType<Type>::first;
    bool found = false;
    while(current->val < elem){
        current=current->link;
    }
    if(current != NULL && current->val==elem){
        found=true;
    }else{
        found= false;
    }
    return found;


}

template <class Type>
void orderedLinkedList<Type>::deleteNode(Type &elem) {
    /*
     * To delete: we will have current and TrailCurrent pointers
     *      we will search until node->val is less than current->val
     *      If not found, just return with a message
     *      If found, where found matters
     *          check if node is First If so make next as first
     *          Check if it is the last, then make trail one as last
     *          If it is in middle, make links accordingly
     */
    nodeType<Type> *current, *trailCurrent;
    bool found=false;
    current=LinkedListType<Type>::first;

    while(current->val<elem && !found){
        trailCurrent=current;
        current=current->link;
    }
    if(current->val == elem) {
        if (current == LinkedListType<Type>::first) {
            LinkedListType<Type>::first = LinkedListType<Type>::first->link;
            found = true;
            delete current;
            LinkedListType<Type>::count--;
        } else if (current->link == NULL){
            LinkedListType<Type>::last=trailCurrent;
            found= true;
            delete current;
            LinkedListType<Type>::count--;
        } else {
            trailCurrent->link=current->link;
            delete current;
            LinkedListType<Type>::count--;
        }
    }else{
        cout<<"Sorry, no element found to delete";
    }
}


template <class Type>
void orderedLinkedList<Type>::insert(Type &elem) {
    /*
     * Insert first: if first existing is bigger than elem, then we will have to add at first
     * Insert Last: If current->link==NULL, it will added as last
     * Insert middle : trailCurrent->link=newNode;
     */
    nodeType<Type> *current, *trailCurrent;
    nodeType<Type> *newNode= new nodeType<Type>;
    newNode->val=elem;
    newNode->link=NULL;

    current=LinkedListType<Type>::first;
    if(current == NULL){
        LinkedListType<Type>::first=newNode;
        LinkedListType<Type>::last=newNode;
        LinkedListType<Type>::count++;
        return;
    }
    while(current != NULL && current->val <= elem){
        trailCurrent=current;
        current=current->link;
    }


        if(LinkedListType<Type>::first==current){
            newNode->link=LinkedListType<Type>::first;
            LinkedListType<Type>::first=newNode;
        }else if(current == NULL){
            LinkedListType<Type>::last->link=newNode;
            LinkedListType<Type>::last=newNode;
        }else{
            trailCurrent->link=newNode;
            newNode->link=current;
        }

    LinkedListType<Type>::count++;
}



template <class Type>
void orderedLinkedList<Type>::insertFirst(Type &node) {
    insert(node);
}


template <class Type>
void orderedLinkedList<Type>::insertLast(Type &node){
    insert(node);
}

template <class Type>
void orderedLinkedList<Type>::divideMidList(orderedLinkedList<Type> &other) {
    if(LinkedListType<Type>::count<2){
        cout<<"Insufficient no of elements in thhe linkedList"<<endl;
    }else{
        nodeType<Type> *current=LinkedListType<Type>::first;
        int temp_count = LinkedListType<Type>::count/2;
        while (temp_count) {
            current=current->link;
            temp_count--;
        }
        nodeType<Type> *tmp;
        tmp=current->link;
        current->link=NULL;
        LinkedListType<Type>::count=LinkedListType<Type>::count/2;

        other.count=LinkedListType<Type>::count/2 + 1;

        nodeType<Type> *newNode = new nodeType<Type>;
        newNode->val=tmp->val;
        newNode->link=tmp->link;
        other.first=newNode;
        tmp=tmp->link;
        while(tmp != NULL){
            nodeType<Type> *newNode = new nodeType<Type>;
            newNode->val=tmp->val;
            newNode->link=tmp->link;
            if(tmp->link== NULL)
                other.last=tmp;

            tmp=tmp->link;
        }
    }
}


template <class Type>
void orderedLinkedList<Type>::mergeList(orderedLinkedList<Type> &list1, orderedLinkedList<Type> &list2) {
    nodeType<Type> *first1=list1.first;
    nodeType<Type> *first2=list2.first;
    nodeType<Type> *lastSmall=NULL;

    if(first1 == NULL){
        LinkedListType<Type>::first=first2;
        list2.first=NULL;
        LinkedListType<Type>::count=list2.count;
        lastSmall=LinkedListType<Type>::first;
    }else if(first2 == NULL){
        LinkedListType<Type>::first=first1;
        list1.first=NULL;
        LinkedListType<Type>::count=list1.count;
        lastSmall=LinkedListType<Type>::first;
    }else{

        if(first1->val < first2->val){
            LinkedListType<Type>::first=first1;
            lastSmall=first1;
            first1=first1->link;

        }else{
            LinkedListType<Type>::first=first2;
            lastSmall=first2;
            first2=first2->link;
        }

        while(first1 != NULL && first2 != NULL){
            if(first1->val < first2->val){
                lastSmall->link=first1;
                lastSmall=first1;
                first1=first1->link;
            }else{
                lastSmall->link=first2;
                lastSmall=first2;
                first2=first2->link;
            }
        }
        if(first1 == NULL){
            lastSmall->link=first2;
        }else if(first2 == NULL){
            lastSmall->link=first1;
        }

        list1.first=NULL;
        list1.last=NULL;
        list2.first=NULL;
        list2.last=NULL;
        LinkedListType<Type>::count=list1.count + list2.count;
    }

}



#if 0
template <class Type>
void orderedLinkedList<Type>::mergeList(orderedLinkedList<Type> &list1, orderedLinkedList<Type> &list2) {
    /* Check if the list is not empty */
    if(LinkedListType<Type>::first != NULL)
        LinkedListType<Type>::destroyList();

    if(list1.first == NULL && list2.first == NULL){ // Both lists are empty
        LinkedListType<Type>::first=NULL;
        LinkedListType<Type>::last=NULL;
        LinkedListType<Type>::count=0;
    }else if(list1.first == NULL){
                                                    // Only First list is empty
        nodeType<Type> *trailCurrent;
        nodeType<Type> *current=list2.first;
        LinkedListType<Type>::count=list2.count;

        nodeType<Type> *newNode= new nodeType<Type>;
        newNode->val = current->val;
        newNode->link = NULL;
        LinkedListType<Type>::first=newNode;
        trailCurrent=current;
        current=current->link;

        while(current != NULL){
            nodeType<Type> *newNode= new nodeType<Type>;
            newNode->val = current->val;
            current=current->link;
        }
        LinkedListType<Type>::last=trailCurrent;


    }else if(list2.first == NULL){                  // Only Second list is empty
        nodeType<Type> *trailCurrent;
        nodeType<Type> *current=list1.first;
        LinkedListType<Type>::count=list1.count;

        nodeType<Type> *newNode= new nodeType<Type>;
        newNode->val = current->val;
        newNode->link = NULL;
        LinkedListType<Type>::first=newNode;
        trailCurrent=current;
        current=current->link;

        while(current != NULL){
            nodeType<Type> *newNode= new nodeType<Type>;
            newNode->val = current->val;
            current=current->link;
        }
        LinkedListType<Type>::last=trailCurrent;
    }else {                                         // None of the lists are empty

        nodeType<Type> *current=LinkedListType<Type>::first;
        if (list1.first->val < list2.first->val) {
            nodeType<Type> *newNode = new nodeType<Type>;
            newNode->val = list1.first->val;
            newNode->link = NULL;

            if(LinkedListType<Type>::first == NULL){
                LinkedListType<Type>::first=newNode;
                LinkedListType<Type>::last=newNode;
            }else{
                nodeType<Type> *tmp = LinkedListType<Type>::last;
                tmp->link = newNode;
                LinkedListType<Type>::last=newNode;
            }
            list1.first=list1.first->link;

        }else{
            nodeType<Type> *newNode = new nodeType<Type>;
            newNode->val = list2.first->val;
            newNode->link = NULL;

            if(LinkedListType<Type>::first == NULL){
              LinkedListType<Type>::first=newNode;
                LinkedListType<Type>::last=newNode;
            }else{
                nodeType<Type> *tmp = LinkedListType<Type>::last;
                tmp->link = newNode;
                LinkedListType<Type>::last=newNode;
            }
            list2.first=list2.first->link;
        }
        LinkedListType<Type>::count++;

    }
}

#endif