#include <iostream>
#include <stdlib.h>
using namespace std;

typedef struct node {
	int data;
	struct node* left;
	struct node* right;};

struct node* node_plus( int k) { 
	struct node* dt1;									// 노드 생성
	dt1 = (struct node*)malloc(sizeof(struct node));
	dt1->data = k;										// 노드에 데이터 부여
	dt1->left = NULL;
	dt1->right = NULL;									// 왼쪽 오른쪽 주소 NULL
	return dt1;											// node_find에 주소 리턴
}	

void node_find(node* h, int k) {
	node* find = h;
	if (find->data < k) {
		if (find->right == NULL) {
			cout << "오른쪽 에 추가" << endl;
			h->right = node_plus(k);     // 오른쪽 주소가 NULL이면 그 주소에 값 추가
			return;
		}
		else {
			cout << "오른쪽으로 이동" << endl;		   // 오르쪽의 주소가 NULL이 아니면 주소를 오른쪽으로 옮긴후 다시 FIND
			node_find(find->right, k);
		}
	}
	else if(find->data > k) {
		if (find->left == NULL) {	
			cout << "왼쪽에 추가 " << endl;
			h->left = node_plus(k);		// 왼쪽 주소가 NULL이면 그 주소에 값 추가	
			return;
		}
		else {
			cout << "왼쪽으로 이동 " << endl;		// 왼쪽의 주소가 NULL이 아니면 주소를 왼쪽으로 옮긴후 다시 FIND
			node_find(find->left, k);
		}
	}
}


int main() {
	struct node* head;
	head = (struct node*)malloc(sizeof(struct node));
	head->data = 50;
	head->left = NULL;
	head->right = NULL;
	int k[2];

	while (1) {
		cout << "데이터를 추가하려면 1 삭제는 2 를 입력해주세요 : ";
		cin >> k[0];
		if (k[0] == 1) {
			cout << "데이터를 입력하세요 : ";
			cin >> k[1];
			node_find(head, k[1]);	
		}	
	}
	return 0;
}