#include <stdio.h>
int main(void)
{
    int num = 8;
    int num1, num2;
    printf("%d", num);
    if (num % 2)
    {
        num1 = num / 2;
        num2 = num / 2 + 1;
    }
    else
    {
        num1 = num2 = num / 2;
    }
    printf(" %d %d", num1, num2);
}