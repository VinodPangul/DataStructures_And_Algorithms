#include <iostream>
#include "safeArray.h"
#include "safeArrayImp.cpp"
using namespace std;

int main() {
    //std::cout << "Hello, World!" << std::endl;

    safeArray<int> a, b(-3,4);
    a.print();
    b.print();

/*
    for(int i=0; i<=4; i++){
        cin>>a[i];
    }
    a.print();
*/
    a[1]=1;
    a.print();
    return 0;
}