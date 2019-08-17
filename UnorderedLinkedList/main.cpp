#include <iostream>
#include "unorderedLinkedList.h"
#include "unorderedLinkedList.cpp"
using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    unorderedLinkedList<int> u1, u2;
    u1.print();
    int num=10;
    u1.insertFirst(num);
    u1.print();
    cout<<"Enter the nos trailed by -999"<<endl;
    cin>>num;

    while(num!= -999){
        u1.insertFirst(num);
        cin>>num;
    }
    u1.print();

    u2=u1;
    cout<<"Printing u2 list after copy"<<endl;
    u2.print();

    cout<<endl;
    num=10;
    u2.deleteNode(num);
    cout<<endl;
    u2.print();

    u2.oddEvenList();

    return 0;
}