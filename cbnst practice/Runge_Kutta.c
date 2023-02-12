#include <stdio.h>
#include <math.h>
float function(float x, float y)
{
    float res = (y - x) / (y + x);
    return res;
}
int main()
{
    float x0, y0, h, x, k1, k2, k3, k4, y;
    printf("Enter the value of x0: ");
    scanf("%f", &x0);
    printf("Enter the value of y0: ");
    scanf("%f", &y0);
    printf("Enter the value of h: ");
    scanf("%f", &h);
    printf("Enter the value of x whose value we have to found: ");
    scanf("%f", &x);
    int n = (int)((x - x0) / h);
    printf("\nY0: %f\n", y0);
    y = y0;
    for (int i = 1; i <= n; i++)
    {
        k1 = h * function(x0, y);
        k2 = h * function(x0 + 0.5 * h, y + 0.5 * k1);
        k3 = h * function(x0 + 0.5 * h, y + 0.5 * k2);
        k4 = h * function(x0 + h, y + k3);
        y = y + (1.0 / 6.0) * (k1 + 2 * k2 + 2 * k3 + k4);
        x0 = x0 + h;
        printf("Y%d: %f\n", i, y);
    }
    float res = y;
    printf("Value of fx at x=%f: %f", x, res);
    return 0;
}
