#include <iostream>
using namespace std;

int S[] = { 11, 14, 20, 30, 10, 36, 21, 15, 18, 7, 3 };

int quicksort(int low, int high) {
	int i, j, x, pivotpoint, swap;
	pivotpoint = S[low]; // �Ǻ��� ����
	if (high - low == 1) {
		if (S[low] > S[high]) { // ������ 2���� ���� ���Ͽ� �������� ���ʿ� �迭���ִ� �ڵ�
			swap = S[low];
			S[low] = S[high];
			S[high] = swap;
			return 0;
		}
	}
	x = high;
	for (i = low + 1; i <= high + 1; i++) {
		if (S[i] > pivotpoint) { // �Ǻ����� S[i] ��°�� ũ�� ����
			for (j = x; j > low; j--, x--) { 
				if (i > j) {       // ���� �迭�� �Ǻ����� �������� ������ S[j]�ڸ��� �ǹ�����Ʈ ����
					swap = S[low];
					S[low] = S[j];
					S[j] = swap;
					quicksort(low, j - 1); // �Ǻ� ���� ������������
					quicksort(j + 1, high); // �Ǻ� ���� ū ���� ����
					return 0;
				}
				else if (S[j] < pivotpoint) { // �Ǻ����� ū S[i]�� �Ǻ����� ���� S[j] ��ġ �ٲ��ִ� �ڵ�
					swap = S[i];
					S[i] = S[j];
					S[j] = swap;
					break;
				}
			}
		}
		if (i > x) { // ���� �Ǻ����� ū ���� ������ �Ǻ��� ������ S[j] ��ġ�� �̵�
			swap = S[low];
			S[low] = S[x];
			S[x] = swap;
			quicksort(low, x - 1);  // �Ǻ� ���� ������������
			quicksort(x + 1, high); // �Ǻ� ���� ū ���� ����
		}
		
	}
}

void main() {
	int siz = sizeof(S) / sizeof(int);
	quicksort(0, siz - 1);
	for (int i = 0; i < siz; i++) { // ������ Ȯ�����ִ� �ڵ�
		cout << S[i] << "\t";
	}
}