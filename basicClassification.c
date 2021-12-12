#include <stdio.h>
#include <math.h>

#include "NumClass.h"

int isPrime(int n)
{
    if (n == 1)
        return 0;
    int x = sqrt((double)n) + 1;
    int y = 2;
    while (y != x)
    {
        if (n % y == 0)
            return 0;
        y++;
    }

    return 1;
}
int azeret(int x)
{
    int y = 1;
    for (size_t i = 2; i <= x; i++)
    {
        y = y * i;
    }
    return y;
}

int isStrong(int n)
{
    int x = n;
    int z = 0;
    while (x > 0)
    {
        int y = x % 10;
        z = z + azeret(y);
        x = x / 10;
    }
    return n==z;
}
