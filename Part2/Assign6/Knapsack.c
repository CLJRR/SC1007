#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
int **M;
int max(int a, int b)
{
    return a > b ? a : b;
}

int bottom_up_dp(int n, int *s, int *v, int C)
{
    //     n = no of items
    //     C = capacity
    //     s = item weight
    //     v = item value

    for (int i = 1; i <= n; i++)     // go thru Item 1 to n (rows)
        for (int j = 1; j <= C; j++) // go thru Capacity 1 to C (cols)
        {
            if (j >= s[i]) // if capacity > item weight
            {
                // check to include or not
                M[i][j] = max(M[i - 1][j], M[i - 1][j - s[i]] + v[i]);
            }
            else
            {
                // take the previous value (since it cant hold the item)
                M[i][j] = M[i - 1][j];
            }
        }
    return M[n][C];
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
    for (i = 0; i <= n; i++)
    {
        M[i] = malloc(sizeof(int) * (C + 1)); // int c array of ptrs
    }

    for (i = 0; i <= n; i++)
        for (j = 0; j <= C; j++)
            M[i][j] = 0;

    //----------------------------------------------------------
    printf("Enter the sizes of items (as a list, separate by spacing:\n");
    for (i = 1; i <= n; i++)
        scanf("%d", &s[i]);

    printf("Enter the values of items (as a list, separate by spacing:\n");
    for (i = 1; i <= n; i++)
        scanf("%d", &v[i]);

    printf("The maximum value is: %d \n", bottom_up_dp(n, s, v, C));
}