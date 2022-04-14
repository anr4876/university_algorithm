#include <iostream>
#define N 5
using namespace std;


int edges[][3] = { {0,0,0}, {1,3,3}, {2,3,3}, {2,4,6},{3,4,4},{3,5,2},{4,5,5} };
int nb_edge = sizeof(edges) / (sizeof(int) * 3);
int vertexSet[N + 1][N];
int nbVertex[N + 1];

void swap(int a[3], int b[3])
{
	int temp;
	for (int i = 0; i < 3; i++) {
		temp = a[i];
		a[i] = b[i];
		b[i] = temp;
	}
}

void edgesort() {

	int i, j, min, minelem;
	for (i = 0; i < nb_edge; i++) {
		for (j = i, min = 10000; j < nb_edge; j++) {
			if (edges[j][2] < min) {
				min = edges[j][2];
				minelem = j;
			}
		}
		swap(edges[i], edges[minelem]);
	}
}

int find(int a){
	int i, j;
	for (i = 1; i <= N; i++) {
		for (j = 0; j < nbVertex[i]; j++) {
			if (a == vertexSet[i][j])
				return vertexSet[i][0];
		}
	}
	return -1;
}

void merge(int x, int y)
{
	int i;
	for (i = 0; i < nbVertex[y]; i++)
		vertexSet[x][nbVertex[x] + i] = vertexSet[y][i];
	nbVertex[x] += nbVertex[y];
	nbVertex[y] = 0;

	cout << endl << " contents of set " << x << " : ";
	for (i = 0; i < nbVertex[x]; i++) {
		cout << "\t" << vertexSet[x][i];
	}
}

void kruskal(int edges[][3], int f[], int& nb_f)
{
	int i, j, k, l;
	int p, q;
	int edge[2];
	int n = 1;

	nb_f = 0;
	for (i = 1; i <= N; i++) {
		nbVertex[i] = 1;
		vertexSet[i][0] = i;
	}

	edgesort();


	while (n <= N) {
		i = edges[n][0];
		j = edges[n][1];

		p = find(i);
		q = find(j);
		cout << endl << " n = " << n << " : i = " << i << " j = " << j << " p = " << p << " q = " << q << endl;
		if (p == -1 || q == -1) {
			cout << "Error of find function" << endl;
		}
		else {
			if (p != q) {
				merge(p, q);
				f[nb_f] = n;
				nb_f++;
			}
		}
		n++;
	}
}


void main() {
	int f[N], nb_f;

	edgesort();
	cout << "Sort edges by weight" << endl;
	for (int i = 0; i < nb_edge; i++) {
		cout << edges[i][0] << "  " << edges[i][1] << "  " << edges[i][2] << endl;
	}

	kruskal(edges, f, nb_f);
	cout << endl << endl;
	cout << "Edges of Spanning Tree" << endl;
	for (int i = 0; i < nb_f; i++) {
		cout << "\t" << edges[f[i]][0] << "\t" << edges[f[i]][1] << endl;
	}
	cin.get();
}