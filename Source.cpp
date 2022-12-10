#include "Graph.h"
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>
#include <time.h>
//We will be storing edges in an adjacency matrix


using namespace std;
//first we want a function to read from a file
vector<int> readFileIntoVector(string filename) {
	vector<int> res;
	ifstream f(filename);
	if (f.is_open()) {
		string s;
		while (f) {
			f >> s;
			res.push_back(stoi(s));
		}
		f.close();

	}
	else {
		cout << "\nFailed to open file!\n";
	}
	return res;
}

graph readFileIntoGraph(string filename) {
	//readFile
	vector<int> read = readFileIntoVector(filename);
	//first item is size
	int size = read[0];
	read.erase(read.begin());

	//create graph and edges
	graph G(size);
	int count = 0;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			G.add_edge(i, j, read[count++]);
		}
	}
	return G;
}

graph makeRandomGraph() {
	//setting number of vertices
	cout << "Please input the number of vertices: ";
	int v;
	cin >> v;
	while (v < 1) {
		cout << "Invalid input.\nMake sure to input a positive integer: ";
		cin >> v;
	}
	// set min and max edge weight
	cout << "Input min edge weight: ";
	int minW;
	cin >> minW;
	while (minW < 1) {
		cout << "Invalid input.\nMake sure to input a positive integer: ";
		cin >> minW;
	}
	cout << "Input max edge weight: ";
	int maxW;
	cin >> maxW;
	while (maxW < minW ) {
		cout << "Invalid input.\nMake sure to input a positive integer greater than the min edge weight: ";
		cin >> maxW;
	}
	srand(time(0));
	int** arr;
	arr = new int* [v];
	for (int i = 0; i < v; i++) {
		arr[i] = new int[v];
		for (int j = 0; j < v; j++) {
			arr[i][j] = 0;
		}
	}

	for (int i = 0; i < v; i++) {
		for (int j = i; j < v; j++) {
			int r = rand() % (maxW + 1);
			if (r < minW) {
				r = 0;
			}
			arr[i][j] = r;
			arr[j][i] = r;
		}
	}
	ofstream f("newGraph.txt");
	f << to_string(v);
	for (int i = 0; i < v; i++) {
		for (int j = 0; j < v; j++) {
			f << " "<< arr[i][j] ;
		}
	}
	f.close();
	graph g = readFileIntoGraph("newGraph.txt");
	return g;

}


int main() {
	
	graph G = readFileIntoGraph("Text.txt");
	//output graph
	cout << "Adjacency matrix is:\n";
	G.print();

	//testing kur
	graph kur = G.mstKur();
	cout << "MST KUR IS:\n";
	kur.printKur();

	//testing prim on orignal
	G.mstPrim();

	//testing rand graph file
	graph r = makeRandomGraph();
	r.print();
}