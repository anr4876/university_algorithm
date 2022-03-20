#include <iostream>

using namespace std;

void list1(int num[] , int i) { // 리스트 출력
	cout << "list==================================" << endl;
	for (int j = 0; j < i - 1; j++) {
		cout << j + 1 << ". : " << num[j] << endl;
	}
	cout << "list==================================" << endl;
}

int main() {

	int num[20];
	int i;
	int x;
	int k;
	int w;

	for (i = 1; i <= 7; i++) {
		num[i - 1] = i;
		
	}

	

	while (1) {
		cout << "노드 삽입 : 1, 노드 삭제 : 2 \n 번호를 선택하시오 : ";
		cin >> x;

		if (x == 1) { // 노드 삽입 코드

			list1(num, i);

			cout << "삽입할 곳의 번호를 입력하시오 : ";
			cin >> k;

			cout << "삽입할 숫자를 입력하시오 : ";
			cin >> w;

			for (int x = k; x < i + 1; x++) 
			{
				num[19] = num[x-1];
				num[x-1] = w;
				w = num[19];
			}

			cout << k << "번째에 삽입 되었습니다. " << endl;
			i++;
			list1(num, i);
		}

		else {  // 노드 삭제 코드
			list1(num, i);

			cout << "삭제할 번호를 입력해주세요 " << endl;
			cin >> k;

			for (int y = k; y < i; y++) num[y-1] = num[y];
			
			i--;
			list1(num, i);
			cout << "정상적으로 삭제 되었습니다" << endl;
		}
	}


	return 0;
}