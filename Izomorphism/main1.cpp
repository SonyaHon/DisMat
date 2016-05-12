#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <ctime>
#include <queue>

bool equal(int **matrix1, int ** matrix2, int n);
void swap(int **matrix, int i1, int i2, int n);

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

	//TODO: Checking for some 

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
		matrix[i1][i] = matrix[i2][i1];
		matrix[i2][i] = store;
	}

	for (size_t i = 0; i < n; ++i) {
		int store = matrix[i][i1];
		matrix[i][i1] = matrix[i][i2];
		matrix[i][i2] = store;
	}
}