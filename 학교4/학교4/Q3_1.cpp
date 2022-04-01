#include <iostream>
using namespace std;

int S[] = { 11, 14, 20, 30, 10, 36, 21, 15, 18, 7, 3 };

int quicksort(int low, int high) {
	int i, j, x, pivotpoint, swap;
	pivotpoint = S[low]; // 피봇값 지정
	if (high - low == 1) {
		if (S[low] > S[high]) { // 마지막 2개의 값을 비교하여 작은수를 외쪽에 배열해주는 코드
			swap = S[low];
			S[low] = S[high];
			S[high] = swap;
			return 0;
		}
	}
	x = high;
	for (i = low + 1; i <= high + 1; i++) {
		if (S[i] > pivotpoint) { // 피봇보다 S[i] 번째가 크면 실행
			for (j = x; j > low; j--, x--) { 
				if (i > j) {       // 남은 배열중 피봇보다 작은수가 없으면 S[j]자리에 피벗포인트 저장
					swap = S[low];
					S[low] = S[j];
					S[j] = swap;
					quicksort(low, j - 1); // 피봇 보다 작은수들정렬
					quicksort(j + 1, high); // 피봇 보다 큰 수들 정렬
					return 0;
				}
				else if (S[j] < pivotpoint) { // 피봇보다 큰 S[i]와 피봇보다 작은 S[j] 위치 바꿔주는 코드
					swap = S[i];
					S[i] = S[j];
					S[j] = swap;
					break;
				}
			}
		}
		if (i > x) { // 만약 피봇보다 큰 수가 없으면 피봇을 마지막 S[j] 위치로 이동
			swap = S[low];
			S[low] = S[x];
			S[x] = swap;
			quicksort(low, x - 1);  // 피봇 보다 작은수들정렬
			quicksort(x + 1, high); // 피봇 보다 큰 수들 정렬
		}
		
	}
}

void main() {
	int siz = sizeof(S) / sizeof(int);
	quicksort(0, siz - 1);
	for (int i = 0; i < siz; i++) { // 들어갔는지 확인해주는 코드
		cout << S[i] << "\t";
	}
}