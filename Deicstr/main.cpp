#include <fstream>
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

#define INF 100000

struct pair {
	int idx;
	int lenth;

	pair() {
		idx = -1;
		lenth = -1;
	}
};

std::vector<bool> seenVerts;
std::vector<pair> vertsValue;
std::queue<int> vrtsToDo;
std::vector<int> root;
 
void doVerts(int, std::vector<std::vector<pair> > vrtx);
int rootFinder(int);

int main(int argv, char **argc) {

	if(argv < 3) {
		std::cout << "No file attached." << std::endl;
		exit(0);
	}

	int maxVerts;

	int vertToFind;

	std::string filename = argc[1]; 
	vertToFind = atoi(argc[2]);

	std::ifstream file(filename);

	file >> maxVerts;

	std::vector<std::vector<pair> > vrtx(maxVerts);

	for(size_t i = 0; i < maxVerts; ++i) {
		seenVerts.push_back(false);
	}

	for(size_t i = 0; i < maxVerts; ++i) {
		pair a;
		a.idx = -1;
		a.lenth = INF;
		vertsValue.push_back(a);
	}

	int vert1, vert2, lenth;
	while(file >> vert1 >> vert2 >> lenth) {
		pair a;
		a.idx = vert2;
		a.lenth = lenth;
		vrtx[vert1].push_back(a);
	}

	vrtsToDo.push(0);
	vertsValue[0].lenth = 0;

	while(!vrtsToDo.empty()) {
		doVerts(vrtsToDo.front(), vrtx);
		vrtsToDo.pop();
	}

	std::cout << "Shortest root is " << vertsValue[vertToFind].lenth << " long" << std::endl;

	int i = rootFinder(vertToFind);

	std::cout << 0 << "->";

	for(size_t i = root.size() - 1; i > 0; --i) {
		std::cout << root[i] << "->";
	}

	std::cout << vertToFind << std::endl;

	return 0;
}

int rootFinder(int vertToFind) {

	if(vertsValue[vertToFind].idx == -1) {
		return -1;
	}
	else {
		root.push_back(vertToFind);
		return rootFinder(vertsValue[vertToFind].idx);
	}
}

void doVerts(int v, std::vector<std::vector<pair> > vrtx) {
	
	if(seenVerts[v] == true) {
		return;
	}

	seenVerts[v] = true;

	for(size_t i = 0; i < vrtx[v].size(); ++i) {
		
		if(vertsValue[vrtx[v][i].idx].lenth == INF) {
			vertsValue[vrtx[v][i].idx].lenth = vertsValue[v].lenth + vrtx[v][i].lenth;
			vertsValue[vrtx[v][i].idx].idx = v;
		}
		else if(vertsValue[vrtx[v][i].idx].lenth != INF) {
			if(vertsValue[vrtx[v][i].idx].lenth >= vertsValue[v].lenth + vrtx[v][i].lenth) {
				vertsValue[vrtx[v][i].idx].lenth = vertsValue[v].lenth + vrtx[v][i].lenth;
				vertsValue[vrtx[v][i].idx].idx = v;
			}
		}

		vrtsToDo.push(vrtx[v][i].idx);
	}
}
