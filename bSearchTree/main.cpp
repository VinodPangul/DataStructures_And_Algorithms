#include <iostream>
#include "bSearchTree.h"
#include "bSearchTree.cpp"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;

    bSearchTree<int> *bst;
    int num=0;
    cout<<"\n Enter the numbers ending with -999"<<endl;
    cin>>num;
    while(num != -999){
        bst->insertNode(num);
        cin>>num;
    }

    bst->inOrder();

    cout<<endl;

    bst->preOrder();
    cout<<endl;

    num=12;
    bst->deleteNode(num);
    bst->inOrder();
   // cout<<endl<<"Node count:"<<bst->treeNodeCount()<<endl;
   // cout<<endl<<"Leaves count:"<<bst->treeLeavesCount()<<endl;


    cout<<"New List:"<<endl;
    bSearchTree<int> bbst;
    bbst.inOrder();
    bbst.insertNode(++num);
    bbst.insertNode(++num);
    bbst.insertNode(++num);
    bbst.insertNode(++num);
    bbst.inOrder();


    return 0;
}