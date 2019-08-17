//
// Created by vpangul on 2019-03-30.
//

#ifndef POINTTYPE_CIRCLETYPE_H
#define POINTTYPE_CIRCLETYPE_H
#include "pointType.h"

class circleType:public pointType
{
public:
    void setRad(double r);
    double calcCircum();
    double calcArea();
    double getRad();
    circleType(double r=0.0, double x=0.0, double y=0.0);
private:
    double radius;
};

#endif //POINTTYPE_CIRCLETYPE_H
