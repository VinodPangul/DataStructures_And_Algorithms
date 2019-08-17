//
// Created by vpangul on 2019-03-30.
//

#ifndef CYLINDERTYPE_CYLINDERTYPE_H
#define CYLINDERTYPE_CYLINDERTYPE_H

#include "circleType.h"

class cylinderType:public circleType{
public:

    void printSurfaceArea();
    void printVolume();
    void setRad(double r);
    void setCenter(double x, double y);
    void setHeight(double h);
private:
    double height;
};

#endif //CYLINDERTYPE_CYLINDERTYPE_H
