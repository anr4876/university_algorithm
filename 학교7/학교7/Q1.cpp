#include <iostream>
using namespace std;
#define N 5

int w[][5] =
{ {0, 7, 4, 6, 1},
{1000, 0, 1000, 1000, 1000},
{1000, 2, 0, 5, 1000},
{1000, 3, 1000, 0, 1000},
{1000, 1000, 1000, 1, 0} };

int f[N * 4][2];

void dijkstra(int n, int w[][5], int f[][2])
{
	int i, j, k, vnear, min;
	int touch[N + 1];
	int length[N + 1];
	int nb_edge = 0;
	int e[N * 4];
	int flag;
	for (i = 2; i <= n; i++) {
		touch[i] = 1;
		length[i] = w[0][i - 1];
	}

	for (j = 0; j < n - 1; j++) {
		min = 1000;
		for (i = 2; i <= n; i++) {
			if (length[i] >= 0 && length[i] < min) {
				min = length[i];
				vnear = i;
			}
		}
		f[nb_edge][0] = touch[vnear];
		f[nb_edge][1] = vnear;
		nb_edge++;

		for (i = 2; i <= n; i++) {
			if (length[vnear] + w[vnear - 1][i - 1] < length[i]) {
				length[i] = length[vnear] + w[vnear - 1][i - 1];
				touch[i] = vnear;
			}
		}
		length[vnear] = -1;
	}
	for (i = 0; i < nb_edge; i++) {
		cout << f[i][0] << "  " << f[i][1] << endl;
	}

	cout << endl << endl;
	for (i = 0; i < nb_edge; i++) {
		e[0] = f[i][1];
		e[1] = f[i][0];
		flag = 1;
		k = 1;
		while (flag) {
			for (j = 0, flag = 0; j < nb_edge; j++) {
				if (e[k] == f[j][1]) {
					k++;
					e[k] = f[j][0];
					flag = 1;
					break;
				}
			}
		}

		for (j = k; j >= 0; j--) {
			cout << e[j] << "  ";
		}
		cout << endl;
		

		
	}
}

void main() {
	dijkstra(N, w, f);
}