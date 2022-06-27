#include <iostream>
using namespace std;
#include <string.h>
#define WT 16
#define N 16

int w[] = { 0, 2, 5, 10, 5 };
int p[] = { 0, 40, 30, 50, 10 };
int maxprofit;

struct node {
	int level;
	int profit;
	int weight;
	float bound;
};

int heapsize = 0;

void siftdown(node PQ[], int i) {

	int parent, largerchild;
	node  siftnode;
	bool spotfound;

	siftnode = PQ[i];
	parent = i;
	spotfound = false;

	while (2 * parent <= heapsize && !spotfound) {
		if (2 * parent < heapsize && PQ[2 * parent].bound < PQ[2 * parent + 1].bound) {
			largerchild = 2 * parent + 1;
		}
		else
			largerchild = 2 * parent;
		if (siftnode.bound < PQ[largerchild].bound) {
			PQ[parent] = PQ[largerchild];
			parent = largerchild;
		}
		else
			spotfound = true;
	}
	PQ[parent] = siftnode;
}

void siftup(node PQ[], int i) {
	int parent, temp;
	node siftnode;
	bool spotfound;
	bool sw = true;

	siftnode = PQ[i];
	parent = i / 2;
	temp = i;
	spotfound = false;

	while (parent >= 1 && !spotfound) {
		if (PQ[parent].bound < siftnode.bound) {
			PQ[temp] = PQ[parent];
			temp = parent;
			parent = parent / 2;
			sw = false;
		}
		else
			spotfound = true;
	}
	if (!sw)
		if (parent == 0) PQ[1] = siftnode;
		else PQ[parent * 2] = siftnode;
}

node remove(node PQ[]) {
	node nodeout;

	nodeout = PQ[1];
	PQ[1] = PQ[heapsize];
	heapsize = heapsize - 1;
	siftdown(PQ, 1);


	return nodeout;
}

void insert(node PQ[], node s) {
	heapsize++;
	PQ[heapsize] = s;
	siftup(PQ, heapsize);
}

float bound(node u) {
	int j, k;
	int totweight = 0;
	float result = 0;

	if (u.weight >= WT)
		return 0;
	else {
		result = (float)u.profit;
		j = u.level + 1;
		totweight = u.weight;
		while (j <= N && totweight + w[j] <= WT) {
			totweight = totweight + w[j];
			result = result + p[j];
			j++;
		}
		k = j;
		if (k <= N)
			result = result + (WT - totweight) * p[k] / w[k];
		return result;
	}
}

void knapsack3(int i, int p[], int w[], int W, int& maxprofit) {
	node PQ[100];
	node u, v;
	bool sw = true;
	v.level = 0;
	v.profit = 0;
	v.weight = 0;
	maxprofit = 0;
	v.bound = bound(v);
	insert(PQ, v);

	while (sw || heapsize) {
		v = remove(PQ);
		if (v.bound > maxprofit) {
			u.level = v.level + 1;
			u.weight = v.weight + w[u.level];
			u.profit = v.profit + p[u.level];

			if (u.weight <= W && u.profit > maxprofit)
				maxprofit = u.profit;
			u.bound = bound(u);

			if (u.bound > maxprofit) {
				insert(PQ, u);
			}

			u.weight = v.weight;
			u.profit = v.profit;
			u.bound = bound(u);

			if (u.bound > maxprofit) {
				insert(PQ, u);
			}
			sw = false;
		}
	}
}

void main() {
	maxprofit = 0;
	knapsack3(0, p, w, WT, maxprofit);
	cout << maxprofit << endl;
}