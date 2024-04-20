#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
int **M;
int max(int a, int b)
{
    if (a >= b)
        return a;
    else
        return b;
}
int bottom_up_dp(int n, int *s, int *v, int C)
{
    // n = no of items
    // C = capacity
    // s = item weight
    // v = item value
    // if (M[n][C] >= 0)
    //     return M[n][C];
    // for (int i = 1; i <= n; i++) // go thru first row
    // {
    //     for (int j = 1; j <= C; j++)
    //     {
    //         M[i][j] = max(M[i - 1][j], M[i - 1][j - s[i]] + v[i]);
    //     }
    // }
    // return -1000;
}

int main()
{
    int n, C;
    int function;
    int *s;
    int *v;
    int i, j;
    printf("Enter the number of items n:\n");
    scanf("%d", &n);
    printf("Enter the capacity C:\n");
    scanf("%d", &C);
    s = (int *)malloc(sizeof(int) * (n + 1));
    v = (int *)malloc(sizeof(int) * (n + 1));
    //----------------------------------------------------------
    // M[n][C] array initialisation
    M = malloc(sizeof(int *) * (n + 1)); // int n array of ptrs
    for (i = 1; i <= n; i++)
    {
        M[i] = malloc(sizeof(int) * (C + 1)); // int c array of ptrs
    }
    for (i = 1; i <= n; i++)
        for (j = 1; j <= C; j++)
        {
            M[i][j] = -1;
        }

    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= C; j++)
        {
            printf("%d", M[i][j]);
        }
        printf("\n");
    }
    //----------------------------------------------------------
    printf("Enter the sizes of items (as a list, separate by spacing:\n");
    for (i = 1; i <= n; i++)
        scanf("%d", &s[i]);

    printf("Enter the values of items (as a list, separate by spacing:\n");
    for (i = 1; i <= n; i++)
        scanf("%d", &v[i]);

    printf("The maximum value is: %d \n", bottom_up_dp(n, s, v, C));
}