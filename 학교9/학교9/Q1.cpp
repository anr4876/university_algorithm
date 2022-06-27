#include <iostream>
#define N 10
using namespace std;

struct heap {
	int S[100];
	int heapsize;
};

void siftdown(heap& H, int i) {
	int parent, largerchild;
	int siftkey;
	bool spotfound;
	siftkey = H.S[i];
	parent = i;
	spotfound = false;
	while (2 * parent <= H.heapsize && !spotfound) {
		if (2 * parent < H.heapsize && H.S[2 * parent] < H.S[2 * parent + 1]) {
			largerchild = 2 * parent + 1;
		}
		else
		{
			largerchild = 2 * parent;
		}
		if (siftkey < H.S[largerchild]) {
			H.S[parent] = H.S[largerchild];
			parent = largerchild;
		}
		else
		{
			spotfound = true;
		}			
	}
	H.S[parent] = siftkey;
}

void siftup(heap& H, int i) {
	int parent;
	int siftkey;
	bool spotfound;
	bool sw = true;

	siftkey = H.S[i];
	parent = i / 2;
	spotfound = false;

	while (parent >= 1 && !spotfound) {
		if (H.S[parent] < siftkey) {
			H.S[i] = H.S[parent];
			parent = parent / 2;
			sw = false;
		}
		else {
			spotfound = true;
		}
		if (!sw) {
			if (parent == 0) H.S[1] = siftkey;
		}
	}
}

int root(heap & H) {
	int keyout;

	keyout = H.S[1];
	H.S[1] = H.S[H.heapsize];
	H.heapsize = H.heapsize - 1;
	siftdown(H, 1);

	return keyout;

}

void insert(heap& H, int k) {
	H.heapsize++;
	H.S[H.heapsize] = k;
	siftup(H, H.heapsize);
}

void removekey(int n, heap& H, int R[]) {
	int i;
	for (i = n; i >= 1; i--) {
		R[i] = root(H);
	}
}

void makeheap(int n, heap& H) {
	int i;
	H.heapsize = n;
	for (i = n / 2; i >= 1; i--) {
		siftdown(H, i);
	}
}

int main() {

	heap H = { 0, 66, 19, 8, 24, 7, 82, 15, 3, 31, 10 };
	H.heapsize = N;
	int Res[N + 1], i;

	for (int i = 1; i <= N; i++) {
		cout << H.S[i] << "   ";
		cout << endl;
	}
	cout << endl;
	cout << endl;

	makeheap(N, H);
	removekey(N, H, Res);
	for (int i = 1; i <= N; i++) {
		cout << Res[i] << "   ";
		cout << endl;
	}


	return 0;
}







