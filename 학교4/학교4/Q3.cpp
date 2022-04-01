#include <iostream>
using namespace std;

int S[] = { 3, 18, 16, 25, 13, 28, 30, 22, 1, 7, 20 };

void partition(int low, int high, int &pivotpoint) {
	int i, j;
	int pivotitem;
	int swap;

	pivotitem = S[low];
	j = low;
	for (i = low + 1; i <= high; i++) {
		if (S[i] < pivotitem) {
			j++;
			swap = S[i];
			S[i] = S[j];
			S[j] = swap;
		}
	}
	pivotpoint = j;
	swap = S[low];
	S[low] = S[pivotpoint];
	S[pivotpoint] = swap;
}

void quicksort(int low, int high) {
	int pivotpoint;
	if (high > low) {
		partition(low, high, pivotpoint);
		quicksort(low, pivotpoint - 1);
		quicksort(pivotpoint + 1, high);
	}
}

void main() {
	int siz = sizeof(S) / sizeof(int);
	quicksort(0, siz-1);
	for (int i = 0; i < siz; i++) {
		cout << S[i] << "\t";
	}

}