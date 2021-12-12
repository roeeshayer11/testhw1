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

int armstrongSum(int n, int digCount)
{
    if (kamutsfarot(n) == 1)
        return (int)(pow(n, digCount));
    int c = n, d = 0;
    int a = n % 10;
    d = d + (int)(pow(a, digCount));
    return d + armstrongSum(n / 10, digCount);
}

int isArmstrong(int n)
{
    if (n == armstrongSum(n, kamutsfarot(n)))
        return 1;
    return 0;
}

int isPalindrome(int n)
{
    int digCount = kamutsfarot(n);
    if (digCount == 1)
        return 1;
    int a = n % 10;
    int b = n / pow(10, digCount - 1);
    if (a != b)
        return 0;
    n = n % (int)(pow(10, digCount - 1));
    n = n / 10;
    return isPalindrome(n);
}
