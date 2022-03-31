#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;

#define NUM 100

void merge(int h, int m, const int u[], const int v[], int s[]) {
	int i, j, k, ind;
	i = 0; j = 0; k = 0;
	while (i < h && j < m) {
		if (u[i] < v[j]) {
			s[k] = u[i];
			i++;
		}
		else {
			s[k] = v[j];
			j++;
		}
		k++;
	}
	if (i >= h) for (ind = j; ind < m; ind++, k++) {
		s[k] = v[ind];
	}
	else for (ind = i; ind < h; ind++, k++) {
		s[k] = u[ind];
	}
}

void RD(int num[], int a) { // �迭 �������� ������ �ߺ� ����

	for (int i = 0; i < a ; i++) {
		num[i] = rand() % a + 1;
		for (int j = 0; j < i; j++) {
			if (num[i] == num[j] && i != j) {
				i--;
				break;
			}
		}
	}
}



void mergesort(const int n, int s[]) {
	int i;
	if (n > 1) {
		int h = (int)(n / 2), m = n - h;
		int* u = new int[h], * v = new int[m];
		
		for (i = 0; i < h; i++) {
			u[i] = s[i];
		}
		for (i = 0; i < m; i++) {
			v[i] = s[h + i];
		}
		mergesort(h, u);
		mergesort(m, v);
		merge(h, m, u, v, s);
	}
}

void main() {

	int num[NUM];
	FILE* fin, * fout;

	RD(num, NUM);
	mergesort(NUM, num);


	fopen_s(&fin, "test.txt", "w");
	for (int i = 0; i < sizeof(num); i++) {
		fprintf(fin, "%d\t", num[i]);
		cout << num[i] << "\t";
		if ((i + 1)  % 10 == 0 && i != 0) {
			fprintf(fin, "\n");
			cout << endl;
		}
	}
	fclose(fin);
	





}