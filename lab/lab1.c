#include <stdio.h>
#include <math.h>

int main()
{
    const double x = 2.361;
    const double y = 1.149;
    printf("%lf", 13*x*y-log(x/y)-17*sin(pow(x, 2)-y));

    return 0;
}