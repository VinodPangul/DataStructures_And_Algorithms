//
// Created by vpangul on 2019-05-20.
//

#ifndef BINARYTREE_BINARYTREE_H
#define BINARYTREE_BINARYTREE_H

#include <iostream>
using namespace std;

template <class elemType>
struct treeNode{
    elemType info;
    treeNode<elemType> *llink;
    treeNode<elemType> *rlink;
};


template <class elemType>
class binaryTee{
public:
    binaryTee<elemType>& operator=(const binaryTee<elemType> &other);

    bool isEmpty(const treeNode<elemType> &root);

    void inOrder();
    void preOrderTraversal(const treeNode<elemType> &root);
    void postOrderTraversal(const treeNode<elemType> &root);

    void deleteNode(elemType& elem);
    void insertNode(elemType& elem, bool indicator);
    int getTreeHeight(const treeNode<elemType> &root);

    vector<vector<int>> levelOrder();
    void levelOrderHelper(treeNode<elemType> *current, vector<vector<int>> &v, int i);


    void binaryTree(treeNode<elemType> &root);
    binaryTee();
    ~binaryTee();
    void deleteTree(treeNode<elemType>* &tmp);
protected:




private:
    treeNode<elemType> *root;
    void inOrderTraversal(const treeNode<elemType> *current);

};




#endif //BINARYTREE_BINARYTREE_H
