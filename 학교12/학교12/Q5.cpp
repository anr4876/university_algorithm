#include <iostream>
using namespace std;


int main() {

	int teen;
	int six[] = { 0,0};
	bool tt = false;
	string en[] = { "A","B","C","D","E","F" };

	cout << "10������ �Է��Ͻÿ� : ";
	cin >> teen;


	six[0] = teen / 16;
	six[1] = teen % 16;

	cout << "�Է��� 10������ 16������ : ";

	for (int x = 0; x < 2; x++) {
		for (int i = 0; i < 6; i++) {
			if (six[x] == 10 + i) cout << en[i];
			else if (six[x] < 10) {
				cout << six[x];
				break;
			}
		}
	}
	
	cout << endl;
	cout << "�Է��� 10������ 2������ : ";

	for (int i = 256; i >= 1; i /= 2) {
		if (teen >= i) {
			cout << 1 ;
			teen -= i;
			tt = true;
			continue;
		}
		
		if(tt || teen == 0) {
			cout << 0;
		}
		
	}
	return 0;
}