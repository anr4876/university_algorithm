#include <iostream>

using namespace std;

int main(void) {

	int N;

	cout << "숫자를 입력하세요 : ";
	cin >> N;

	for (int i = 1; i <= N; i++) {
		if (i == 1) {
			cout << i;
			continue;
		}
		if (N % i == 0 ) {
			for (int j = 2; j < i - 1; j++) {
				if (i % j == 0 ) {
					continue;
				}
				else {
					cout << "," << i;
					break;
				}
			}
			
		}
	}



	return 0;
}