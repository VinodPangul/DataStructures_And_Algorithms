//
// Created by vpangul on 2019-05-20.
//

#include <iostream>
#include "binaryTree.h"
using namespace std;

template <class elemType>
bool binaryTee<elemType>::isEmpty(const treeNode<elemType> &root) {
    if(root == NULL)
        return true;
    else
        return false;
}

template <class elemType>
binaryTee<elemType>::binaryTee() {
    root=NULL;
}

template <class elemType>
binaryTee<elemType>::~binaryTee() {
    deleteTree(root);
}

template <class elemType>
void binaryTee<elemType>::deleteTree(treeNode<elemType>* &tmp) {
    treeNode<elemType> *current=tmp;
       if(current == NULL){
           return;
       }
       else{
           deleteTree(current->llink);
           deleteTree(current->rlink);
           delete current;
       }
}

template <class elemType>
int binaryTee<elemType>::getTreeHeight(const treeNode<elemType> &root) {
    if (!root) return 0;
    else return 1 + max(getTreeHeight(root.llink), getTreeHeight(root.rlink));
}
//
//int max(int a, int b){
//    if a>b?a:b;
//}

template <class elemType>
void binaryTee<elemType>::inOrder() {
    inOrderTraversal(root);
}
template <class elemType>
void binaryTee<elemType>::preOrder(){
    preOrderTraversal(root);
}


template <class elemType>
void binaryTee<elemType>::inOrderTraversal(const treeNode<elemType> *current) {

    if(current == NULL){

    }else{
        inOrderTraversal(current->llink);
//        visitNode(current);
        cout<<current->info<<" ";
        inOrderTraversal(current->rlink);
    }
}

template <class elemType>
void binaryTee<elemType>::preOrderTraversal(const treeNode<elemType> *current) {
   // treeNode<elemType> *current=root;

    if(current == NULL){

    }else{
        cout<<current->info<<" ";
        preOrderTraversal(current->llink);
        preOrderTraversal(current->rlink);
    }
}

template <class elemType>
void binaryTee<elemType>::postOrderTraversal(const treeNode<elemType> &root) {
    treeNode<elemType> *current=root;

    if(root == NULL){

    }else{
        preOrderTraversal(current->llink);
        preOrderTraversal(current->rlink);
        cout<<current->info<<" ";
    }
}

#if 0
template <class elemType>
void binaryTee<elemType>::deleteNode(elemType &elem) {
    treeNode<elemType> *current=root;
    if(! current){
        cout<<"Tree is empty"<<endl;
        return;
    }
    bool found=true;

    if(current && current->info == elem){
        found=true;
    }else{

    }
}
#endif

#if 0
template <class elemType>
void binaryTee<elemType>::insertNode(elemType &elem, bool indicator) {
        treeNode<elemType> *tmp = new treeNode<elemType>;
        tmp->info=elem;
        tmp->llink=NULL;
        tmp->rlink=NULL;
    if(!root){
        root = tmp;
    }else {
        treeNode<elemType> *current = root, *trailCurrent = NULL;
        if (indicator) {
            // Insert node on right
            while (current) {
                trailCurrent = current;
                current = current->rlink;
            }
        } else {
            // Insert node on left
            while(current) {
                trailCurrent = current;
                current = current->rlink;
            }
        }

        if(indicator) trailCurrent->rlink = tmp;
        else trailCurrent->llink = tmp;
    }
}

#endif