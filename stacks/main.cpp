#include <iostream>
#include <string>
#include "linkedStackType.h"
#include "linkedStackType.cpp"

using namespace std;
int main() {
    std::cout << "Hello, World!" << std::endl;
    linkedStackType<string> st, st2, st3;

    const char* end="end";
    char num[100]="";
    cout<<"Enter nums ending with -999"<<endl;
    gets(num);
    //while(strcasecmp(num, "end")){
        while(strcmp(num,end) != 0){
        st.push(num);
        gets(num);
    }

//    while (! st.isEmptyStack()){
//        cout<<st.top()<<" ";
//        st.pop();
//    }

    //st2 = st;
//    cout<<"Enter nums ending with -999"<<endl;
//    gets(num);
//    //while(strcasecmp(num, "end")){
//        while(strcmp(num,end) != 0){
//        st2.push(num);
//        gets(num);
//    }
//
//    if(st2.isEqual(st)) cout<<"same stacks"<<endl;
//    else cout<<"Stacks are not same"<<endl;

    st3.reverseStack(st);
    while (! st3.isEmptyStack()){
        cout<<st3.top()<<" ";
        st3.pop();
    }


    return 0;
}