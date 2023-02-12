#include <stdio.h>
int main()
{
    int n, m;
    printf("Enter the number of equations: ");
    scanf("%d", &n);
    float arr[n][n + 1];
    for (int i = 0; i < n; i++)
    {
        printf("Enter the  %d equation: ", i + 1);
        for (int j = 0; j < n + 1; j++){
            scanf("%f", &arr[i][j]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j == i)
                continue;
            float temp1 = arr[i][i] / arr[j][i];
            for (int k = 0; k < n + 1; k++)
            {
                arr[j][k] = (arr[j][k] * temp1) - arr[i][k];
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n + 1; j++)
        {
            printf("%f ", arr[i][j]);
        }
        printf("\n");
    }
    float ans[n];
    for (int i = 0; i < n; i++)
        ans[i] = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        ans[i] = arr[i][n];
        ans[i] /= arr[i][i];
    }
    for (int i = 0; i < n; i++)
    {
        printf("x%d: %f \n", i + 1, ans[i]);
    }
    return 0;
}
