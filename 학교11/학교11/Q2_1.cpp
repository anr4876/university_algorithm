#include <iostream>
using namespace std;

int x;
int s[] = { 10, 12, 13, 14, 18, 20, 25, 27, 30, 35, 40, 45 };
int no = 0;

int location(int low, int high) {
	int mid;
	if (low > high) {
		return -1;
	}
	else {
		mid = (low + high) / 2;
		no++;
		cout << "no = " << no << "\t" << "mid = " << mid << "\t" << "s[mid] = " << s[mid] << endl;
		if (x == s[mid]) {
			return mid;
		}
		else if(x < s[mid]) {
			return location(low, mid - 1);
		}
		else {
			return location(mid + 1, high);
		}
	}
}

int main() {
	int locationout;
	cout << "찾고자 하는 값을 입력하세요 : ";
	cin >> x;
	locationout = location(0, sizeof(s) / sizeof(int) - 1);
	cout << " result = " << locationout;
}