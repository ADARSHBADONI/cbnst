#include <stdio.h>
int main()
{
    int n, m, t;
    printf("Enter the number of equations: ");
    scanf("%d", &n);
    float arr[n][n + 1];
    float ans[n];
    for (int i = 0; i < n; i++)
        ans[i] = 0;
    for (int i = 0; i < n; i++)
        {
            printf("Enter the  %d equation: ", i + 1);
            for (int j = 0; j < n + 1; j++)
            {
                scanf("%f", &arr[i][j]);
            }
        }
    printf("Enter the no of iterations: ");
    scanf("%d", &t);
    for (int c = 0; c < t; c++)
    {
        for (int i = 0; i < n; i++)
        {
            float temp = arr[i][n];
            for (int j = 0; j < n; j++)
            {
                if (j == i)
                    continue;
                temp -= arr[i][j] * ans[j];
            }
            ans[i] = temp / arr[i][i];
        }
        for (int k = 0; k < n; k++)
        {
            printf("x%d: %f ", k + 1, ans[k]);
        }
        printf("\n");
    }
    return 0;
}
