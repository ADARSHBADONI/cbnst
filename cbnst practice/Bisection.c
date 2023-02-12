#include <stdio.h>
#include <conio.h>
#include <math.h>
float function(float x)
{
    float res = x * x * x - 4 * x - 9;
    return res;
}
float solve(float a, float b)
{
    float x1;
    int count = 0;
    while (fabs(b - a) >= 0.001)
    {
        x1 = (a + b) / 2.0;
        printf("a=%f b=%f x1=%f Value of f(x1):%f \n", a, b, x1, function(x1));
        if (function(x1) == (float)0.0)
            break;
        else if ((function(x1) * function(a)) < 0)
            b = x1;
        else
            a = x1;
            count++;
    }
    printf("Total iterations: %d\n", count);
    return x1;
}
int main()
{
    int a, b = 0;
    for (b = 0;; b++)
    {
        if (function(b) > 0)
        {
            break;
        }
    }
    for (a = b;; a--)
    {
        if (function(a) < 0)
        {
            break;
        }
    }
    printf("a=%d b=%d\n", a, b);
    float res = solve(a, b);
    printf("Solution of the function: %f\n", res);
    printf("value of the function: %f", function(res));
    return 0;
}
