#include<stdio.h>
#define MAX 5
void set(int []);
int main()
{
    int a[MAX],i;
    a[0]=0;
    set(a);
    for(i=0;i<MAX;i++)
    {
            printf("%d\n",a[i]);
    }
    return 0;
}

void set(int s[])
{
    s[0]=0;
    int n,i;
    printf("enter how many numbers\n");
    scanf("%d",&n);
    printf("enter elements\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&s[i]);
    }
    s[0]=n;
    //  for(i=1;i<n;i++)
    // {
    //         printf("%d\n",s[i]);
    // }
}
//That means in user defined function array type argument , 
//it works as reference i.e. not needed to return type .
//we can change content of main function of array using user defined function\n
//without return type user defined function.