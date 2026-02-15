#include<stdio.h>
#define MAX 20
int main()
{
    int a[MAX],b[MAX],p[MAX][MAX],i,j,m,n;
    printf("enter size of first set:\n");
    scanf("%d",&n);
    
    printf("enter elements:");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }    
    
    printf("enter size of second set:\n");
    scanf("%d",&m);
    
    printf("enter elements:");
    for(i=0;i<m;i++)
    {
        scanf("%d",&b[i]);
    }  
    
    printf("cartesian product is: {");  
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            printf("(%d,%d)",a[i],b[j]);
            if((i==n-1)&&(j==m-1))
            break;
            printf(",");
        }
    }
    printf("}");
    return 0;
}
