#pragma once
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;



class graph {
private:
    int n; // number of vertices
    int** adj; // adjacency matrix
    //vector<pair<int, pair<int,int>>> E;
public:
    graph(int n);
    ~graph();
    void add_edge(int i, int j, int w);
    void print();
    graph mstKur();
};
