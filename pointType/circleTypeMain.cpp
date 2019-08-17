//
// Created by vpangul on 2019-03-30.
//

#include<iostream>
#include "circleType.h"

using namespace std;
int main(){

    circleType c1;
    c1.calcCircum();
    c1.calcArea();

    c1.setRad(10);
    double c1_area=c1.calcArea();
    double c1_circum=c1.calcCircum();

    cout<<"c1_area: "<<c1_area<<"c1_circum: "<<c1_circum<<endl;

    c1.setPoint(1.1, 2.2);
    c1.setRad(12);
    cout<<c1.calcCircum();
    cout<<c1.calcArea();
    return 0;
}
