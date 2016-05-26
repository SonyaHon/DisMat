#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <ctime>
#include <queue>

bool equal(int **matrix1, int ** matrix2, int n);
int tComp(int **matrix, bool *checked, int vN);
void proccessVert(bool *checked, int vN, int currVert, int **matrix);
int dim(int **matrix, int vN);
int min(int a, int b);


void SSwap(int **matrix, int i1, int i2, int vN) {

	for (size_t i = 0; i < vN; ++i) {
		int store = matrix[i1][i];
		matrix[i1][i] = matrix[i2][i];
		matrix[i2][i] = store;
	}

	for (size_t i = 0; i < vN; ++i) {
		int store = matrix[i][i1];
		matrix[i][i1] = matrix[i][i2];
		matrix[i][i2] = store;
	}


}

void swap3 (int **matrix, int i1, int i2) {
	int store = matrix[i1][0];
	matrix[i1][0] = matrix[i2][0];
	matrix[i2][0] = store;

	store = matrix[i1][1];
	matrix[i1][1] = matrix[i2][1];
	matrix[i2][1] = store;

	store = matrix[i1][2];
	matrix[i1][2] = matrix[i2][2];
	matrix[i2][2] = store;

	store = matrix[0][i1];
	matrix[0][i1] = matrix[0][i2];
	matrix[0][i2] = store;

	store = matrix[1][i1];
	matrix[1][i1] = matrix[1][i2];
	matrix[1][i2] = store;

	store = matrix[2][i1];
	matrix[2][i1] = matrix[2][i2];
	matrix[2][i2] = store;
}

void swap4 (int **matrix, int i1, int i2) {
	int store = matrix[i1][0];
	matrix[i1][0] = matrix[i2][0];
	matrix[i2][0] = store;

	store = matrix[i1][1];
	matrix[i1][1] = matrix[i2][1];
	matrix[i2][1] = store;

	store = matrix[i1][2];
	matrix[i1][2] = matrix[i2][2];
	matrix[i2][2] = store;

	store = matrix[i1][3];
	matrix[i1][3] = matrix[i2][3];
	matrix[i2][3] = store;

	store = matrix[0][i1];
	matrix[0][i1] = matrix[0][i2];
	matrix[0][i2] = store;

	store = matrix[1][i1];
	matrix[1][i1] = matrix[1][i2];
	matrix[1][i2] = store;

	store = matrix[2][i1];
	matrix[2][i1] = matrix[2][i2];
	matrix[2][i2] = store;

	store = matrix[3][i1];
	matrix[3][i1] = matrix[3][i2];
	matrix[3][i2] = store;
}

void swap5 (int **matrix, int i1, int i2) {
	int store = matrix[i1][0];
	matrix[i1][0] = matrix[i2][0];
	matrix[i2][0] = store;

	store = matrix[i1][1];
	matrix[i1][1] = matrix[i2][1];
	matrix[i2][1] = store;

	store = matrix[i1][2];
	matrix[i1][2] = matrix[i2][2];
	matrix[i2][2] = store;

	store = matrix[i1][3];
	matrix[i1][3] = matrix[i2][3];
	matrix[i2][3] = store;

	store = matrix[i1][4];
	matrix[i1][4] = matrix[i2][4];
	matrix[i2][4] = store;

	store = matrix[0][i1];
	matrix[0][i1] = matrix[0][i2];
	matrix[0][i2] = store;

	store = matrix[1][i1];
	matrix[1][i1] = matrix[1][i2];
	matrix[1][i2] = store;

	store = matrix[2][i1];
	matrix[2][i1] = matrix[2][i2];
	matrix[2][i2] = store;

	store = matrix[3][i1];
	matrix[3][i1] = matrix[3][i2];
	matrix[3][i2] = store;

	store = matrix[4][i1];
	matrix[4][i1] = matrix[4][i2];
	matrix[4][i2] = store;
}

void swap6 (int **matrix, int i1, int i2) {
	int store = matrix[i1][0];
	matrix[i1][0] = matrix[i2][0];
	matrix[i2][0] = store;

	store = matrix[i1][1];
	matrix[i1][1] = matrix[i2][1];
	matrix[i2][1] = store;

	store = matrix[i1][2];
	matrix[i1][2] = matrix[i2][2];
	matrix[i2][2] = store;

	store = matrix[i1][3];
	matrix[i1][3] = matrix[i2][3];
	matrix[i2][3] = store;

	store = matrix[i1][4];
	matrix[i1][4] = matrix[i2][4];
	matrix[i2][4] = store;

	store = matrix[i1][5];
	matrix[i1][5] = matrix[i2][5];
	matrix[i2][5] = store;

	store = matrix[0][i1];
	matrix[0][i1] = matrix[0][i2];
	matrix[0][i2] = store;

	store = matrix[1][i1];
	matrix[1][i1] = matrix[1][i2];
	matrix[1][i2] = store;

	store = matrix[2][i1];
	matrix[2][i1] = matrix[2][i2];
	matrix[2][i2] = store;

	store = matrix[3][i1];
	matrix[3][i1] = matrix[3][i2];
	matrix[3][i2] = store;

	store = matrix[4][i1];
	matrix[4][i1] = matrix[4][i2];
	matrix[4][i2] = store;

	store = matrix[5][i1];
	matrix[5][i1] = matrix[5][i2];
	matrix[5][i2] = store;
}

void swap7 (int **matrix, int i1, int i2) {
	int store = matrix[i1][0];
	matrix[i1][0] = matrix[i2][0];
	matrix[i2][0] = store;

	store = matrix[i1][1];
	matrix[i1][1] = matrix[i2][1];
	matrix[i2][1] = store;

	store = matrix[i1][2];
	matrix[i1][2] = matrix[i2][2];
	matrix[i2][2] = store;

	store = matrix[i1][3];
	matrix[i1][3] = matrix[i2][3];
	matrix[i2][3] = store;

	store = matrix[i1][4];
	matrix[i1][4] = matrix[i2][4];
	matrix[i2][4] = store;

	store = matrix[i1][5];
	matrix[i1][5] = matrix[i2][5];
	matrix[i2][5] = store;

	store = matrix[i1][6];
	matrix[i1][6] = matrix[i2][6];
	matrix[i2][6] = store;

	store = matrix[0][i1];
	matrix[0][i1] = matrix[0][i2];
	matrix[0][i2] = store;

	store = matrix[1][i1];
	matrix[1][i1] = matrix[1][i2];
	matrix[1][i2] = store;

	store = matrix[2][i1];
	matrix[2][i1] = matrix[2][i2];
	matrix[2][i2] = store;

	store = matrix[3][i1];
	matrix[3][i1] = matrix[3][i2];
	matrix[3][i2] = store;

	store = matrix[4][i1];
	matrix[4][i1] = matrix[4][i2];
	matrix[4][i2] = store;

	store = matrix[5][i1];
	matrix[5][i1] = matrix[5][i2];
	matrix[5][i2] = store;

	store = matrix[6][i1];
	matrix[6][i1] = matrix[6][i2];
	matrix[6][i2] = store;
}

void swap8 (int **matrix, int i1, int i2) {
	int store = matrix[i1][0];
	matrix[i1][0] = matrix[i2][0];
	matrix[i2][0] = store;

	store = matrix[i1][1];
	matrix[i1][1] = matrix[i2][1];
	matrix[i2][1] = store;

	store = matrix[i1][2];
	matrix[i1][2] = matrix[i2][2];
	matrix[i2][2] = store;

	store = matrix[i1][3];
	matrix[i1][3] = matrix[i2][3];
	matrix[i2][3] = store;

	store = matrix[i1][4];
	matrix[i1][4] = matrix[i2][4];
	matrix[i2][4] = store;

	store = matrix[i1][5];
	matrix[i1][5] = matrix[i2][5];
	matrix[i2][5] = store;

	store = matrix[i1][6];
	matrix[i1][6] = matrix[i2][6];
	matrix[i2][6] = store;

	store = matrix[i1][7];
	matrix[i1][7] = matrix[i2][7];
	matrix[i2][7] = store;

	store = matrix[0][i1];
	matrix[0][i1] = matrix[0][i2];
	matrix[0][i2] = store;

	store = matrix[1][i1];
	matrix[1][i1] = matrix[1][i2];
	matrix[1][i2] = store;

	store = matrix[2][i1];
	matrix[2][i1] = matrix[2][i2];
	matrix[2][i2] = store;

	store = matrix[3][i1];
	matrix[3][i1] = matrix[3][i2];
	matrix[3][i2] = store;

	store = matrix[4][i1];
	matrix[4][i1] = matrix[4][i2];
	matrix[4][i2] = store;

	store = matrix[5][i1];
	matrix[5][i1] = matrix[5][i2];
	matrix[5][i2] = store;

	store = matrix[6][i1];
	matrix[6][i1] = matrix[6][i2];
	matrix[6][i2] = store;

	store = matrix[7][i1];
	matrix[7][i1] = matrix[7][i2];
	matrix[7][i2] = store;
}

void swap9 (int **matrix, int i1, int i2) {
	int store = matrix[i1][0];
	matrix[i1][0] = matrix[i2][0];
	matrix[i2][0] = store;

	store = matrix[i1][1];
	matrix[i1][1] = matrix[i2][1];
	matrix[i2][1] = store;

	store = matrix[i1][2];
	matrix[i1][2] = matrix[i2][2];
	matrix[i2][2] = store;

	store = matrix[i1][3];
	matrix[i1][3] = matrix[i2][3];
	matrix[i2][3] = store;

	store = matrix[i1][4];
	matrix[i1][4] = matrix[i2][4];
	matrix[i2][4] = store;

	store = matrix[i1][5];
	matrix[i1][5] = matrix[i2][5];
	matrix[i2][5] = store;

	store = matrix[i1][6];
	matrix[i1][6] = matrix[i2][6];
	matrix[i2][6] = store;

	store = matrix[i1][7];
	matrix[i1][7] = matrix[i2][7];
	matrix[i2][7] = store;

	store = matrix[i1][8];
	matrix[i1][8] = matrix[i2][8];
	matrix[i2][8] = store;

	store = matrix[0][i1];
	matrix[0][i1] = matrix[0][i2];
	matrix[0][i2] = store;

	store = matrix[1][i1];
	matrix[1][i1] = matrix[1][i2];
	matrix[1][i2] = store;

	store = matrix[2][i1];
	matrix[2][i1] = matrix[2][i2];
	matrix[2][i2] = store;

	store = matrix[3][i1];
	matrix[3][i1] = matrix[3][i2];
	matrix[3][i2] = store;

	store = matrix[4][i1];
	matrix[4][i1] = matrix[4][i2];
	matrix[4][i2] = store;

	store = matrix[5][i1];
	matrix[5][i1] = matrix[5][i2];
	matrix[5][i2] = store;

	store = matrix[6][i1];
	matrix[6][i1] = matrix[6][i2];
	matrix[6][i2] = store;

	store = matrix[7][i1];
	matrix[7][i1] = matrix[7][i2];
	matrix[7][i2] = store;

	store = matrix[8][i1];
	matrix[8][i1] = matrix[8][i2];
	matrix[8][i2] = store;
}

void swap10 (int **matrix, int i1, int i2) {
	int store = matrix[i1][0];
	matrix[i1][0] = matrix[i2][0];
	matrix[i2][0] = store;

	store = matrix[i1][1];
	matrix[i1][1] = matrix[i2][1];
	matrix[i2][1] = store;

	store = matrix[i1][2];
	matrix[i1][2] = matrix[i2][2];
	matrix[i2][2] = store;

	store = matrix[i1][3];
	matrix[i1][3] = matrix[i2][3];
	matrix[i2][3] = store;

	store = matrix[i1][4];
	matrix[i1][4] = matrix[i2][4];
	matrix[i2][4] = store;

	store = matrix[i1][5];
	matrix[i1][5] = matrix[i2][5];
	matrix[i2][5] = store;

	store = matrix[i1][6];
	matrix[i1][6] = matrix[i2][6];
	matrix[i2][6] = store;

	store = matrix[i1][7];
	matrix[i1][7] = matrix[i2][7];
	matrix[i2][7] = store;

	store = matrix[i1][8];
	matrix[i1][8] = matrix[i2][8];
	matrix[i2][8] = store;

	store = matrix[i1][9];
	matrix[i1][9] = matrix[i2][9];
	matrix[i2][9] = store;

	store = matrix[0][i1];
	matrix[0][i1] = matrix[0][i2];
	matrix[0][i2] = store;

	store = matrix[1][i1];
	matrix[1][i1] = matrix[1][i2];
	matrix[1][i2] = store;

	store = matrix[2][i1];
	matrix[2][i1] = matrix[2][i2];
	matrix[2][i2] = store;

	store = matrix[3][i1];
	matrix[3][i1] = matrix[3][i2];
	matrix[3][i2] = store;

	store = matrix[4][i1];
	matrix[4][i1] = matrix[4][i2];
	matrix[4][i2] = store;

	store = matrix[5][i1];
	matrix[5][i1] = matrix[5][i2];
	matrix[5][i2] = store;

	store = matrix[6][i1];
	matrix[6][i1] = matrix[6][i2];
	matrix[6][i2] = store;

	store = matrix[7][i1];
	matrix[7][i1] = matrix[7][i2];
	matrix[7][i2] = store;

	store = matrix[8][i1];
	matrix[8][i1] = matrix[8][i2];
	matrix[8][i2] = store;

	store = matrix[9][i1];
	matrix[9][i1] = matrix[9][i2];
	matrix[9][i2] = store;
}

void swap11 (int **matrix, int i1, int i2) {
	int store = matrix[i1][0];
	matrix[i1][0] = matrix[i2][0];
	matrix[i2][0] = store;

	store = matrix[i1][1];
	matrix[i1][1] = matrix[i2][1];
	matrix[i2][1] = store;

	store = matrix[i1][2];
	matrix[i1][2] = matrix[i2][2];
	matrix[i2][2] = store;

	store = matrix[i1][3];
	matrix[i1][3] = matrix[i2][3];
	matrix[i2][3] = store;

	store = matrix[i1][4];
	matrix[i1][4] = matrix[i2][4];
	matrix[i2][4] = store;

	store = matrix[i1][5];
	matrix[i1][5] = matrix[i2][5];
	matrix[i2][5] = store;

	store = matrix[i1][6];
	matrix[i1][6] = matrix[i2][6];
	matrix[i2][6] = store;

	store = matrix[i1][7];
	matrix[i1][7] = matrix[i2][7];
	matrix[i2][7] = store;

	store = matrix[i1][8];
	matrix[i1][8] = matrix[i2][8];
	matrix[i2][8] = store;

	store = matrix[i1][9];
	matrix[i1][9] = matrix[i2][9];
	matrix[i2][9] = store;

	store = matrix[i1][10];
	matrix[i1][10] = matrix[i2][10];
	matrix[i2][10] = store;

	store = matrix[0][i1];
	matrix[0][i1] = matrix[0][i2];
	matrix[0][i2] = store;

	store = matrix[1][i1];
	matrix[1][i1] = matrix[1][i2];
	matrix[1][i2] = store;

	store = matrix[2][i1];
	matrix[2][i1] = matrix[2][i2];
	matrix[2][i2] = store;

	store = matrix[3][i1];
	matrix[3][i1] = matrix[3][i2];
	matrix[3][i2] = store;

	store = matrix[4][i1];
	matrix[4][i1] = matrix[4][i2];
	matrix[4][i2] = store;

	store = matrix[5][i1];
	matrix[5][i1] = matrix[5][i2];
	matrix[5][i2] = store;

	store = matrix[6][i1];
	matrix[6][i1] = matrix[6][i2];
	matrix[6][i2] = store;

	store = matrix[7][i1];
	matrix[7][i1] = matrix[7][i2];
	matrix[7][i2] = store;

	store = matrix[8][i1];
	matrix[8][i1] = matrix[8][i2];
	matrix[8][i2] = store;

	store = matrix[9][i1];
	matrix[9][i1] = matrix[9][i2];
	matrix[9][i2] = store;

	store = matrix[10][i1];
	matrix[10][i1] = matrix[10][i2];
	matrix[10][i2] = store;
}

void swap12 (int **matrix, int i1, int i2) {
	int store = matrix[i1][0];
	matrix[i1][0] = matrix[i2][0];
	matrix[i2][0] = store;

	store = matrix[i1][1];
	matrix[i1][1] = matrix[i2][1];
	matrix[i2][1] = store;

	store = matrix[i1][2];
	matrix[i1][2] = matrix[i2][2];
	matrix[i2][2] = store;

	store = matrix[i1][3];
	matrix[i1][3] = matrix[i2][3];
	matrix[i2][3] = store;

	store = matrix[i1][4];
	matrix[i1][4] = matrix[i2][4];
	matrix[i2][4] = store;

	store = matrix[i1][5];
	matrix[i1][5] = matrix[i2][5];
	matrix[i2][5] = store;

	store = matrix[i1][6];
	matrix[i1][6] = matrix[i2][6];
	matrix[i2][6] = store;

	store = matrix[i1][7];
	matrix[i1][7] = matrix[i2][7];
	matrix[i2][7] = store;

	store = matrix[i1][8];
	matrix[i1][8] = matrix[i2][8];
	matrix[i2][8] = store;

	store = matrix[i1][9];
	matrix[i1][9] = matrix[i2][9];
	matrix[i2][9] = store;

	store = matrix[i1][10];
	matrix[i1][10] = matrix[i2][10];
	matrix[i2][10] = store;

	store = matrix[i1][11];
	matrix[i1][11] = matrix[i2][11];
	matrix[i2][11] = store;

	store = matrix[0][i1];
	matrix[0][i1] = matrix[0][i2];
	matrix[0][i2] = store;

	store = matrix[1][i1];
	matrix[1][i1] = matrix[1][i2];
	matrix[1][i2] = store;

	store = matrix[2][i1];
	matrix[2][i1] = matrix[2][i2];
	matrix[2][i2] = store;

	store = matrix[3][i1];
	matrix[3][i1] = matrix[3][i2];
	matrix[3][i2] = store;

	store = matrix[4][i1];
	matrix[4][i1] = matrix[4][i2];
	matrix[4][i2] = store;

	store = matrix[5][i1];
	matrix[5][i1] = matrix[5][i2];
	matrix[5][i2] = store;

	store = matrix[6][i1];
	matrix[6][i1] = matrix[6][i2];
	matrix[6][i2] = store;

	store = matrix[7][i1];
	matrix[7][i1] = matrix[7][i2];
	matrix[7][i2] = store;

	store = matrix[8][i1];
	matrix[8][i1] = matrix[8][i2];
	matrix[8][i2] = store;

	store = matrix[9][i1];
	matrix[9][i1] = matrix[9][i2];
	matrix[9][i2] = store;

	store = matrix[10][i1];
	matrix[10][i1] = matrix[10][i2];
	matrix[10][i2] = store;

	store = matrix[11][i1];
	matrix[11][i1] = matrix[11][i2];
	matrix[11][i2] = store;
}

void swap13 (int **matrix, int i1, int i2) {
	int store = matrix[i1][0];
	matrix[i1][0] = matrix[i2][0];
	matrix[i2][0] = store;

	store = matrix[i1][1];
	matrix[i1][1] = matrix[i2][1];
	matrix[i2][1] = store;

	store = matrix[i1][2];
	matrix[i1][2] = matrix[i2][2];
	matrix[i2][2] = store;

	store = matrix[i1][3];
	matrix[i1][3] = matrix[i2][3];
	matrix[i2][3] = store;

	store = matrix[i1][4];
	matrix[i1][4] = matrix[i2][4];
	matrix[i2][4] = store;

	store = matrix[i1][5];
	matrix[i1][5] = matrix[i2][5];
	matrix[i2][5] = store;

	store = matrix[i1][6];
	matrix[i1][6] = matrix[i2][6];
	matrix[i2][6] = store;

	store = matrix[i1][7];
	matrix[i1][7] = matrix[i2][7];
	matrix[i2][7] = store;

	store = matrix[i1][8];
	matrix[i1][8] = matrix[i2][8];
	matrix[i2][8] = store;

	store = matrix[i1][9];
	matrix[i1][9] = matrix[i2][9];
	matrix[i2][9] = store;

	store = matrix[i1][10];
	matrix[i1][10] = matrix[i2][10];
	matrix[i2][10] = store;

	store = matrix[i1][11];
	matrix[i1][11] = matrix[i2][11];
	matrix[i2][11] = store;

	store = matrix[i1][12];
	matrix[i1][12] = matrix[i2][12];
	matrix[i2][12] = store;

	store = matrix[0][i1];
	matrix[0][i1] = matrix[0][i2];
	matrix[0][i2] = store;

	store = matrix[1][i1];
	matrix[1][i1] = matrix[1][i2];
	matrix[1][i2] = store;

	store = matrix[2][i1];
	matrix[2][i1] = matrix[2][i2];
	matrix[2][i2] = store;

	store = matrix[3][i1];
	matrix[3][i1] = matrix[3][i2];
	matrix[3][i2] = store;

	store = matrix[4][i1];
	matrix[4][i1] = matrix[4][i2];
	matrix[4][i2] = store;

	store = matrix[5][i1];
	matrix[5][i1] = matrix[5][i2];
	matrix[5][i2] = store;

	store = matrix[6][i1];
	matrix[6][i1] = matrix[6][i2];
	matrix[6][i2] = store;

	store = matrix[7][i1];
	matrix[7][i1] = matrix[7][i2];
	matrix[7][i2] = store;

	store = matrix[8][i1];
	matrix[8][i1] = matrix[8][i2];
	matrix[8][i2] = store;

	store = matrix[9][i1];
	matrix[9][i1] = matrix[9][i2];
	matrix[9][i2] = store;

	store = matrix[10][i1];
	matrix[10][i1] = matrix[10][i2];
	matrix[10][i2] = store;

	store = matrix[11][i1];
	matrix[11][i1] = matrix[11][i2];
	matrix[11][i2] = store;

	store = matrix[12][i1];
	matrix[12][i1] = matrix[12][i2];
	matrix[12][i2] = store;
}

void (*swap[11])(int **matrix, int i1, int i2) =
{swap3, swap4, swap5, swap6, swap7, swap8, swap9, swap10, swap11, swap12, swap13};

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
	if (vN > 5) {
		if (tComp(matrix1, cVrts1, vN) != tComp(matrix2, cVrts2, vN)) {
			printf("NO\n");
			return 0;
		}

		//End checking for tie component

		//Checking diametr

		if (dim(matrix1, vN) != dim(matrix2, vN)) {
			printf("NO\n");
			return 0;
		}

		//End checkign for diametr

		//TODO: Checking for some invariants
	}
	//Last step - checking all

	int swapFlag;
	swapFlag = vN - 3;
	bool swapFg = false;
	if (swapFlag < 0 || swapFg > 10) swapFg = true;

	int idx[vN];

	for (int i = 0; i < vN; ++i) {
		idx[i] = 0;
	}

	if (!swapFg) {
		for (int i = 1; i < vN;) {
			if (idx[i] < i) {
				if (equal(matrix1, matrix2, vN)) {
					printf("YES\n");
					return 0;
				}

				int k = i % 2 * idx[i];
				swap[swapFlag](matrix2, i, k);
				idx[i]++;
				i = 1;
			}
			else {
				idx[i++] = 0;
			}
		}
	}
	else if (swapFg) {
		for (int i = 1; i < vN;) {
			if (idx[i] < i) {
				if (equal(matrix1, matrix2, vN)) {
					printf("YES\n");
					return 0;
				}

				int k = i % 2 * idx[i];
				SSwap(matrix2, i, k, vN);
				idx[i]++;
				i = 1;
			}
			else {
				idx[i++] = 0;
			}
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

int min(int a, int b) {
	return (a > b ? b : a);
}

int dim(int **matrix, int vN) {
	int **newM = new int *[vN];
	for (int i = 0; i < vN; ++i) {
		newM[i] = new int [vN];
	}

	for (int i = 0; i < vN; ++i) {
		for (int j = 0; j < vN; ++j) {
			newM[i][j] = matrix[i][j];
			if (!newM[i][j]) {
				newM[i][j] = 10000;
			}
		}
	}

	for (int k = 0; k < vN; ++k) {
		for (int i = 0; i < vN; ++i) {
			for (int j = 0; j < vN; ++j) {
				if (i != j) {
					newM[i][j] = min(newM[i][j], newM[i][k] + newM[k][j]);
				}
			}
		}
	}

	for (int i = 0; i < vN; ++i) {
		for (int j = 0; j < vN; ++j) {
			if (newM[i][j] == 10000) {
				newM[i][j] = 0;
			}
		}
	}

	int max = newM[0][1];

	for (int i = 0; i < vN; ++i) {
		for (int j = 0; j < vN; ++j) {
			if (newM[i][j] > max) {
				max = newM[i][j];
			}
		}
	}

	delete[] newM;
	return max;
}