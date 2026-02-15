#include<stdio.h>
int n=5;
int search(int a[], int m)
{
    static int i=0;

    if(a[i]==m)
    {
        return i;
    }
    else if(i==n)
    {
        return -1;
    }
    else
    {
        i++;
        return search(a,m);
    }
}

int main()
{
    // int n;
    // printf("enter the size of array:\n");
    // scanf("%d",&n);
    
    int a[n],m,s;
    printf("enter numbers for array:\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("enter number to be searched:\n");
    scanf("%d",&m);
    s=search(a,m);

    if(s==-1)
    {
        printf("not found");
    }
    else{
        printf("%d is in %d position",m,s+1);
    }
    return 0;
}