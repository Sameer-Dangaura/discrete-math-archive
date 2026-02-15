#include<stdio.h>
int power(int a, int n)
{
    if(n==0)
    {
        return 1;
    }
    else if(n==1)
    {
        return a;
    }
    else
    {
        return (a*power(a,n-1));
    }
}

int main()
{
    int x,y,p;
    printf("enter value of base no. and power no.\n");
    scanf("%d %d",&x,&y);
    p=power(x,y);
    printf("%d^%d=%d",x,y,p);
    return 0;
}