#include <iostream>
using namespace std;
#include <string>

int main(void) {

	int j = 0;            // �� ����
	int x[11] = { };    // ���� ����
	int k[11] = { };   // �ܾ� ����
	string st1[10];
	int num = 1;
	while(1) {
		cout << "���ڿ��� �Է��ϼ��� : ";
		getline(cin, st1[j]);
		k[j]++;
		for (int i = 0; i < st1[j].length(); i++) { //�ܾ� ���� ����
			if (st1[j][i] == ' ' && st1[j][i] != st1[j][j]) {				
				k[j]++; //  �ܾ� ���̿� ������ �ԷµǸ� ī��Ʈ +1
			}
		}
		cout << "�Է��Ͻ� �ܾ� ������ : " << k[j] << "�Դϴ�. " << endl;
		for (int i = 0; i < st1[j].length(); i++) { //���� ���� ����
			if (st1[j][i] != ' ') {
				x[j]++; // �Է¹��� ���ڸ� ������ �����ϰ� ī��Ʈ
			}
		}
		cout << "�Է��Ͻ� ���� ������ : " << x[j] << "�Դϴ�. " << endl;
		j++; // �ټ� ī��Ʈ
		cout << "�� �Է��Ͻø� 1, �׸� �Է��Ͻø� 0 �� �Է����ּ��� : "; // ����ؼ� �Է��ϱ����� �ڵ�
		cin >> num;
		cin.ignore();
		if (num == 0) {
			break;
		}
	}
	for (int i = 0; i < j; i++) {  // ��ü ����, �ܾ ���ϴ� �ڵ�
		x[10] += x[i];
		k[10] += k[i];
	}
	cout << "�Է��Ͻ� ���ڿ��� ��,�ܾ�,����  ������ : " << j << ',' << k[10] << ',' << x[10] << "�Դϴ�. " << endl;
	return 0;
}