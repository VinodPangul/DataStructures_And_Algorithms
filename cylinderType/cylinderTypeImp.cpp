//
// Created by vpangul on 2019-03-30.
//

#include <iostream>
#include "circleType.h"
#include "cylinderType.h"
using namespace std;

void cylinderType::printSurfaceArea(){
    cout<<"\n Surface Area: ";
    double circum_area=height*circleType::calcCircum();
    double base_area=2*circleType::calcArea();
    cout<<"Surface area:"<<circum_area+base_area;

}

void cylinderType::printVolume() {
    cout<<"\n Volume of Circle:"<<circleType::calcArea()*height;
}

void cylinderType::setRad(double r){
    circleType::setRad(r);
}

void cylinderType::setCenter(double x, double y) {
    circleType::setPoint(x,y);
}

void cylinderType::setHeight(double h) {
    height=h;
}