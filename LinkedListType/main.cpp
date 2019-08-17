#include <iostream>
#include "LinkedListType.h"
#include "LinkedListType.cpp"
using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    LinkedListType<int> l1;
    l1.destroyList();

    l1.print();


    return 0;
}