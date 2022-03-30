#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;


int main() {

    int i = 0, j;
    FILE* fin, * fout;
    double num[11][11];

    fopen_s(&fin, "test.txt", "w");
    for (i = 0; i < 10; i++) {
        num[10][i] = 0;
        for (j = 0; j < 10; j++) {
            num[i][j] = (rand() % 200) * 1.1;
            fprintf(fin, "%5.1lf\t", num[i][j]);
            printf("%5.1lf \t", num[i][j]);       
        }
        for (j = 0; j < 10; j++) {
            num[10][i] += num[i][j];
        }
        fprintf(fin, "%5.1lf\t \n", num[10][i]);
        printf("%5.1lf \t", num[10][i]);
        printf("\n");
    }
    for (i = 0; i < 10; i++) {
        num[i][10] = 0;
        for (j = 0; j < 10; j++) {            
            num[i][10] += num[i][j];
        }
        fprintf(fin, "%5.1lf\t", num[i][10]);
        printf("%5.1lf \t", num[i][10]);        
    }
   
    fclose(fin);

    return 0;
   
}