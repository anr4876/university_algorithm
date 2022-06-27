#include<stdio.h>
#include<math.h> 
#define WIDTH 19 
#define HEIGHT 100
#define PI (3.141592)

int isEqual(double d1, double d2, double e)
{
	if ((d1 - d2 > 0.0 ? d1 - d2 : d2 - d1) < e) return 1; return 0;
}

int main(int argc, char *argv[])
{ 
	double x=0.0; double y=0.0;
	int col=0,row=0;
	printf("%-*d%1d%*d\n",WIDTH,-1,0,WIDTH,1);
	for(row=0;row<WIDTH*2+1;row++) printf("-");
	printf("\n");
	for(col=0;col<HEIGHT;col++) { 
		y=sin(2*PI*x); 
		for(row=0;row<WIDTH*2+1;row++) 
		{ if(isEqual((double)row,(y+1.0)*(double)WIDTH,0.5))
			printf("*"); else if(row == WIDTH) printf("|");
			else printf(" ");
		}
		x += 0.05; printf("\n");
	} 
} 

