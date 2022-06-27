#include <iostream>
using namespace std;

int main() {

	
	int month;
	int day;
	int sum = 0;

	cout << "월 : ";
	cin >> month ;

	cout << "일 : ";
	cin >> day;

	for (int i = 1; i < month; i++) {
		sum += 31;
		if (i == 2) {
			sum -= 3;
		}
		else if (i == 4 || i == 6 || i==9 || i== 11) {
			sum -= 1;
		}
	}

	cout << "오늘은 이번 년도의 " << sum + day << "번째 이다.";

	return 0;
}