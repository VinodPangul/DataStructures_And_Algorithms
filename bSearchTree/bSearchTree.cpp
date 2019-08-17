//
// Created by vpangul on 2019-06-01.
//

#include <iostream>
#include "bSearchTree.h"

using namespace std;

template <class elemType>
bool bSearchTree<elemType>::searchNode(elemType& elem){
    /*
     *  ROOT == NULL -> RETURN FALSE;
     *   else
     *
     *     root->info == elem return TRUE;
     *
     *    Else
     *      elem < root
     *      return searchNode(root.llink, elem )
     *
     *      OR elem > root
     *        return searchNode(root.rlink, elem )
     *
     */

    return searchNodeHelper(elem, binaryTee<elemType>::root);

}


template <class elemType>
bool bSearchTree<elemType>::searchNodeHelper(elemType &elem, treeNode<elemType> *root){
    if(root == NULL) return false;
    else{
        if(root->info == elem) return true;
        else if(root->info < elem) return searchNodeHelper(elem, root->llink);
        else return searchNodeHelper(elem, root->rlink);
    }
}


template <class elemType>
int bSearchTree<elemType>::treeNodeCount(treeNode<elemType> *root) {
    /*
     * root == NULL return 0;
     * else
     *    return 1 + treeNodeCount(root->llink) + treeNodeCount(root->rlink)
     *
     */
    if(root == NULL) return 0;
    else
        return 1 + treeNodeCount(root->llink) + treeNodeCount(root->rlink);

}


template <class elemType>
int bSearchTree<elemType>::treeLeavesCount(treeNode<elemType> *root) {
    /*
     * root == NULL  return 0
     * else
     *   if root->llink == NULL  && root->rlink == NULL --> return 1
     *   else
     *      return treeLeavesCount(root->llink ) + treeLeavesCount(root->rlink);
     */

    if(root == NULL) return 0;
    else{
        if(root->llink == NULL && root->rlink == NULL) return 1;
        else
            return treeLeavesCount(root->llink) + treeLeavesCount(root->rlink);
    }
}


template <class elemType>
void bSearchTree<elemType>::insertNode(elemType &elem) {
    /*
     * root == NULL -> create new node and will assign this value and mark the root
     *
     * else
     *    elem  is in the TREE already
     *
     *    elem < root
     *
     *    elem > root
     *
     *
     */

    treeNode<elemType> *prev = NULL;
    insertNodeHelper(binaryTee<elemType>::root, prev, elem);

}


#if 0
template <class elemType>
void bSearchTree<elemType>::insertNodeHelper(treeNode<elemType> &root, elemType &elem){

    treeNode<elemType> *prev=NULL;

    if(root == NULL){
        treeNode<elemType> *newNode = new treeNode<elemType>;
        newNode->info = elem;
        newNode->llink = NULL;
        newNode->rlink = NULL;
        root=newNode;
        return;
    }else{
        if(root.info < elem){
            if(root.llink == NULL){
                //Create a node and assign this node to llink of root
                treeNode<elemType> *newNode = new treeNode<elemType>;
                newNode->info = elem;
                newNode->llink = NULL;
                newNode->rlink = NULL;
                root.llink = newNode;
                return;
            }else{
                insertNodeHelper(root.llink, elem);
            }
        }else{
            if(root.rlink == NULL){
                treeNode<elemType> *newNode = new treeNode<elemType>;
                newNode->info = elem;
                newNode->llink = NULL;
                newNode->rlink = NULL;
                root.rlink = newNode;
                return;
            }else{
                insertNodeHelper(root.rlink, elem);
            }



        }
    }

}

#endif

template <class elemType>
void bSearchTree<elemType>::insertNodeHelper(treeNode<elemType> *root, treeNode<elemType> *prev, elemType &elem) {


    if (root == NULL) {

        treeNode<elemType> *newNode = new treeNode<elemType>;
        newNode->info = elem;
        newNode->llink = NULL;
        newNode->rlink = NULL;
        if(prev == NULL){
            binaryTee<elemType>::root = newNode;
        }else{
            if(elem < prev->info){
                prev->llink = newNode;
            }else{
                prev->rlink = newNode;
            }
        }
        return;
    } else {

        prev=root;
        if (elem < root->info) {
            insertNodeHelper(root->llink, prev, elem);
        } else {

            insertNodeHelper(root->rlink, prev, elem);
        }

    }
}

template <class elemType>
void bSearchTree<elemType>::deleteNode(elemType &elem) {
    /*
     * root == null return
     * else
     *
     *   elem == root->val -> delete
     *        deleting node could be -> leaf
     *
     *   else  elem < root
     *           prev = root
     *           deleteNode(root->llink)
     *    else
     *          prev = root
     *         deleteNode(root->rlink)
     *
     */

    treeNode<elemType> *prev=NULL;
    deleteNodeHelper(binaryTee<elemType>::root, prev, elem);
}

template <class elemType>
void bSearchTree<elemType>::deleteNodeHelper(treeNode<elemType> *root, treeNode<elemType> *prev, elemType &elem){
    if(root == NULL) return ;
    else{
        if(elem == root->info ){

            // Leaf Case
            if(! root->llink && !root->rlink){
                if(prev->info < elem)
                    prev->rlink = NULL;
                else
                    prev->llink = NULL;
                delete root;
            }else if(root->llink && !root->rlink){
                if(prev->info < elem){
                    prev->rlink = root->llink;
                    delete root;
                }else{
                    prev->llink = root->llink;
                    delete root;
                }

            }else if(root->rlink && !root->llink) {
                if (prev->info < elem) {
                    prev->rlink = root->rlink;
                    delete root;
                } else {
                    prev->llink = root->rlink;
                    delete root;
                }
            }
            else{
                treeNode<elemType> *current=root, *trail=NULL;
                while(current->llink){
                    trail = current;
                    current=current->llink;
                }

                if(current->rlink){
                    root->info = current->rlink->info;
                    delete current->rlink;
                    current->rlink=NULL;
                }else{
                    root->info = current->info;
                    delete current;
                    root->llink=NULL;
                }

            }

        }else if(elem < root->info){
            prev=root;
            deleteNodeHelper(root->llink, prev, elem);
        }else{

            prev=root;
            deleteNodeHelper(root->rlink, prev, elem);
        }



    }


}