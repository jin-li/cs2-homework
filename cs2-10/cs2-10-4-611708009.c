#include <stdio.h>
#include <stdlib.h>

int f(int i)
{
    static int j=0;
    return i *j++;
}

int main()
{
    int result1, result2;
    result1 = f(10);
    printf("The value of f(10) is %d if f has never been called before.\n", result1);

    int k;
    for (k = 0; k < 5; k++)
    {
        result2 = f(10);
    }
    printf("The value of f(10) is %d if f has been called five times previously.\n", result2);

    return 0;
}
