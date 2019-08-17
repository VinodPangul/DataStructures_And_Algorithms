//
// Created by vpangul on 2019-04-06.
//

#include <iostream>
#include "safeArray.h"
using namespace std;

template <class elemType>
safeArray<elemType>::safeArray(){
    lowerb=0;
    rightb=4;
    arr=new elemType[rightb-lowerb];
    for(int i=lowerb; i<=rightb; i++){
        arr[i]=0;
    }
}

template <class elemType>
safeArray<elemType>::safeArray(int rb){
    if(rb>0)
       rightb=rb;

    arr=new elemType[rightb-lowerb];
    for(int i=lowerb; i<=rightb; i++){
        arr[i]=0;
    }
}

template <class elemType>
safeArray<elemType>::safeArray(int lb, int rb){

    if(lb>rb){
        cerr<<"Invalid initialization"<<endl;
        lowerb=0;
        rightb=4;
    }else {
        lowerb=lb;
        rightb=rb;
        arr = new elemType[rightb - lowerb];
        for (int i = lowerb; i <= rightb; i++) {
            arr[i] = 0;
        }
    }
}

template <class elemType>
safeArray<elemType>::~safeArray() {
    delete [] arr;
}


template <class elemType>
safeArray<elemType>::safeArray(const safeArray<elemType> &other) {
    rightb=other.rightb;
    lowerb=other.lowerb;

    delete [] arr;
    arr=new elemType[rightb-lowerb];
    for(int i=lowerb; i<=rightb; i++){
        arr[i]=other.arr[i];
    }

}


// Overload asignment operator
template <class elemType>
safeArray<elemType>& safeArray<elemType>::operator=(const safeArray<elemType> &other) {
    if(this != other){
        lowerb=other.lowerb;
        rightb=other.rightrb;

        delete [] arr;
        arr=new elemType[rightb-lowerb];
        for(int i=lowerb; i<=rightb; i++){
            arr[i]=other.arr[i];
        }
    }
    return *this;
}


template <class elemType>
bool safeArray<elemType>::operator!=(const safeArray<elemType> &other){
    if(this != other)
        return true;

    return false;
}


template <class elemType>
bool safeArray<elemType>::operator==(const safeArray<elemType> &other) {
    if (this == other) {
        for(int i=lowerb; i<=rightb; i++){
            if(arr[i]!=other.arr[i])
                return false;
        }
        return true;
    }
}

template <class elemType>
int& safeArray<elemType>::operator[](int index) {
    if(index>=lowerb && index<rightb)
        return arr[index-lowerb];

    assert("Index is not correct");
}

template <class elemType>
void safeArray<elemType>::print() {
    cout<<"Printing the array:";
         for(int i=lowerb; i<=rightb; i++){
             cout<<arr[i]<<" ";
         }
}

template <class elemType>
ostream& operator<<(ostream &obj, safeArray<elemType> &other) {
          for(int i=0; i<other.rightb-other.lowerb; i++){
             obj<<other.arr[i]<<" ";
         }
}

template <class elemType>
 istream& operator>>(ostream &obj, safeArray<elemType> &other) {
         for(int i=0; i<other.rightb-other.lowerb; i++){
             obj>>other.arr[i];
         }
}
