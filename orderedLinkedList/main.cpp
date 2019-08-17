#include <iostream>
#include "orderedLinkedList.h"
#include "orderedLinkedList.cpp"
using  namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    orderedLinkedList<int> o1, midList, mergedList;
    int num;

    cout<<"Enter the numbers";
    cin>>num;
    while(num != -999){
        o1.insert(num);
        cin>>num;
    }

    o1.print();
    num=6;
    bool found=o1.search(num);
    cout<<"found:"<<found<<endl;
    cout<<"true:"<<true<<endl;

    o1.deleteNode(num);
    o1.print();
    cout<<endl;

    cout<<"Calling divideMidList() :"<<endl;
    o1.divideMidList(midList);

    cout<<"midList:";
    midList.print();
    cout<<endl;

    cout<<"MainList:";
    o1.print();
    cout<<endl;

    mergedList.mergeList(o1, midList);
    cout<<"Merged Lists are:"<<endl;
    mergedList.print();

    return 0;
}