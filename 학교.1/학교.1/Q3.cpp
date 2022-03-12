#include <stdio.h>
using namespace std;
#include <iostream>

int main() {

	int number[2] ;
	int arr[2] ;

	cout << "숫자를 입력하시오 : ";
	cin >> number[0];

	cout << "숫자를 입력하시오 : ";
	cin >> number[1];

	arr[0] = number[0];
	arr[1] = number[1];
	
	for (int i = 1; i < number[1]; i++) {
		arr[0] *= number[0] - i;
		arr[1] *= number[1] - i;
	}

	cout << arr[0] / arr[1];

	return 0;
}