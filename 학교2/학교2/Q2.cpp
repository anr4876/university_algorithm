#include <iostream>

using namespace std;

void list1(int num[] , int i) { // ����Ʈ ���
	cout << "list==================================" << endl;
	for (int j = 0; j < i - 1; j++) {
		cout << j + 1 << ". : " << num[j] << endl;
	}
	cout << "list==================================" << endl;
}

int main() {

	int num[20];
	int i;
	int x;
	int k;
	int w;

	for (i = 1; i <= 7; i++) {
		num[i - 1] = i;
		
	}

	

	while (1) {
		cout << "��� ���� : 1, ��� ���� : 2 \n ��ȣ�� �����Ͻÿ� : ";
		cin >> x;

		if (x == 1) { // ��� ���� �ڵ�

			list1(num, i);

			cout << "������ ���� ��ȣ�� �Է��Ͻÿ� : ";
			cin >> k;

			cout << "������ ���ڸ� �Է��Ͻÿ� : ";
			cin >> w;

			for (int x = k; x < i + 1; x++) 
			{
				num[19] = num[x-1];
				num[x-1] = w;
				w = num[19];
			}

			cout << k << "��°�� ���� �Ǿ����ϴ�. " << endl;
			i++;
			list1(num, i);
		}

		else {  // ��� ���� �ڵ�
			list1(num, i);

			cout << "������ ��ȣ�� �Է����ּ��� " << endl;
			cin >> k;

			for (int y = k; y < i; y++) num[y-1] = num[y];
			
			i--;
			list1(num, i);
			cout << "���������� ���� �Ǿ����ϴ�" << endl;
		}
	}


	return 0;
}