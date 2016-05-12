#include "Graph.h"

Graph::Graph(int **matrix_, int vN) {

	vertexNumber = vN;
	matrix = new int*[vN];
}