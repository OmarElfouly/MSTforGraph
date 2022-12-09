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
    //E.push_back({w,{i,j}});
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

graph graph::mstKur()
{
    //create a new graph to store the minimum spanning tree
    graph mst(n);
    //create a set of vertices
    set<int> vertices;
    for (int i = 0; i < n; i++) {
        vertices.insert(i);
    }
    //create a set of edges
    set<pair<int, pair<int, int>>> edges;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (adj[i][j] != 0) {
                edges.insert(make_pair(adj[i][j], make_pair(i, j)));
            }
        }
    }
    set<set<int>> trees;
    for (int i = 0; i < n; i++) {
        set<int> tree;
        tree.insert(i);
        trees.insert(tree);
    }
    //while there are still edges to be added
    while (!edges.empty()) {
        //get the edge with the smallest weight
        pair<int, pair<int, int>> edge = *edges.begin();
        edges.erase(edges.begin());
        //get the two vertices of the edge
        int i = edge.second.first;
        int j = edge.second.second;
        int w = edge.first;
        //get the trees that contain the two vertices
        set<int> tree1;
        set<int> tree2;
        for (set<set<int>>::iterator it = trees.begin(); it != trees.end(); it++) {
            if ((*it).find(i) != (*it).end()) {
                tree1 = *it;
            }
            if ((*it).find(j) != (*it).end()) {
                tree2 = *it;
            }
        }
        //if the two vertices are not in the same cluster i.e. no cycle
        if (tree1 != tree2) {
            //add the edge to the minimum spanning tree
            mst.add_edge(i, j, w);
            //merge the two trees
            tree1.insert(tree2.begin(), tree2.end());
            trees.erase(tree2);
        }
    }
    return mst;
    
}
