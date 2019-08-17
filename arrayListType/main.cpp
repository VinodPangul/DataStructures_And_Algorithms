#include <iostream>
#include "arrayListType.h"
#include "arrayListType.cpp"

using namespace std;
int main() {
    std::cout << "Hello, World!" << std::endl;
    arrayListType<int> a1(5);

    int count;
    cout<<"Enter the no of items in the list"<<endl;
    cin>>count;
    for(int i=0; i<count; i++){
        int num;
        cout<<"Entet the numi:";
        cin>>num;
        a1.insertAt(i, num);

    }
    a1.print();
    a1.remove(9);
    a1.print();

    int loc=a1.seqSearch(6);
    if(loc == -1) {
        cerr << "This num is not int he list";
    }else{
        cout<<"This num is found at"<<loc<<endl;
    }

    if(a1.isEmpty()){ cout<<"Empty"<<endl; }

     arrayListType<string> str1;

    int str_count;
    cout<<"Enter the no of items in the list"<<endl;
    cin>>str_count;
    for(int i=0; i<str_count; i++){
        string str;
        cout<<"Entet the str:";
        cin>>str;
        str1.insertAt(i, str);

    }
    str1.print();
    str1.remove("ABC");
    str1.print();

    loc=str1.seqSearch("DEF");
    if(loc == -1) {
        cerr << "This num is not int he list";
    }else{
        cout<<"This num is found at"<<loc<<endl;
    }

    if(str1.isEmpty()){ cout<<"Empty"<<endl; }


    return 0;
}