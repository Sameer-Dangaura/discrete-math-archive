#include<stdio.h>
#define infinity 999

void dij(int n, int v, int cost[n][n], int dist[])
{

    int w,u,flag[n],min;

    for(w=1;w<=n;w++)
    {
        flag[w]=0;
        dist[w]=cost[v][w];
    }

    int count=2;

    while(count<=n)
    {
        min=99;
        for(w=1;w<=n;w++)
        {
            if((dist[w]<min)&&!flag[w])
            {
			    min=dist[w];
                u=w;
            }
        }
        flag[u]=1;
        count++;

        for(w=1;w<=n;w++)
        {
            	if((dist[u]+cost[u][w]<dist[w])&&!flag[w])
           	 {
              	  dist[w]=dist[u]+cost[u][w];
           	 }
        }


    }
}



void main()
{
    int n,i,j;
    printf("Enter the total vertices:\n");
    scanf("%d",&n);

    int v,cost[n][n],dist[n];

    printf("Enter the source vertex:\n");
    scanf("%d",&v);
    
    printf("Enter the cost matrix:\n");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            scanf("%d",&cost[i][j]);

            if(cost[i][j]==0)
            {
                cost[i][j]=infinity;
            }
        }
    }
    dij(n,v,cost,dist);

    //Now displaying
    printf("Displaying path from source vertex to each vertex:\n");

    for(i=1;i<=n;i++)
    {
    	if(i!=v)
        printf("%d vertex to %d is %d\n",v,i,dist[i]);
    }
}

