//
// Created by vpangul on 2019-04-03.
//
#include <iostream>
#include "arrayListType.h"

using namespace std;

template <class elemType>
arrayListType<elemType>::arrayListType(const arrayListType<elemType>& otherList) {
    length=otherList.length;
    maxSize=otherList.maxSize;
    delete[] list;

    list= new arrayListType(maxSize);
    for(int i=0; i<length; i++){
        list[i]=otherList[i];
    }
}

template <class elemType>
arrayListType<elemType>& arrayListType<elemType>::operator=(const arrayListType<elemType>& otherList){
    if( this != &otherList){
        length=otherList.length;
        maxSize=otherList.maxSize;
        delete [] list;

        list = new arrayListType(maxSize);
        for(int i=0; i<length; i++){
            list[i]=otherList[i];
        }
     return *this;

    }

}

template <class elemType>
int arrayListType<elemType>::seqSearch(const elemType &listParam) {
    if(length<0 || length>maxSize)
        cerr<<"Inavlid list, can't search";

    bool found=false;
    int i;
    for(i=0; i<length; i++){
        if(list[i]==listParam){
            found=true;
            break;
        }
    }
    if(!found)
        return -1;

    return i;
}

template <class elemType>
void arrayListType<elemType>::insert(const elemType& listParam){

    if(length==0) {
        list[length] = listParam;
        length++;
    }

    if(length==maxSize)
        cerr<<"Can't insert as the list is full"<<endl;

    int found=seqSearch(listParam);
    if(found != -1)
        cerr<<"Can't add, it already exists in the list";

    list[length]=listParam;
    length++;
}

template <class elemType>
void arrayListType<elemType>::remove(const elemType& listParam) {
    if(length<0)
        cerr<<"List is empty or corrupted";

    int loc=seqSearch(listParam);
    if(loc == -1)
        cerr<<"Elem is not found for removal"<<endl;

    removeAt(loc);
}

template <class elemType>
bool arrayListType<elemType>::isItemAtEqual(int location, const elemType& listParam)const {

    return(list[location] == listParam);
}

template <class elemType>
void arrayListType<elemType>::print() const {
    for(int i=0; i<length; i++){
        cout<<"Location:"<<i<<" Value:"<<list[i]<<endl;
    }
}

template <class elemType>
void arrayListType<elemType>::insertAt(int location, const elemType& listParam) {
    if(length>=maxSize){
        cerr<<"Can't Insert, exeeded the max length";
    }

    for(int i=length; i>location; i--){
        list[i]=list[i-1];
    }
    list[location]=listParam;
    length++;
}

template <class elemType>
void arrayListType<elemType>::insertAtEnd(const elemType& listParam) {
    if(length>maxSize){
        cerr<<"Can't insert at end in full list"<<endl;
    }else{
        list[length]=listParam;
        length++;
    }
}

template <class elemType>
void arrayListType<elemType>::removeAt(int location) {
    if(location<0 || location>maxSize){
        cerr<<"Not a correct location to remove the element from"<<endl;
    }else{
        for(int i=location; i<=length; i++){
            list[i]=list[i+1];
        }
        length--;
    }
}

template <class elemType>
void arrayListType<elemType>::replaceAt(int location, const elemType& listParam) {
    if(length<0 || length>maxSize){
        cerr<<"Can't replace, issue with the length of the list"<<endl;
    }
    list[location]=listParam;
}

/* Simple Functions */
template <class elemType>
int arrayListType<elemType>::getSize() {
    return length;
}

template <class elemType>
int arrayListType<elemType>::getMaxSize() {
    return maxSize;
}


template <class elemType>
bool arrayListType<elemType>::isEmpty()
{
    return length==0?true:false;
}

template <class elemType>
bool arrayListType<elemType>::isFULL() {
    return length >= maxSize ? true: false;
}

template <class elemType>
void arrayListType<elemType>::clearList() {
    length=0;
}

/* Constructor */
template <class elemType>
arrayListType<elemType>::arrayListType(int size) {
    list = new elemType[size];
    length=0;
    maxSize=size;
}


/* Destructor */
template <class elemType>
arrayListType<elemType>::~arrayListType() {
    delete [] list;
}
