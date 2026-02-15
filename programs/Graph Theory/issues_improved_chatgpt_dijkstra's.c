#include <stdio.h>
#define INFINITY 999

void dij(int n, int v, int cost[n][n], int dist[]) 
{
    int w, u, flag[n], min;

    for (w = 0; w < n; w++) 
	{
        flag[w] = 0;
        dist[w] = cost[v][w];
    }
    dist[v] = 0;
    flag[v] = 1;

    int count = 1;

    while (count < n - 1) 
	{
        min = INFINITY;
        for (w = 0; w < n; w++)
		 {
            if ((dist[w] < min) && !flag[w]) 
			{
                min = dist[w];
                u = w;
            }
        }

        flag[u] = 1;

        for (w = 0; w < n; w++) 
		{
            if (!flag[w])
			 {
                if (dist[u] + cost[u][w] < dist[w]) 
				{
                    dist[w] = dist[u] + cost[u][w];
                }
            }
        }

        count++;
    }
}

int main() 
{
    int n, i, j;
    printf("Enter the total vertices:\n");
    scanf("%d", &n);

    int v, cost[n][n], dist[n];

    printf("Enter the cost matrix:\n");
    for (i = 0; i < n; i++)
	 {
        for (j = 0; j < n; j++)
		 {
            scanf("%d", &cost[i][j]);

            if (cost[i][j] == 0)
			 {
                cost[i][j] = INFINITY;
            }
        }
    }

    printf("\nEnter the source vertex:\n");
    scanf("%d", &v);

    dij(n, v, cost, dist);

    // Now displaying
    printf("\nDisplaying path from source vertex to each vertex:\n");

    for (i = 0; i < n; i++) 
	{
        printf("%d vertex to %d is %d\n", v, i, dist[i]);
    }

    return 0;
}

