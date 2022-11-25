#include <stdio.h>
#include <math.h>

int main()
{
    double k=0;
    double x;
    float sum=0.0;
    scanf("%lf", &x);
    if (x>0.3) printf("Out of range!");
    else if (x>=0.2) {
            for (x; x <= 0.3; x = x + 0.01) {
                sum = sum + (1/(4*k+3))*pow(x, (4*k+3));
                k=k+1;
                printf("%.6lf\n", sum);
            }
    }
    else printf("Out of range!");
    return 0;
}