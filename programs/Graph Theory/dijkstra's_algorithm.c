#include<stdio.h>
#define infinity 999

void dij(int n, int v, int cost[10][10], int dist[])
{

    int w,u,flag[n],min;

    for(w=0;w<n;w++)
    {
        flag[w]=0;
        dist[w]=cost[v][w];
    }
    dist[v]=0;
    flag[v]=1;
	
    int count=1;

    while(count<n-1)
    {
        min=infinity;
        for(w=0;w<n;w++)
            if((dist[w]<min)&&!flag[w])
            {
			    min=dist[w];
                u=w;
            }
        
        flag[u]=1;

        for(w=0;w<n;w++)
        	if(!flag[w])
			{
            	if(min+cost[u][w]<dist[w])
           	 {
              	  dist[w]=min+cost[u][w];
           	 }
           }
        
		count++;

    }
}



void main()
{
    int n,i,j;
    printf("Enter the total vertices:\n");
    scanf("%d",&n);

    int v,cost[10][10],dist[10];
    
    printf("Enter the cost matrix:\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&cost[i][j]);

            if(cost[i][j]==0)
            {
                cost[i][j]=infinity;
            }
        }
    }
    
    printf("\n Enter the source vertex:\n");
    scanf("%d",&v);
    
    dij(n,v,cost,dist);

    //Now displaying
    printf("\n Displaying path from source vertex to each vertex:\n");

    for(i=0;i<n;i++)
    {
        printf("%d vertex to %d is %d\n",v,i,dist[i]);
    }
}

