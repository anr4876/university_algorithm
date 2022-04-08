#include <iostream>
#include <time.h>
using namespace std;
#define N 30

#define K 10

int num1 = N;
int num2 = K;

int BinomialCoefficient1(int num1, int num2) {

	if (num2 == 0 || num2 == num1) {
		
		return 1;
	}
	else {
		
	
		return BinomialCoefficient1(num1 - 1, num2 - 1) + BinomialCoefficient1(num1 - 1, num2);
	}
}

int  BinomialCoefficient2(int num1, int num2) { // ���� �� �ٽ� �����

	int num[N + 1][K + 1];
	int i, j;
	for(i = 0; i <= num1; i++) {
		
		for (j = 0; j <= i && j <= num2; j++) {
			if (j == 0 || j == i) {
				num[i][j] = 1;
			}
			else {
				num[i][j] = num[i - 1][j - 1] + num[i - 1][j];
				
			}
			
			
		}
		printf("\n");
	}
	
	return num[num1][num2];
	
}




void main() {
	clock_t start, end;


	start = clock();
	cout << BinomialCoefficient1(num1, num2)<< endl;
	end = clock();

	double ClockNum = (double)(end - start);
	printf("%f", ClockNum);

	cout << endl;

	start = clock();
	cout << BinomialCoefficient2(num1, num2) << endl;
	end = clock();

	ClockNum = (double)(end - start);

	printf("%f", ClockNum);
}