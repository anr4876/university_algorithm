#include <stdio.h>
double sum(double n)
{
    if (n == 1)return 1;
    else return 1 / n + sum(n - 1);

}

int main()
{
    double n;
    printf("N�� ����");
    scanf_s("%lf", &n);

    printf("n�� ���� %lf�Դϴ�..\n", sum(n));
    return 0;
}

