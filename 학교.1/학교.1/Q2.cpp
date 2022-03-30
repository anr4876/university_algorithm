#include <stdio.h>
using namespace std;
#include <iostream>

int main(void) {

	int n;
	int m;
	int num = 0;

	printf("숫자 n를 입력해주세요 : ");
	
	cin >> n;
	
	printf("숫자 m를 입력해주세요 : ");
	cin >> m;

	for (int i = 0; i < m; i++) {
		num += (n + i);
	}
	printf("%d", num);

	return 0;
}