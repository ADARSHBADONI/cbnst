#include <stdio.h>
#include<math.h>
#define f(x) x*x*x-4*x-9//take x0 2.5
#define e 0.001
#define df(x)3*x*x-4

int main()
{
    float x0,x1,f0,f1,df0;
    int i=0;
    printf("enter the value for x0");
    scanf("%f",&x0);
    do{
        f0=f(x0);
        df0=df(x0);
        x1=x0-(f0/df0);
        f1=f(x1);
        x0=x1;
        i++;
        printf("no of iterations:%d\t",i);
        printf("root:%f\t",x1);
        printf("value of function:%f\t\n",f1);
    }
   while (fabs(f1)>e);
    return 0;
}
