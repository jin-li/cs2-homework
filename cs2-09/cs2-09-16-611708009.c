#include <stdio.h>
#include <stdlib.h>

int sum(int (*f)(int), int start, int end)
{
    int i;
    int sum = 0;
    for(i = start; i <= end; i++)
    {
        sum += (*f)(i);
    }
    return sum;
}

int square(int a)
{
    return a*a;
}

int main()
{
    int start, end, s;
    printf("Please enter the start number: ");
    scanf("%d",&start);
    printf("Please enter the end number: ");
    scanf("%d",&end);
    s = sum(square, start, end);
    printf("The sum of square from %d to %d is %d", start, end, s);
    return 0;
}
