//
// Created by vpangul on 2019-08-15.
//

#ifndef WEIGHTEDGRAPHS_WGRAPH_H
#define WEIGHTEDGRAPHS_WGRAPH_H

#include <iostream>
#include <vector>
using namespace std;


template <class elemType>
struct Edge {
    elemType src, dest, weight;
};

//typedef pair<int, int> Pair;
//typedef pair<elemType, elemType> Pair;
template <class elemType>
using Pair = pair<elemType, elemType>;


template <class elemType>
class wgraph {
public:
    void addAdjNode(elemType src, Edge<elemType> *currentEdge);
    void printGraph(vector<Edge<elemType>> &edges,  int N);
    wgraph(vector<Edge<elemType>> &edges, int N);
private:
   vector<vector<Pair<elemType>>> graph;

};


#endif //WEIGHTEDGRAPHS_WGRAPH_H
