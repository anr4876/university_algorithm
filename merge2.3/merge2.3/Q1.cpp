#include <iostream>
#include <stdlib.h>
using namespace std;

int main() {

	int lan = 0;
	for (int i = 0; i < 12; i++) {
		lan = rand()%99 + 1;
		cout << lan << endl;
	}


	return 0;
}