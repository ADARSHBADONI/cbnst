#include <stdio.h>
int main()
{
    int n, i, j, k;
    printf("Enter No. of Observation : ");
    scanf("%d", &n);
    float x[n], y[n];
    printf("Enter the observations(x  y):\n");
    float sum_x = 0, sum_y = 0, sum_xy = 0, sum_xx = 0, sum_xxy = 0, sum_xxx = 0, sum_xxxx = 0;
    for (i = 0; i < n; i++)
    {
        scanf("%f %f", &x[i], &y[i]);
        sum_x += x[i];
        sum_y += y[i];
        sum_xy += x[i] * y[i];
        sum_xx += x[i] * x[i];
        sum_xxy += x[i] * x[i] * y[i];
        sum_xxx += x[i] * x[i] * x[i];
        sum_xxxx += x[i] * x[i] * x[i] * x[i];
    }

    float matrix[3][4];
    matrix[0][0] = n;
    matrix[0][1] = sum_x;
    matrix[0][2] = sum_xx;
    matrix[0][3] = sum_y;

    matrix[1][0] = sum_x;
    matrix[1][1] = sum_xx;
    matrix[1][2] = sum_xxx;
    matrix[1][3] = sum_xy;

    matrix[2][0] = sum_xx;
    matrix[2][1] = sum_xxx;
    matrix[2][2] = sum_xxxx;
    matrix[2][3] = sum_xxy;

    printf("X=%0.2f  Y=%0.2f  XY=%0.2f  X^2=%0.2f  X^2Y=%0.2f  X^3=%0.2f  X^4=%0.2f\n", sum_x, sum_y, sum_xy, sum_xx, sum_xxy, sum_xxx, sum_xxxx);

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 4; j++)
        {
            if (i != j)
            {
                float p = matrix[j][i] / matrix[i][i];
                for (k = 0; k < 4; k++)
                {
                    matrix[j][k] = matrix[j][k] - (p * matrix[i][k]);
                }
            }
        }
    }
    float a = matrix[0][3] / matrix[0][0];
    float b = matrix[1][3] / matrix[1][1];
    float c = matrix[2][3] / matrix[2][2];
    printf("a = %.2f \t b = %.3f \t c = %.3f \n", a, b, c);
    printf("Equation :  y = %.2f + %.2fx + %.2fx^2 \n", a, b, c);
    return 0;
}