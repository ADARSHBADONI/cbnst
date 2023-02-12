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
    float res = p;
    int k = 0;
    for (int j = 1; j < i; j++)
    {
        if (i % 2 == 1)
        {
            res *= (p - k);
            k++;
        }
        else
            res *= (p + k - 1);
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
    float x, h = arr[1] - arr[0];
    printf("Enter the number whose value you have to be found: ");
    scanf("%f", &x);
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
    int k = 0;
    while (arr[k] < x)
        k++;
    k--;
    float p = (x - arr[k]) / h;
    float res = mat[k][0];
    for (int i = 1; i < n; i++)
    {
        res += (solve(p, i) * mat[(k - i + 1)][i]) / fact(i);
    }
    printf("Value of X=%0.2f: %0.4f\n", x, res);
    return 0;
}
