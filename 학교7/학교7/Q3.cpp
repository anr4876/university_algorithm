#include <iostream>
using namespace std;

int pp_num(int u) 
{
	if (u == 2) {
		return u;
	}
	else {
		return u + pp_num(u - 2);

	}
}

int plus_num(int k, int u) 
{
	if (k != u){
		return pp_num(u) + plus_num(k, u - 2);
	}
	else {
		return k;
	}

}




int main() {

	

	cout << plus_num(2, 50);

	return 0;
}