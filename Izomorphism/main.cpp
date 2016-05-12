#include <iostream>
#include <stdio.h>
#include <vector>
#include <stdlib.h>
#include <fstream>
#include <ctime>
#include <queue>

int Det(std::vector<std::vector<int> > matrix_in, int size);
void getMatrix(int i, int size, std::vector<std::vector<int> > matrix_in, std::vector<std::vector<int> > &matrix_out);
int pow(int a, int b);
int Parts(std::vector<std::vector<int> > &V, std::queue<int> &vertsToDo, std::vector<bool> &seenVerts);
void doVert(std::vector<std::vector<int> > &V, std::queue<int> &vertsToDo, std::vector<bool> &seenVerts, int vert);
int recPart(std::vector<std::vector<int> > &V, std::queue<int> &vertsToDo, std::vector<bool> &seenVerts);
bool perebor(std::vector<std::vector<int> > &gr1, std::vector<std::vector<int> > &gr2, int);
void swap(std::vector<std::vector<int> > &gr, int i1, int i2, int size);
int fac(int);
bool Equal(std::vector<std::vector<int> > gr1, std::vector<std::vector<int> > gr2, int nodes);

int N;

struct Vector2 {

	int x;
	int y;
};
struct Graph {
	
	std::vector<std::vector<int> > nodes;
	std::queue<int> vertsToDo;
	std::vector<bool> seenVerts;

	int nodesNumber; //rdy
	int edgesNumber; //rdy
	int rComponent; // rdy
	int determinant; // rdy
	int chromaticNumber;
	Vector2 pass;


	Graph(std::string filename) {
		std::ifstream file(filename);

		file >> nodesNumber;
		file >> edgesNumber;

		nodes.reserve(nodesNumber);

		for(size_t i = 0; i < nodesNumber; ++i) {
			std::vector<int> a;
			nodes.push_back(a);
			for(size_t j = 0; j < nodesNumber; ++j) {
				int a;
				file >> a;
				nodes[i].push_back(a);
			}
		}

		for(int i = 0; i < nodesNumber; ++i) {
			seenVerts.push_back(false);
		}

	 	//determinant = Det(nodes, nodesNumber);
	 	rComponent = Parts(nodes, vertsToDo, seenVerts);	
	}
};

int main(int argc, char **argv) {

	N = 0;

	float dur;
	clock_t start, finish;
	start = clock();

	if(argc < 3) {
		puts("No files selected.");
		exit(0);
	}

	std::string file1 = argv[1];
	std::string file2 = argv[2];

	Graph graph1 = Graph(file1);
	Graph graph2 = Graph(file2);


	// FIRST STEP - amount of nodes and edges
	
		if(graph1.nodesNumber != graph2.nodesNumber || graph1.edgesNumber != graph2.edgesNumber) {
			puts("No isomorphism. Amount of nodes and edges is not equal.");
		    //exit(0);
		}

	// SECONDD STEP - determinant of matrix
		
		if(graph1.determinant != graph2.determinant) {
			puts("No isomorphism. Determinants are not equal.");
			//exit(1);
		}

	// THIRD STEP - rComponent
	
		if(graph1.rComponent != graph2.rComponent) {
			puts("No isomorphism. Connection components are not equals");
			//exit(2);
		}

	// FORTH STEP - Chromatic number


	// LAST STEP - PEREBOR
	
	if(perebor(graph1.nodes, graph2.nodes, graph1.nodesNumber)) {
		std::cout << "Graphs are isomorhic." << std::endl;
	}
	else {
		std::cout << "No isomorphism." << std::endl;
	}

	finish = clock();

	dur = (float)(finish - start) /  CLOCKS_PER_SEC;

	std::cout << dur << std::endl;

	return 0;
}

int Det(std::vector<std::vector<int> > matrix_in, int size) {
	
	if(size == 2) {
		return matrix_in[0][0]*matrix_in[1][1] - matrix_in[0][1]*matrix_in[1][0];
	}
	else if(size == 1) {
		return matrix_in[0][0];
	}
	else {
		int determinant = 0;
		for(size_t i = 0; i < size; ++i) {
			std::vector<std::vector<int> > matrix_out;
			matrix_out.reserve(size - 1);
			getMatrix(i, size, matrix_in, matrix_out);
			determinant += matrix_in[0][i]*pow(-1, i)*Det(matrix_out, size - 1);
		}
		return determinant;
	}
}

void getMatrix(int i, int size, std::vector<std::vector<int> > matrix_in, std::vector<std::vector<int> > &matrix_out) {


	int xo = 0;
	for(size_t x = 1; x < size; ++x) {
		std::vector<int> a;
		matrix_out.push_back(a);
		for(size_t y = 0; y < size; ++y) {
			if(y != i) {
				matrix_out[xo].push_back(matrix_in[x][y]);
			}
		}
		xo++;
	}
}

int pow(int a, int b) {
	int c = a;
	for(int i = 0; i < b + 1; ++i) {
		c*=a;
	}

	return c;
}

int Parts(std::vector<std::vector<int> > &V, std::queue<int> &vertsToDo, std::vector<bool> &seenVerts) {

	vertsToDo.push(0);

	while(!vertsToDo.empty()) {
	
		doVert(V, vertsToDo, seenVerts, vertsToDo.front());
		vertsToDo.pop();
	}

	int flag = 0;
	for(size_t i = 0; i < seenVerts.size(); ++i) {
		if(seenVerts[i] == true) flag++;
	}

	if(flag == seenVerts.size()) return 1;
	else {
		return recPart(V, vertsToDo, seenVerts);
	}


}

int fac(int n) {
	int a = 1;
	for(int i = 1; i < n; ++i) {
		a *= i + 1;
	}

	return a;

}

void swap(std::vector<std::vector<int> > &gr, int i1, int i2, int nodes) {

	float dur;
	clock_t start, finish;
	start = clock();

	for(int i = 0; i < nodes; ++i) {
		int store = gr[i1][i];
		gr[i1][i] = gr[i2][i];
		gr[i2][i] = store;
	}

	for(int i = 0; i < nodes; ++i) {
		int store = gr[i][i1];
		gr[i][i1] = gr[i][i2];
		gr[i][i2] = gr[i][i1];
	}

	finish = clock();

	dur = (float)(finish - start) /  CLOCKS_PER_SEC;

	N++;
	std::cout << dur << " " << N << std::endl;

}

bool perebor(std::vector<std::vector<int> > &gr1, std::vector<std::vector<int> > &gr2, int nodes) {
	bool isIt = Equal(gr1, gr2, nodes);

	if(isIt) return true;

	int idx[nodes];

	for(int i = 0; i < nodes; ++i) {
		idx[i] = 0;
	}

	for(int i = 1; i < nodes;) {
		if(idx[i] < i) {
			if(Equal(gr1, gr2, nodes)) {
				return true;
			}

			int k = i % 2 * idx[i];
			swap(gr2, k, i, nodes);
			idx[i]++;
			i = 1;
		}
		else {
			idx[i++] = 0;
		}
	}

	return false;	
}

int recPart(std::vector<std::vector<int> > &V, std::queue<int> &vertsToDo, std::vector<bool> &seenVerts) {

	int clas = 2;
	int lastVert;

	for(size_t i = 0; i < seenVerts.size(); ++i) {
		if(seenVerts[i] == false) lastVert = i;
	}

	vertsToDo.push(lastVert);
	while(!vertsToDo.empty()) {
		doVert(V, vertsToDo, seenVerts, vertsToDo.front());
		vertsToDo.pop();
	}	

	int i = 0;
	for(; i < seenVerts.size(); ++i) {
		if(seenVerts[i] == false) break;
	}
	if(i != seenVerts.size()) {
		return clas + recPart(V, vertsToDo, seenVerts) - 1;
	}

	return clas;
}

bool Equal(std::vector<std::vector<int> > gr1, std::vector<std::vector<int> > gr2, int nodes) {
	bool isIt = true;
	for(size_t i = 0; i < nodes; ++i) {
		for(size_t j = 0; j < nodes; ++j) {
			if(gr1[i][j] != gr2[i][j]) isIt = false;
		}
	}

 	return isIt;
}

void doVert(std::vector<std::vector<int> > &V, std::queue<int> &vertsToDo, std::vector<bool> &seenVerts, int vert) {

		if(seenVerts[vert] == true) {
			return;
		}

		seenVerts[vert] = true;

		for(size_t i = 0; i < V[vert].size(); ++i) {
			if(i != vert && V[vert][i] != 0) {
				vertsToDo.push(i);
			}
		}
}