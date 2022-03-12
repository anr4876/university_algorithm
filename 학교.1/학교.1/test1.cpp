#include <iostream>
using namespace std;
#include <stdio.h>
#include <stdlib.h>

void main() {

	int a[10];
	int i;
	int* pti;

	for (i = 0; i < 10; i++)
		a[i] = (i + 1) * 10;
	
	pti = a;
	for (i = 0; i < 10; i++)
		cout << i << '\t' << a[i] << '\t' << a + i << '\t' << *(a + i) << endl;

}