#include <iostream>
using namespace std;

int main() {
	int sum = 0;
	for (int i = 1; i <= 1000; i++) {
		for (int j = 1; j < i; j++) {
			if (i % j == 0) {
				sum += j;
			}
			if (sum == i) {
				cout << "¿ÏÀü¼ö : " << i << endl;
				break;
			}
			
		}
		sum = 0;
	}



	return 0;
}
