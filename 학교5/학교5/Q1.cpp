#include <iostream>
#include <time.h>
using namespace std;
#define N 6

#define K 2

int num1 = N;
int num2 = K;

int BinomialCoefficient1(int num1, int num2) {

	if (num1 == 0 || num1 == num2) {
		return 1;
	}
	else {
		return BinomialCoefficient1(num1 - 1, num2 - 1) + BinomialCoefficient1(num1 - 1, num2);
	}
}

int  BinomialCoefficient2(int num1, int num2) { // 전부 다 다시 만들기

	int num[N+1][K+1];
	int i, j;
	for(i = 0; i <= num1; i++) {
		
		for (j = 0; j <= i; j++) {
			if (j == 0 || j == i) {
				num[i][j] = 1;
			}
			else {
				num[i][j] = num[i - 1][j - 1] + num[i - 1][j];
				
			}
			cout << num[i][j] << "\t";
		}
		printf("\n");
	}
	
	return num[num1][num2];
	
}




void main() {
	clock_t start, end;


	//start = clock();
	//cout << BinomialCoefficient1(num1, num2)<< endl;
	//end = clock();

	//double ClockNum = (double)(end - start);
	//printf("%f", ClockNum);

	start = clock();
	cout << BinomialCoefficient2(num1, num2) << endl;
	end = clock();

	double ClockNum = (double)(end - start);

	printf("%f", ClockNum);
}