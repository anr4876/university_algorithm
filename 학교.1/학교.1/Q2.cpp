#include <stdio.h>
using namespace std;
#include <iostream>

int main(void) {

	int n;
	int m;
	int num = 0;

	printf("���ڸ� �Է����ּ��� : ");
	
	cin >> n;
	
	printf("���ڸ� �Է����ּ��� : ");
	cin >> m;

	for (int i = 0; i < m; i++) {
		num += (n + i);
	}
	printf("%d", num);

	return 0;
}