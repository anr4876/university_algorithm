#include <iostream>
using namespace std;
#include <string>

int main(void) {

	int j = 0;            // 줄 개수
	int x[11] = { };    // 글자 개수
	int k[11] = { };   // 단어 개수
	string st1[10];
	int num = 1;
	while(1) {
		cout << "문자열을 입력하세요 : ";
		getline(cin, st1[j]);
		k[j]++;
		for (int i = 0; i < st1[j].length(); i++) { //단어 개수 세기
			if (st1[j][i] == ' ' && st1[j][i] != st1[j][j]) {				
				k[j]++; //  단어 사이에 공백이 입력되면 카운트 +1
			}
		}
		cout << "입력하신 단어 개수는 : " << k[j] << "입니다. " << endl;
		for (int i = 0; i < st1[j].length(); i++) { //글자 개수 세기
			if (st1[j][i] != ' ') {
				x[j]++; // 입력받은 문자를 공백을 제외하고 카운트
			}
		}
		cout << "입력하신 글자 개수는 : " << x[j] << "입니다. " << endl;
		j++; // 줄수 카운트
		cout << "더 입력하시면 1, 그만 입력하시면 0 을 입력해주세요 : "; // 계속해서 입력하기위한 코드
		cin >> num;
		cin.ignore();
		if (num == 0) {
			break;
		}
	}
	for (int i = 0; i < j; i++) {  // 전체 글자, 단어를 합하는 코드
		x[10] += x[i];
		k[10] += k[i];
	}
	cout << "입력하신 문자열의 줄,단어,글자  개수는 : " << j << ',' << k[10] << ',' << x[10] << "입니다. " << endl;
	return 0;
}