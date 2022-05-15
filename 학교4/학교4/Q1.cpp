#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;

#define NUM 100

void merge(int h, int m, int u[], int v[], int s[]) {
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

void RD(int a ,int num[] ) { // 배열 랜덤숫자 대입후 중복 삭제

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



void mergesort(int n, int s[]) {
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

	RD( NUM, num);

	mergesort(NUM, num);

	fopen_s(&fin, "test.txt", "w");
	for (int i = 0; i < sizeof(num)/sizeof(int); i++) {
		fprintf(fin, "%d\t", num[i]);
		cout << num[i] << "\t";
		if ((i + 1)  % 10 == 0 && i != 0) {
			fprintf(fin, "\n");
			cout << endl;
		}
	}

	fclose(fin);
	

}