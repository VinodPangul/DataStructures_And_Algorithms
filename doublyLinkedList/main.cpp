#include <iostream>
#include "doublyLinkedList.h"
#include "doublyLinkedList.cpp"
using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    doublyLinkedList<int> d, g;
    cout<<d.length();
    cout<<d.isEmpty();
    int num=0;
    cout<<"Enter the nums with -999"<<endl;
    cin>>num;
    while(num != -999){
        d.insert(num);
        cin>>num;
    }

    cout<<d.length()<<endl;
    d.print();
    cout<<endl;
    num=6;
    cout<<"Search Result: "<<d.search(num)<<endl;

    d.deleteElem(num);
    d.print();
//    g=d;
//    cout<<d.length();


    return 0;
}