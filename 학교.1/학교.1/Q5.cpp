#include <iostream>
using namespace std;



int main(void) {

	int i = 0;
	int num = 0;
	string st1[10];

	while (1) {
		cout << "���ڿ��� �Է��ϼ��� : ";
		cin >> st1[i];
		i++;
		cout << "�� �Է��Ͻø� 1, �׸� �Է��Ͻø� 0 �� �Է����ּ��� : ";
		cin >> num;
		if (num == 0) {
			break;
		}
		
	}
	cout << "�Է��� ���ڿ��� ���� : " << i;

	
	



	return 0;
}