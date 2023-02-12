#include <stdio.h>
#include <math.h>
int fact(int i)
{
    if (i == 0 || i == 1)
        return 1;
    else
        return i * fact(i - 1);
}
float solve(float p, int i)
{
    float res = 1;
    for (int j = 0; j < i; j++)
    {
        res *= (p + j);
    }
    return res;
}
int main()
{
    int n;
    printf("Enter the number of values: ");
    scanf("%d", &n);
    float arr[n];
    float mat[n][n];
    printf("Enter the X and its values(Y):\n");
    printf("X    Y\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%f", &arr[i]);
        scanf("%f", &mat[i][0]);
    }
    float h = arr[1] - arr[0];
    float x;
    printf("Enter the number whose value you have to be found: ");
    scanf("%f", &x);
    float p = (x - arr[n - 1]) / h;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            mat[j][i] = mat[j + 1][i - 1] - mat[j][i - 1];
        }
    }
    printf("Forward Difference Table:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            printf("%0.2f ", mat[i][j]);
        }
        printf("\n");
    }

    float res = mat[n - 1][0];
    for (int i = 1; i < n; i++)
    {
        res += (solve(p, i) * mat[n - i - 1][i]) / fact(i);
    }
    printf("Value of X=%0.2f: %0.4f\n", x, res);
    return 0;
}
