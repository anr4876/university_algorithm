#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
using namespace std;
#define NUM 100

int num[NUM + 1];

int location(int l, int h , int x) {
	int mid;

	if (l > h) {
		return 0;
	}
	else {
		mid = (int)((l + h) / 2);
		if ( x == num[mid]) {
			return mid;
		}
		else if (num[mid] > x) {
			return location(l, mid - 1,  x);
		}
		else {
			return location( mid + 1 ,h ,  x);
		}
	}
}

void main() {
	
	
	ifstream is;
	is.open("test.txt");
	for (int i = 1; i <= NUM; i++) {
		is >> num[i] ;
	}
			
	is.close();

	cout << location(1, NUM , 59)<< endl;
	cout << num[location(1, NUM, 59)];

}