#include <iostream>
using namespace std;



int main(void) {

	int i = 0;
	int num = 0;
	string st1[10];

	while (1) {
		cout << "문자열을 입력하세요 : ";
		cin >> st1[i];
		i++;
		cout << "더 입력하시면 1, 그만 입력하시면 0 을 입력해주세요 : ";
		cin >> num;
		if (num == 0) {
			break;
		}
		
	}
	cout << "입력한 문자열의 개수 : " << i;

	
	



	return 0;
}