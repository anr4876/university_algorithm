#include <stdio.h>
double sum(double n)
{
    if (n == 1)return 1;
    else return 1 / n + sum(n - 1);

}

int main()
{
    double n;
    printf("N의 값은");
    scanf_s("%lf", &n);

    printf("n의 합은 %lf입니다..\n", sum(n));
    return 0;
}

