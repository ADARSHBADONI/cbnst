#include <stdio.h>
#include <math.h>
int main()
{
    int n, i, j, k;
    printf("Enter No. of Observation : ");
    scanf("%d", &n);
    float x[n], y[n];
    printf("Enter the observations(x  y):\n");
    float sum_x = 0, sum_y = 0, sumXX = 0, sumYY = 0, sumXY = 0;
    for (i = 0; i < n; i++)
    {
        scanf("%f %f", &x[i], &y[i]);
        sum_x += x[i];
        sum_y += y[i];
    }
    float y_mean = sum_y / n, x_mean = sum_x / n;
    for (int i = 0; i < n; i++)
    {
        sumXX += (x[i] - x_mean) * (x[i] - x_mean);
        sumYY += (y[i] - y_mean) * (y[i] - y_mean);
        sumXY += (x[i] - x_mean) * (y[i] - y_mean);
    }
    float dty, dtx, r, slopeyx, c, val, yx;
    dty = sqrt(sumYY / n);
    dtx = sqrt(sumXX / n);
    r = sumXY / (n * dty * dtx);
    slopeyx = r * dty / dtx;
    c = -slopeyx * x_mean + y_mean;
    printf("Regression Coefficient = %.3f \n", r);
    printf("Slope y on x = %.3f\n", slopeyx);
    printf("Regression line y on x: ");
    printf("y=%0.2fx+%0.2f\n", slopeyx, c);

    printf("Enter Value  at which you have to find y: ");
    scanf("%f", &val);
    yx = slopeyx * val + c;
    printf("Y at x=%0.2f=%0.2f\n", val, yx);
    return 0;
}
