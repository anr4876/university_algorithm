#include <iostream>
using namespace std;
int w[][5] = {
	{0, 1, 1000, 1, 5},
	{9, 0, 3, 2, 1000},
	{1000, 1000, 0, 4, 1000},
	{1000, 1000, 2, 0, 3},
	{3, 1000, 1000, 1000, 0} 
};
int d[5][5], p[5][5];
void floyd(int n, int w[][5], int d[][5], int p[][5]){
	int i, j, k;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			p[i][j] = 0;
			d[i][j] = w[i][j];
		}
	}
	for (k = 0; k < j; k++)
		for (i = 0; i < n; i++)
			for (j = 0; j < n; j++)
				if (d[i][k] + d[k][j] < d[i][j]) {
					p[i][j] = k + 1;
					d[i][j] = d[i][k] + d[k][j];
				}	
}
void path(int q, int r)
{
	if (p[q][r] != 0) {
		path(q, p[q][r] - 1);
		cout << "v" << p[q][r] << " ";
		path(p[q][r] - 1, r);
	}
}
void main() {
	int i, j, n = 5, start, goal;
	floyd(n, w, d, p);
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++)
			cout << d[i][j] << " ";
		cout << endl;
	}
	cout << endl;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++)
			cout << p[i][j] << " ";
		cout << endl;
	}
	cout << "출발점 : ";
	cin >> start;
	cout << endl << "도착점 :";
	cin >> goal;
	cout << "거리 = " << d[start - 1][goal - 1] << endl;
	cout << "path = " << "v" << start << " ";
	path(start - 1, goal - 1);
	cout << "v" << goal << endl;
}
