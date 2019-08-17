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
    void preOrder();
    void preOrderTraversal(const treeNode<elemType> *current);
    void postOrderTraversal(const treeNode<elemType> &root);

  //  virtual void deleteNode(elemType& elem)=0;
  //  virtual void insertNode(elemType& elem)=0;
  //  virtual bool searchNode(elemType& elem)=0;
  //  virtual int treeNodeCount(treeNode<elemType> &root)=0;
  //  virtual int treeLeavesCount(treeNode<elemType> &root)=0;

    int getTreeHeight(const treeNode<elemType> &root);

    void binaryTree(treeNode<elemType> &root);
    binaryTee();
    ~binaryTee();
    void deleteTree(treeNode<elemType>* &tmp);
protected:
    treeNode<elemType> *root;

private:

    void inOrderTraversal(const treeNode<elemType> *current);

};




#endif //BINARYTREE_BINARYTREE_H
