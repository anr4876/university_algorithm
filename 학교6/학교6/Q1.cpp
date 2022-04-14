#include <iostream>
using namespace std;
#define N 5

void prim(int n, int w[][5], int edges[][2])
{
	int i, k, vnear;
	int min;
	int nearest[N + 1];
	int distance[N + 1];
	int nb_edge = 0;

	for (i = 2; i <= n; i++) {
		nearest[i] = 1;
		distance[i] = w[0][i - 1];
	}

	for (k = 0; k < n - 1; i++) {
		min = 10000;
		for (i = 2; i <= n; i++) {
			if (distance[i] >= 0 && distance[i] < min) {
				min = distance[i];
				vnear = i;
			}
		}
		edges[nb_edge][0] = vnear;
		edges[nb_edge][1] = nearest[vnear];
		nb_edge++;
		distance[vnear] = -1;
		for (i = 2; i <= n; i++) {
			if (w[i - 1][vnear - 1] < distance[i]) {
				distance[i] = w[i - 1][vnear - 1];
				nearest[i] = vnear;
			}
		}
	}
	cout << endl;
	for (i = 2; i < nb_edge; i++) {
		cout << "v" << edges[i][0] << " -> v" << edges[i][1] << endl;
	}
	
}

int main() {
	int w[][5] = {
		{1, 1, 3, 10000, 10000},
		{1, 0, 3, 6, 10000},
		{3, 3, 0, 4, 2},
		{10000, 6, 4, 0, 5},
		{10000, 10000, 2, 5, 0} };

	int edges[N * 4][2];
	prim(N, w, edges);
}