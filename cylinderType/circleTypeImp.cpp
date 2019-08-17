//
// Created by vpangul on 2019-03-30.
//

#include <iostream>
#include "circleType.h"

using namespace std;

double circleType::calcCircum(){
    return  2*3.14*radius;
}

double circleType::calcArea(){
    return 3.14*radius*radius;
}

void circleType::setRad(double r){
    radius=r;
}

double circleType::getRad() {
    return radius;
}
circleType::circleType(double r, double x, double y):pointType(x,y){
//	pointType::pointType();
    radius=r;
}

