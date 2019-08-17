#include <iostream>
#include "complexType.h"

using namespace std;

int main(){
    complexType c1, c2;
    double rp, ip;
    cout<<"Enter the real and img parts"<<endl;
    cin>>rp>>ip;

    c1.setComplex(rp,ip);
    double rp2, ip2;
    cout<<"Enter the real and img parts"<<endl;
    cin>>rp2>>ip2;
    c2.setComplex(rp2, ip2);

    if(c2 == c1){
        cout<<"Both numbers are same";

    }else{
        cout<<"Both nums are not same"<<endl;
    }
    cout<<c1;
    cout<<c2;
    cout<<c1+c2;
    return 0;
}