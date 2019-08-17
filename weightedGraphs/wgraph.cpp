//
// Created by vpangul on 2019-08-15.
//

#include <iostream>
#include "wgraph.h"

using namespace std;

template <class elemType>
void wgraph<elemType>::addAdjNode(elemType src, Edge<elemType> *currentEdge){
    for(auto &edge : currentEdge){
        graph[edge.src].push_back(make_pair(edge.dest, edge.weight));
    }
}

template <class elemType>
void wgraph<elemType>::printGraph(vector<Edge<elemType>> &edges, int N){


    for(int i=0; i<N; i++){
        cout<<i<<" ---> ";
        for(Pair<elemType> v : graph[i]){
           // cout<<"( "<<v.first<<", "<<v.second<<" )";
            cout<<"( "<<v.first<<", "<<v.second<<" )";
        }
        cout<<" | "<<endl;
    }
}

template <class elemType>
wgraph<elemType>::wgraph(vector<Edge<elemType>> &edges, int N){

    graph.resize(N);

    for(auto &edge : edges){
        elemType src  = edge.src;
        elemType dest = edge.dest;
        elemType weight = edge.weight;

        graph[src].push_back(make_pair(dest, weight));
    }
}


