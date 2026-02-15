#include<stdio.h>
int main()
{
    int n,m,i,j,k;
    printf("Enter the size of matrix:\n");
    scanf("%d %d",&n,&m);
    int a[n][m];
    printf("enter the elements in 1st matrix:\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    // int p;
    // printf("Enter the size of another matrix:\n");
    // scanf("%d",&p);
    int b[m][n];
    int c[n][n];
     for (i = 0; i < n; i++) {
        for (k = 0; k < n; k++) {
            c[i][k] = 0;
        }
    }
    printf("enter the elements in 2nd matrix:\n");
    for(j=0;j<m;j++)
    {
        for(k=0;k<n;k++)
        {
            scanf("%d",&b[j][k]);
        }
    }
    
    for(i=0;i<n;i++)
    {
        for(k=0;k<n;k++)
        {

            for(j=0;j<m;j++)
            {
                c[i][k]= c[i][k]||(a[i][j] && b[j][k]);
            }
        }
    }

    printf("The product of matrix is:\n");
    for(i=0;i<n;i++)
    {
        for(k=0;k<n;k++)
        {
            printf("%d\t",c[i][k]);
        }
        printf("\n");
    }
    return 0;
}
