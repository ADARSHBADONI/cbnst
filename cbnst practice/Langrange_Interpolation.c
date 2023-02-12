#include <stdio.h>
#include <math.h>
float solve(float x[], float f[], int n, float num)
{
    float res = 0;
    for (int i = 0; i < n; i++)
    {
        float temp1 = 1, temp2 = 1;
        for (int j = 0; j < n; j++)
        {
            if (i != j)
            {
                temp1 *= (num - x[j]);
                temp2 *= (x[i] - x[j]);
            }
        }
        res += (temp1 / temp2) * f[i];
    }
    return res;
}
int main()
{
    int n;
    printf("Enter the number of values: ");
    scanf("%d", &n);
    float x[n], f[n], num;
    printf("Enter the X and its values(Y):\n");
    printf("X Y\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%f", &x[i]);
        scanf("%f", &f[i]);
    }
    printf("Enter the number whose value is to be find:");
    scanf("%f", &num);
    float res = solve(x, f, n, num);
    printf("Vaule of function at number %f: %f\n", num, res);
    return 0;
}
