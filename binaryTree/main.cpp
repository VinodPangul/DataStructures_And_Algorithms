#include <iostream>
#include "binaryTree.cpp"

using namespace std;
int main() {
    std::cout << "Hello, World!" << std::endl;
    binaryTee<int> b1;
    bool var=true;
    int num=0;
    cin>>num;
    while(num != -999){
        b1.insertNode(num, var);
        var = !var;
        cin>>num;
    }

    b1.inOrder();

    cout<<"\n calling lever node classifier:"<<endl;
    vector<vector<int>> op;
    op=b1.levelOrder(); //

        return 0;
}