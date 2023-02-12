#include <stdio.h>
#include <math.h>
int main()
{
    float xa, xp, rov;
    int n;
    printf("Enter the Actual Value: ");
    scanf("%f", &xa);
    printf("Enter the Approximate Value: ");
    scanf("%f", &xp);
    float Ea, Er, Ep;
    if (xa >= xp)
        Ea = xa - xp;
    else
        Ea = xp - xa;
    Er = Ea / xa;
    Ep = Er * 100;
    printf("Absolute error: %f\n", Ea);
    printf("Relative error: %f\n", Er);
    printf("Percentage error: %f\n", Ep);
    printf("enter the digit upto you want to round of: ");
    scanf("%d", &n);
    double temp = (float)((int)(xa * pow(10, n))) / pow(10, n);
    double rem = xa - temp;
    printf("truncate value: %lf", temp);
    if (rem <= 5.0 / pow(10, n + 1))
        rov = temp;
    else
        rov = temp + 1.0 / pow(10, n);
    printf("\nRound of value: %lf", rov);
    return 0;
}
