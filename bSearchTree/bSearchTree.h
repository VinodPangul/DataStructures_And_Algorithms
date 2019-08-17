//
// Created by vpangul on 2019-06-01.
//

#ifndef BSEARCHTREE_BSEARCHTREE_H
#define BSEARCHTREE_BSEARCHTREE_H

#include <iostream>
#include "binaryTree.h"
#include "binaryTree.cpp"

using namespace std;

template <class elemType>
class bSearchTree : public binaryTee<elemType> {
public:
    void deleteNode(elemType& elem);
    void insertNode(elemType& elem);
    bool searchNode(elemType& elem);
    int treeNodeCount(treeNode<elemType> *root);
    int treeLeavesCount(treeNode<elemType> *root);

    bool searchNodeHelper(elemType &elem, treeNode<elemType> *root);
    void insertNodeHelper(treeNode<elemType> *root, treeNode<elemType> *prev, elemType &elem);
    void deleteNodeHelper(treeNode<elemType> *root, treeNode<elemType> *prev, elemType &elem);

        private:

};


#endif //BSEARCHTREE_BSEARCHTREE_H
