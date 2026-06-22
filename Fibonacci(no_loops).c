#include <stdio.h>

void fib(int a, int b,int n)
{
    if(n==0)return;
    printf("%d ",a);
    return fib(b,a+b,--n);
}
int main()
{
    int n;
    scanf("%d",&n);
    fib(0,1,n);
}
