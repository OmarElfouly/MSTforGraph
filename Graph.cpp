#include "Graph.h"

graph::graph(int n)
{
    this->n = n;
    adj = new int* [n];
    for (int i = 0; i < n; i++) {
        adj[i] = new int[n];
        for (int j = 0; j < n; j++) {
            adj[i][j] = 0;
        }
    }
}

graph::~graph()
{
    for (int i = 0; i < n; i++) {
        delete[] adj[i];
    }
    delete[] adj;
}

void graph::add_edge(int i, int j, int w)
{
    adj[i][j] = w;
}

void graph::print()
{
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout.width(3);
            cout << adj[i][j] << " ";
        }
        cout << "\n";
    }
}
