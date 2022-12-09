#pragma once
#include <iostream>
using namespace std;

class graph {
private:
    int n; // number of vertices
    int** adj; // adjacency matrix
public:
    graph(int n);
    ~graph();
    void add_edge(int i, int j, int w);
    void print();
};
