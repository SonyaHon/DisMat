#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <ctime>
#include <queue>

bool equal(int **matrix1, int ** matrix2, int n);
void swap(int **matrix, int i1, int i2, int n);
int tComp(int **matrix, bool *checked, int vN);
void proccessVert(bool *checked, int vN, int currVert, int **matrix);

std::queue<int> vertsToCheck;


int main(int argc, char ** argv) {

	float dur;
	clock_t start, finish;
	start = clock();

	// Reading graphs
	int vN;
	int **matrix1;
	int **matrix2;

	std::cin >> vN;

	matrix1 = new int*[vN];
	matrix2 = new int*[vN];

	bool cVrts1[vN];
	bool cVrts2[vN];
	for (size_t i = 0; i < vN; ++i) {
		cVrts1[i] = false;
		cVrts2[i] = false;
	}

	for (size_t i = 0; i < vN; ++i) {
		matrix1[i] = new int[vN];
		for (size_t j = 0; j < vN; ++j) {
			int temp;
			std::cin >> temp;
			matrix1[i][j] = temp;
		}
	}

	for (size_t i = 0; i < vN; ++i) {
		matrix2[i] = new int[vN];
		for (size_t j = 0; j < vN; ++j) {
			int temp;
			std::cin >> temp;
			matrix2[i][j] = temp;
		}
	}
	
		if (equal(matrix1, matrix2, vN)) {
			printf("YES\n");
			return 0;
		} 

	// Graphs readed

	// Checking for tie component
	if(tComp(matrix1, cVrts1, vN) != tComp(matrix2, cVrts2, vN)) {
		printf("NO\n");
		return 0;
	}
	//End checking for tie component

	//Checking diametr
	


	//End checkign for diametr

	//TODO: Checking for some invariants
	//TODO: Razvertka forov na swap

	//Last step - checking all

	int idx[vN];
	for (int i = 0; i < vN; ++i) {
		idx[i] = 0;
	}

	for (int i = 1; i < vN;) {
		if (idx[i] < i) {
			if (equal(matrix1, matrix2, vN)) {
				printf("YES\n");
				return 0;
			}

			int k = i % 2 * idx[i];
			swap(matrix2, k, i, vN);
			idx[i]++;
			i = 1;
		}
		else {
			idx[i++] = 0;
		}
	}


	//Done all.. Finising
	printf("NO\n");

	finish = clock();

	dur = (float)(finish - start) /  CLOCKS_PER_SEC;

	std::cout << dur << std::endl;

	return 0;
}

bool equal(int **matrix1, int ** matrix2, int n) {
	for (size_t i = 0; i < n; ++i) {
		for (size_t j = 0; j < n; ++j) {
			if (matrix1[i][j] != matrix2[i][j]) return false;
		}
	}

	return true;
}	


void swap(int **matrix, int i1, int i2, int n) {

	for (size_t i = 0; i < n; ++i) {
		int store = matrix[i1][i];
		matrix[i1][i] = matrix[i2][i];
		matrix[i2][i] = store;
	}

	for (size_t i = 0; i < n; ++i) {
		int store = matrix[i][i1];
		matrix[i][i1] = matrix[i][i2];
		matrix[i][i2] = store;
	}
}

int tComp(int **matrix, bool *checked, int vN) {

	int tComp_ = 1;
	int currVert;
	for (int j = 0; j < vN; j++) {
		if (checked[j] == false) currVert = j;
		else continue;
	}

	vertsToCheck.push(currVert);

	while (!vertsToCheck.empty()) {
		proccessVert(checked, vN, vertsToCheck.front(), matrix);
		vertsToCheck.pop();
	}

	int i = 0;
	for (; i < vN; i++) {
		if (checked[i] == false)  {
			break;
		}
	}

	if (i != vN) {
		return tComp_ + tComp(matrix, checked, vN);
	}
	return tComp_;
}

void proccessVert(bool *checked, int vN, int currVert, int **matrix) {
	if (checked[currVert] == true) {
		return;
	}

	checked[currVert] = true;
	for (size_t i = 0; i < vN; ++i) {
		if (matrix[currVert][i] == 1 || currVert == i) {
			vertsToCheck.push(i);
		}
	}

}
