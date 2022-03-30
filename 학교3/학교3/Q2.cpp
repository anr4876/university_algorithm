#include <iostream>
using namespace std;
#include <time.h>
#define N 30
#include <stdio.h>

int fib1(int n) {
	if (n <= 1) return n;
	else return fib1(n - 1) + fib1(n - 1);
}

int fib2(int n) {
	int i, f[N + 1];
	f[0] = 0;
	f[1] = 1;
	if (n > 1) {
		for (i = 2; i <= n; i++)
			f[i] = f[i - 1] + f[i - 2];
		return f[n];
	}
}


void main() {
	int result1, result2;
	clock_t start, fin;
	start = clock();
	result1 = fib1(N);
	fin = clock();
	printf("% 20.10f", (double)(fin - start) / CLOCKS_PER_SEC);
	start = clock();
	result1 = fib2(N);
	fin = clock();
	printf("% 20.10f", (double)(fin - start) / CLOCKS_PER_SEC);

	int temp = rand() % 97;


}