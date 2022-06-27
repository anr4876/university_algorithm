#include <iostream>
#include <stdlib.h>
using namespace std;

typedef struct node {
	int data;
	struct node* left;
	struct node* right;};

struct node* node_plus( int k) { 
	struct node* dt1;									// ��� ����
	dt1 = (struct node*)malloc(sizeof(struct node));
	dt1->data = k;										// ��忡 ������ �ο�
	dt1->left = NULL;
	dt1->right = NULL;									// ���� ������ �ּ� NULL
	return dt1;											// node_find�� �ּ� ����
}	

void node_find(node* h, int k) {
	node* find = h;
	if (find->data < k) {
		if (find->right == NULL) {
			cout << "������ �� �߰�" << endl;
			h->right = node_plus(k);     // ������ �ּҰ� NULL�̸� �� �ּҿ� �� �߰�
			return;
		}
		else {
			cout << "���������� �̵�" << endl;		   // �������� �ּҰ� NULL�� �ƴϸ� �ּҸ� ���������� �ű��� �ٽ� FIND
			node_find(find->right, k);
		}
	}
	else if(find->data > k) {
		if (find->left == NULL) {	
			cout << "���ʿ� �߰� " << endl;
			h->left = node_plus(k);		// ���� �ּҰ� NULL�̸� �� �ּҿ� �� �߰�	
			return;
		}
		else {
			cout << "�������� �̵� " << endl;		// ������ �ּҰ� NULL�� �ƴϸ� �ּҸ� �������� �ű��� �ٽ� FIND
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
		cout << "�����͸� �߰��Ϸ��� 1 ������ 2 �� �Է����ּ��� : ";
		cin >> k[0];
		if (k[0] == 1) {
			cout << "�����͸� �Է��ϼ��� : ";
			cin >> k[1];
			node_find(head, k[1]);	
		}	
	}
	return 0;
}