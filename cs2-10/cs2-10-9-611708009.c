#include <stdio.h>
#include <stdlib.h>

#define MEDIAN(x,y,z) (x < y ? (y < z ? y : x < z ? z : x) : (y > z ? y : x > z ? z : x))

int main()
{
    double x, y, z;
    printf("Please enter three numbers: ");
    scanf("%lf %lf %lf", &x, &y, &z);
    printf("The median is %.0lf.", MEDIAN(x, y, z));

    return 0;
}
