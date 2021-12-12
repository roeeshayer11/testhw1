#include <stdio.h>
#include <math.h>

#include "NumClass.h"
int kamutsfarot(int n)
{
    int x = n;
    int z = 0;
    if (n == 0)
        return 1;

    while (x > 0)
    {
        z = z + 1;
        x = x / 10;
    }
    return z;
}

int isArmstrong(int n)
{

    int x = n, y = 0, z = kamutsfarot(n);
    while (x > 0)
    {
        y = y + pow(x % 10, z);
        x = x / 10;
    }
    return y == n;
}

int isPalindrome(int n)
{
    if (n < 10)
        return 1;
    int x = kamutsfarot(n);
    int y = n;
    while (y > 1)
    {
        if ((y % 10) != (int)(y / (pow(10, x - 1))))
            return 0;

        y = y % (int)pow(10, x - 1);
        y = y / 10;
        x = x - 2;
    }

    return 1;
}
