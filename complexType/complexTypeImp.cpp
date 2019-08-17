//
// Created by vpangul on 2019-03-30.
//
#include <iostream>
#include "complexType.h"

void complexType::setComplex(double &real, double &img) {
    rp=real;
    ip=img;
}

void complexType::getComplex(double &real, double &img) {
    real=rp;
    img=ip;
}

complexType::complexType(double real, double img) {
    rp=real;
    ip=img;
}

complexType complexType::operator*(const complexType &otherComplex) const {

    complexType tmp;
    tmp.rp=(rp*otherComplex.rp ) - (ip*otherComplex.ip);
    tmp.ip=(rp*otherComplex.rp) + (ip*otherComplex.ip);
    return tmp;
}

complexType complexType::operator+(const complexType &otherComplex) const {
    complexType tmp;
    tmp.rp=rp+otherComplex.rp;
    tmp.ip=ip+otherComplex.ip;
    return tmp;
}

bool complexType::operator==(const complexType &otherComplex) const {
    if((rp == otherComplex.rp ) && (ip == otherComplex.ip)){
        return true;
    }
    return false;
}

istream& operator>>(istream& isObject, complexType& complex) {
    char ch;
    isObject>>complex.rp;
    isObject>>ch;
    isObject>>complex.ip;
    isObject>>ch;

    return isObject;

}

ostream& operator<<(ostream& osObject, const complexType& complex) {
    osObject<<"(";
    osObject<<complex.rp;
    osObject<<", ";
    osObject<<complex.ip;
    osObject<<")";

    return osObject;
}