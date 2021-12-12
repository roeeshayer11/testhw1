#include <stdio.h>
#include "NumClass.h"

int max(int a, int b)
{
    if (a > b)
        return a;
    return b;
}
int min(int a, int b)
{
    if (a > b)
        return b;
    return a;
}

int main()
{
    int a, b;
    scanf("%d%d", &a, &b);
    int c = b;
    b = max(a, b);
    a = min(a, c);
    for (int i = a; i <= b; i++)
    {
        if(isPrime(i)==1)
        printf("%d ",i);
    }
    printf("\n");
    for (int i = a; i <= b; i++)
    {
        if(isArmstrong(i)==1)
        printf("%d ",i);
    }
    printf("\n");
    for (int i = a; i <= b; i++)
    {
        if(isStrong(i)==1)
        printf("%d ",i);
    }
    printf("\n");
    for (int i = a; i <= b; i++)
    {
        if(isPalindrome(i)==1)
        printf("%d ",i);
    }
    
   printf("\n");
    return 0;
}