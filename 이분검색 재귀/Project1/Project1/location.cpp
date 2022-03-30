#include <iostream>
using namespace std;

int location(int low, int high ,int S[] , int x) {
	int mid;

	if (low > high) {
		return 0;
	}


	else {
		mid = (int)((high + low) / 2);
		if (x == S[mid]) {
			return mid;
		}
		else if (x < S[mid]) {
			location(low, mid - 1, S , x);
		}
		else {
			location(mid + 1, high, S, x);
		}
	}
}


int main() {

	int num[] = { NULL, 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17 };

	

	printf("%d", location(1, 18, num, 15));

	return 0;
}