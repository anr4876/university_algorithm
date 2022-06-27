#include <iostream>
using namespace std;
#define N 10


void selectionsort(int n, int num[]) {
	int number, change , copy[10] , count = 1;
	cout << "처음 : ";
	for (int x = 0; x < n; x++) {
		copy[x] = num[x];
		cout << copy[x] << "  " ;
	}
	cout << endl;
	for (int i = 0; i < n; i++) {
		number = i;
		for (int j = number; j < n;j++ ) {
			if (copy[number] > copy[j]) {
				number = j;
			}
		}
		if (number == i) {
			continue;
		}
		change = copy[i];
		copy[i] = copy[number];
		copy[number] = change;		
	
		cout << count << "번 : ";
		for (int j = 0; j < n; j++) {
			cout << copy[j] << "  ";
		}
		count++;
		cout << endl;
	}
}

void Bubble_sort(int n, int num[]) {
	int copy[10], number , change;

	cout << "처음 : ";
	for (int x = 0; x < n; x++) {
		copy[x] = num[x];
		cout << copy[x] << "  ";
	}
	cout << endl;

	for (int i = 1; i <= n; i++) {
	
		for (int j = 0; j < n - i; j++) {
			if (copy[j] > copy[j + 1]) {
				change = copy[j];
				copy[j] = copy[j + 1];
				copy[j + 1] = change;
			}
		}

		cout << i  << "번 : ";
		for (int j = 0; j < n; j++) {
			cout << copy[j] << "  ";
		}
		cout << endl;
	}
}

void insertion_sort(int n, int num[]) {
	int number, count = 0, change, copy[10],c;
	cout << "처음 : ";
	for (int x = 0; x < n; x++) {
		copy[x] = num[x];
		cout << copy[x] << "  ";
	}
	cout << endl;
	for (int i = 0; i < n; i++) {
		number = i;
		for (c = 0; c < n - count; c++) {
			if (copy[number] < copy[c]) {
				number = c;
			}
		}
		if (number == i) {
			continue;
		}
		change = copy[c-1];
		copy[c-1] = copy[number];
		copy[number] = change;
		count++;
		cout << count << "번 : ";
		for (int j = 0; j < n; j++) {
			cout << copy[j] << "  ";
		}
		cout << endl;
	}
}

int main(void) {


	int rand_num_1[] = { 30, 20 , 23, 15, 9, 25, 11, 18, 29, 1 };

	cout << "=================selectionsort===================" << endl;

	selectionsort(N, rand_num_1);

	cout << "==================Bubble_sort====================" << endl;

	Bubble_sort(N, rand_num_1);

	cout << "=================insertion_sort===================" << endl;

	insertion_sort(N, rand_num_1);
	return 0; 
}