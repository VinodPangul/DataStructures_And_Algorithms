#include <iostream>
#include "cylinderType.h"

using namespace std;
int main() {

    cylinderType c1;

    c1.setHeight(10);
    c1.setCenter(1,2);
    c1.setRad(2.12);
    c1.print();

    c1.printVolume();
    c1.printSurfaceArea();

    return 0;
}