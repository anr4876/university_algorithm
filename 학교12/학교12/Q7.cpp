#include <iostream>
using namespace std;

typedef struct NODE {
	int data;
	struct NODE* next;
}node;

int main() {
	node* head = (node*)malloc(sizeof(node));
	node* now = NULL;
	node* link = NULL;
	link = head;
	now = head;
	for (int i = 0; i < 10; i++) {
		node* nex = (node*)malloc(sizeof(node));
		now->next = nex;
		nex->data = i;
		nex->next = NULL;
		now = now->next;
	
	}

	link = link->next;
	while (link != NULL) {
		cout << link->data << endl;
		link = link->next;
	}

	return 0;
}