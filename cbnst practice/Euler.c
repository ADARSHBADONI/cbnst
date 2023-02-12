#include <stdio.h>
#include <math.h>
float function(float x, float y)
{
    float res = (y - x) / (y + x);
    return res;
}
int main()
{
    float x0, y0, h, x, yxn, xn;
    int n;
    printf("Enter the value of x0: ");
    scanf("%f", &x0);
    printf("Enter the value of y0: ");
    scanf("%f", &y0);
    printf("Enter the value of n: ");
    scanf("%d", &n);
    printf("Enter the value of x whose value we have to found: ");
    scanf("%f", &x);
    h = (x - x0) / n;
    printf("\nY0: %f\n", y0);
    yxn = y0, xn = x0;
    for (int i = 1; i <= n; i++)
    {
        xn = x0 + (i - 1) * h;
        yxn = yxn + h * function(xn, yxn);
        printf("Y%d: %f\n", i, yxn);
    }
    float res = yxn;
    printf("Value of fx at x=%f: %f", x, res);

    return 0;
}
