#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
int *F;

int top_down_dp(int n)
{
    if (F[n] >= 0)
        return F[n];
    if (F[n - 1] == -1)
    {
        top_down_dp(n - 1);
    }
    if (F[n - 2] == -1)
    {
        top_down_dp(n - 2);
    }
    if (F[n - 3] == -1)
    {
        top_down_dp(n - 3);
    }
    F[n] = F[n - 1] + 2 * F[n - 2] - 3 * F[n - 3];
    return F[n];
}

int main()
{
    int n;
    int function;
    int i;
    printf("Enter the value of n:\n");
    scanf("%d", &n);
    F = malloc(sizeof(int) * (n + 1));
    F[0] = 0;
    F[1] = 1;
    F[2] = 2;
    for (int i = 3; i <= n; i++)
    {
        F[i] = -1;
    }

    printf("The value of F(%d) is: %d \n", n, top_down_dp(n));
}