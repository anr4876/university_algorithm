#include <iostream>
using namespace std;
#include <time.h>
#define N 5
#include <stdio.h>

int factorial(int n) {
	if (n <= 1) return n;
	else {
		return n * factorial(n - 1);
	}
}

int factorial2(int n) {
	int i, result;
	result = 1;
	for (i = 1; i <= n; i++) {
		result *= i;

	}
	return result;
}

void main() {
	int result;
	clock_t start, fin;
	start = clock();
	result = factorial(N);
	fin = clock();

	printf("result : %10d \t %20.10f \n", result, (double)(fin - start) / CLOCKS_PER_SEC);

	start = clock();
	factorial2(N);
	fin = clock();

	printf("result : % 10d \t % 20.10f \n", result, (double)(fin - start) / CLOCKS_PER_SEC);
}