#include <stdio.h>
int degree(int x);

int main()
{
    int i;
    for (i = 0; i < 300; i = i+20)
        printf("%d\t%d \n", i, degree(i));
    return 0;
}

int degree(int base)
{
    int ans;
    ans = (5*(base-32))/9;
    return ans;
}
