//
// Created by vpangul on 2019-03-30.
//

#ifndef COMPLEXTYPE_COMPLEXTYPE_H
#define COMPLEXTYPE_COMPLEXTYPE_H

using namespace std;
class complexType{

    friend ostream& operator<<(ostream&, const complexType&);
    friend istream& operator>>(istream&, complexType&);

public:
    void setComplex(double& real, double& img);
    void getComplex(double& real, double& img);

    complexType operator+(const complexType& otherComplex)const;
    complexType operator*(const complexType& otherComplex)const;
    bool operator==(const complexType& otherComplex)const;

    complexType(double real=0, double img=0);
//private:
protected:
    double rp;
    double ip;
};

#endif //COMPLEXTYPE_COMPLEXTYPE_H
