#include <iostream>
using namespace std;

class nQueensPuzzle{
public:
    nQueensPuzzle(int Queens);

    bool canPlaceQueen(int k, int i);

    void queensConfig(int k);

    void printConfig();

    int solutionsCount();
private:
    int noOfSol;
    int noOfQueens;
    int *queensInRow;
};


nQueensPuzzle::nQueensPuzzle(int Queens) {
    noOfQueens=Queens;
    queensInRow = new int[noOfQueens];
    noOfSol=0;
}


void nQueensPuzzle::printConfig() {
    for(int j=0; j<noOfQueens-1; j++)
        cout<<"("<<queensInRow[j]<<" ";

    cout<<queensInRow[noOfQueens]<<" )";
}

int nQueensPuzzle::solutionsCount() {
    return noOfSol;
}


bool nQueensPuzzle::canPlaceQueen(int k, int i) {
    for(int j=0; j<k; j++){
        if((queensInRow[j] == i) || (abs(queensInRow[j]-i) == abs(j-k)))
            return false;

    }
    return true;
}

void nQueensPuzzle::queensConfig(int k) {
    for(int i=0 ; i<noOfQueens; i++){
        if(canPlaceQueen(k, i)){
            queensInRow[k]=i;
            if(k == noOfQueens-1){
                printConfig();
            }else{
                queensConfig(k+1);
            }
        }
    }
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    nQueensPuzzle nq(8);
    nq.queensConfig(8);

    return 0;
}