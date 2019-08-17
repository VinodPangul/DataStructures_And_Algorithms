#include <iostream>
#include "unorderedLinkedList.h"
#include "unorderedLinkedList.cpp"
using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    unorderedLinkedList<int> u1;
    u1.insertFirst(10);
    return 0;
}