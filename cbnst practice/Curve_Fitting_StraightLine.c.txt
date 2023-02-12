#include <stdio.h>
#include <math.h>
int main()
{
    int n;
    printf("Enter the number of observations: ");
    scanf("%d", &n);
    float x[n], y[n];
    printf("Enter the observations(x  y):\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%f %f", &x[i], &y[i]);
    }
    float sum1 = 0, sum2 = 0, sum3 = 0, sum4 = 0, a, b;
    for (int i = 0; i < n; i++)
    {
        sum1 += x[i];
        sum2 += y[i];
        sum3 += (x[i] * x[i]);
        sum4 += (x[i] * y[i]);
    }
    a = ((sum3 * sum2) - (sum4 * sum1)) / ((n * sum3) - (sum1 * sum1));
    b = ((n * sum4) - (sum1 * sum2)) / ((n * sum3) - (sum1 * sum1));
    printf("a=%f\nb=%f", a, b);
    return 0;
}
