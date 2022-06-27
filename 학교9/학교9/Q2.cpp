#include <iostream>
#include <math.h>

using namespace std;



int main(void) {
	FILE* fio, *fcl;
	int num;
	int number[10][10];
	double z_score = 0;
	double average = 0;
	double standard = 0;
	double S = 0;

	fopen_s(&fio, "score.txt", "w");
	for (int i = 1; i <= 100; i++) {

		num = (rand() % 49 + 50);
		fprintf(fio, "%d\t", num);
		cout << num << "\t" ;

		if (i % 10 == 0 ) {
			fprintf(fio, "\n");
			cout << endl;
		}
	}
	fclose(fio);

	cout << endl;
	cout << endl;

	fopen_s(&fcl, "score.txt", "r+");
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			fscanf_s(fcl, "%d[\t]", &number[i][j]);
			cout << number[i][j] << "\t";
			average += number[i][j];
			
		}
		cout << endl;
	}
	fclose(fcl);

	
	average /= 100;
	cout << "평균 : " << average << endl;

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			
			
			standard += ((number[i][j] - average) * (number[i][j] - average));

		}
	
	}
	standard /= 100;

	
	standard = sqrt(standard);

	cout << "표준편차 : " << standard << endl;

	z_score = (number[3][2] - average) / standard;

	cout << "z-score : " << z_score << endl;

	S = z_score * 20 + 100;

	cout << "표준 점수 : " << S << endl;



	return 0;
}