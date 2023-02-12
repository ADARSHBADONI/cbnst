#include <stdio.h>
#include <math.h>
float function1(float x)
{
    float res = x * x * x - 2 * x + 1;
    return res;
}
float function2(float x)
{
    float res = (x * x * x + 1) / 2;
    return res;
}
float solve(float x0, int n)
{
    float fx, x;
    printf("x0=%f\n", x0);
    for (int i = 0; i < n; i++)
    {
        x = function2(x0);
        printf("x%d= %f\n", i + 1, x);
        if (fabs(x - x0) <= 0.0001)
            return x;
        x0 = x;
    }
    return x;
}
int main()
{
    int x0, x1 = 0, n;
    for (x1 = 0;; x1++)
    {
        if (function1(x1) > 0)
        {
            break;
        }
    }
    for (x0 = x1;; x0--)
    {
        if (function1(x0) < 0)
        {
            break;
        }
    }
    printf("Number of iterations :");
    scanf("%d", &n);
    float res = solve((x0 + x1) / 2.0, n);
    printf("Solution of the equation: %f\n", res);
    return 0;
}
