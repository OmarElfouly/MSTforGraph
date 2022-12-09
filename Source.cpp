#include "Graph.h"
#include <fstream>
#include <vector>
#include <string>
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
			//cout << s<<" ";//was used to test
		}
	}
	else {
		cout << "\nFailed to open file!\n";
	}
	return res;
}

int main() {
	//readFile
	vector<int> read = readFileIntoVector("Text.txt");
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

	//output graph
	cout << "Adjacency matrix is:\n";
	G.print();

	//testing kur
	graph kur = G.mstKur();
	cout << "MST KUR IS:\n";
	kur.print();

}