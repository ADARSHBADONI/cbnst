#include <stdio.h>
#include <math.h>
float function(float x)
{
    float res = 1 / (1 + x * x);
    return res;
}
int main()
{
    int n;
    printf("Enter the Value of n: ");
    scanf("%d", &n);
    float x0, xn;
    printf("Enter the value of x0 and xn: ");
    scanf("%f %f", &x0, &xn);
    float width = (xn - x0) / n;
    float i, res = 0;
    res += (function(x0) + function(xn));
    i = x0 + width;
    int j = 1;
    while (j < n)
    {
        if (j % 3 == 0)
            res += (2 * function(i));
        else
            res += (3 * function(i));
        i += width;
        j++;
    }
    res = res * ((3 * width) / 8);
    printf("res=%f\n", res);
    return 0;
}
