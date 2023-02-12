#include <stdio.h>
#include <math.h>
    float
    function(float x)
{
    float res = x * x * x - 2 * x - 5;
    return res;
}
float solve(float a, float b, int n)
{
    float fa, fb, fc, c;
    fa = function(a);
    fb = function(b);
    for (int i = 0; i < n; i++)
    {
        c = (a * fb - b * fa) / (fb - fa);
        fc = function(c);
        printf("a: %f b: %f fa: %f fb: %f c: %f fc: %f\n", a, b, fa, fb, c, fc);
        if (fabs(b - a) <= 0.001)
            return c;
        if (fa * fc < 0)
            {
                b = c;
                fb = fc;
            }
        else
        {
            a = c;
            fa = fc;
        }
    }
    return c;
}
int main()
{
    int a, b = 0, n;
    for (b = 0;; b++)
    {
        if (function(b) > 0)
        {
            break;
        }
    }
    a = b - 1;
    printf("Number of iterations:");
    scanf("%d", &n);
    float res = solve(a, b, n);
    printf("Solution of the equation: %f\n", res);
    return 0;
}