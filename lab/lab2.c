#include <stdio.h>
#include <math.h>

int main()
{
    float x;
    scanf("%f", &x);
    if (x < 2.5)
        if (x >= 2)
            for (x;  x <= 4;  x = x + 0.2)
            printf("%f\n", cosf(log(x*x)));
        else
            printf("Out of range!");
    else if(x <= 3.5)
        for (x;  x <= 4;  x = x + 0.2)
            printf("%f\n", 1/cosf(x*x*x*x));
    else if(x <= 4)
        for (x;  x <= 4;  x = x + 0.2)
            printf("%f\n", tanf(sinf(x)));
    else
         printf("Out of range!");
    return 0;
}