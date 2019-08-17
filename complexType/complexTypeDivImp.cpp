//
// Created by vpangul on 2019-03-30.
//

#include <iostream>
#include "complexTypeDiv.h"
using namespace std;

complexType complexTypeDiv::operator-(complexType& a, complexType& b){
    complexType tmp;
    tmp.rp=a.rp-b.rp;
    tmp.ip=a.ip-b.ip;

    return tmp;
}

complexType complexTypeDiv::operator/(complexType& a, complexType& b){
    complexType tmp;
    tmp.rp=a.rp/b.rp;
    tmp.ip=a.ip/b.ip;

    return tmp;
}
