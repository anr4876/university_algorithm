#include <iostream>
using namespace std;

int main() {

	
	int month;
	int day;
	int sum = 0;

	cout << "�� : ";
	cin >> month ;

	cout << "�� : ";
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

	cout << "������ �̹� �⵵�� " << sum + day << "��° �̴�.";

	return 0;
}