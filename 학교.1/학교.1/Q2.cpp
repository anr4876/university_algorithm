#include <stdio.h>
using namespace std;
#include <iostream>

int main(void) {

	int n;
	int m;
	int num = 0;

	printf("���� n�� �Է����ּ��� : ");
	
	cin >> n;
	
	printf("���� m�� �Է����ּ��� : ");
	cin >> m;

	for (int i = 0; i < m; i++) {
		num += (n + i);
	}
	printf("%d", num);

	return 0;
}