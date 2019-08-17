//
// Created by vpangul on 2019-03-30.
//

#ifndef COMPLEXTYPE_COMPLEXTYPEDIV_H
#define COMPLEXTYPE_COMPLEXTYPEDIV_H

#include "complexType.h"
class complexTypeDiv:public complexType{

protected:
    complexType operator-(complexType&, complexType&);
    complexType operator/(complexType&, complexType&);
};

#endif //COMPLEXTYPE_COMPLEXTYPEDIV_H
