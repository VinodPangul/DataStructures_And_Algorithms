#include <iostream>
#include "wgraph.cpp"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    vector<Edge<int>> edges = {
            { 0, 1, 6 }, { 1, 2, 7 }, { 2, 0, 5 }, { 2, 1, 4 },
            { 3, 2, 10 }, { 4, 5, 1 }, { 5, 4, 3 }
    };

    int N = 6;
    wgraph<int> w(edges, N);
    w.printGraph(edges, N);

#if 0
    vector<Edge<string>> edges2 = {
            {"A", "D", "weight5"}, {"B", "B", "weight5"},
            {"C", "A", "weight50"}, {"A", "C", "weight15"},
    };
    N = 4;
    wgraph<string> w2(edges2,N);
    w2.printGraph(edges2, N);
#endif
    return 0;
}