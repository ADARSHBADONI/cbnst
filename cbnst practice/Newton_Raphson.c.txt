#include <stdio.h>
#include <math.h>
float function(float x)
{
    float res = x * x * x * x - x - 10;
    return res;
}
float diffoffunction(float x)
{
    float res = 4 * x * x * x - 1;
    return res;
}
float solve(float x0, int n)
{
    float fx, dfx, x;
    fx = function(x0);
    dfx = diffoffunction(x0);
    printf("x0= %f fx0= %f dfx0= %f\n", x0, fx, dfx);
    for (int i = 0; i < n; i++)
    {
        x = x0 - fx / dfx;
        fx = function(x);
        dfx = diffoffunction(x);
        printf("x%d= %f fx%d= %f dfx%d= %f\n", i + 1, x, i + 1, fx, i + 1, dfx);
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
        if (function(x1) > 0)
        {
            break;
        }
    }
    for (x0 = x1;; x0--)
    {
        if (function(x0) < 0)
        {
            break;
        }
    }
    printf("Number of iterations :");
    scanf("%d", &n);
    printf("x0= %d x1= %d\n", x0, x1);
    float x = (x0 + x1) / 2.0;
    float res = solve(x, n);
    printf("Solution of the equation: %f\n", res);
    return 0;
}
