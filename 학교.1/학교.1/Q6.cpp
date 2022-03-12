#include <iostream>
using namespace std;
#include <string>

int main(void) {

	int j = 0;            // 줄 개수
	int x[11] = { };    // 글자 개수
	int k[11] = { };   // 문장 개수
	

	string st1[10];
	int num = 1;

	while(1) {

		cout << "문자열을 입력하세요 : ";
		getline(cin, st1[j]);

		k[j]++;
		for (int i = 0; i < st1[j].length(); i++) { //단어 개수 세기
			if (st1[j][i] == ' ' && st1[j][i] != st1[j][j]) {
				
				k[j]++;
			}
		}
		

		cout << "입력하신 단어 개수는 : " << k[j] << "입니다. " << endl;

		for (int i = 0; i < st1[j].length(); i++) { //글자 개수 세기
			if (st1[j][i] != ' ') {
				x[j]++;
			}
		}

		cout << "입력하신 글자 개수는 : " << x[j] << "입니다. " << endl;



		j++;
		cout << "더 입력하시면 1, 그만 입력하시면 0 을 입력해주세요 : ";
		cin >> num;
		cin.ignore();
		if (num == 0) {
			break;
		}
		
		


	}
	for (int i = 0; i < j; i++) {
		x[10] += x[i];
		k[10] += k[i];
	}

	cout << "입력하신 문자열의 줄,단어,글자  개수는 : " << j << ',' << k[10] << ',' << x[10] << "입니다. " << endl;


	return 0;
}