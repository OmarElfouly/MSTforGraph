#include "Graph.h"
#include <map>

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
    adj[j][i] = w;
    if (w != 0) {
        edges.insert(make_pair(w, make_pair(i, j)));
    }
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
    cout << "\n";

    cout << "Number of Vertices are: " << n << "\nNumber of non-zero edges: "<<edges.size()<<"\n\n";
    //Improve or remove the following
    map<int, char> Alphabet = { {0,'A'},{1,'B'},{2,'C'},{3,'D'},{4,'E'},{5,'F'},{6,'G'},{7,'H'} };
    
    cout << "These " << edges.size() << " are:\n";
    for (auto edge : edges) {
        cout << Alphabet[edge.second.first] << " " << Alphabet[edge.second.second] << " " << edge.first<<"\n";
    }

    

}

graph graph::mstKur()
{
    //create a new graph to store the minimum spanning tree
    graph mst(n);
    //create a set of edges
    set<pair<int, pair<int, int>>> E = edges;
    
    set<set<int>> trees;// trees starts of as vertices
    for (int i = 0; i < n; i++) {
        set<int> tree;
        tree.insert(i);
        trees.insert(tree);
    }
    //while there are still edges to be added
    while (!E.empty()) {
        //get the edge with the smallest weight
        pair<int, pair<int, int>> edge = *E.begin();
        E.erase(edge);
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
        if (tree1.size()!=0 && tree2.size()!=0&&tree1 != tree2) {
            //add the edge to the minimum spanning tree
            mst.add_edge(i, j, w);
            //merge the two trees
            trees.erase(tree1);
            trees.erase(tree2);
            tree1.insert(tree2.begin(), tree2.end());
            //new stuff
            trees.insert(tree1);
        }
    }
    return mst;
    
}
void graph::printKur()
{
    map<int, char> Alphabet = { {0,'A'},{1,'B'},{2,'C'},{3,'D'},{4,'E'},{5,'F'},{6,'G'},{7,'H'} };

    cout << "The minimum spanning tree is:\n";
    for (auto edge : edges) {
        cout << Alphabet[edge.second.first] << " " << Alphabet[edge.second.second] << " " << edge.first << "\n";
    }
}
