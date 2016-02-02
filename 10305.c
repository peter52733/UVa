#include <stdio.h>
#include <stdlib.h>
int graph[101][101];
int main()
{
    int node,link,linked[101],counter,i,j,k,from,to,visited[101];
    while(1)
    {
        scanf("%d %d",&node,&link);
        if(!node&&!link) break;
        counter=node;
        for(i=1;i<=node;i++)
        {
            linked[i]=0;
            visited[i]=0;
            for(j=1;j<=node;j++) graph[i][j]=0;
        }
        for(i=0;i<link;i++)
        {
            scanf("%d %d",&from,&to);
            graph[from][to]=1;
            linked[to]+=1;
        }
        while(counter)
        {
            for(i=1;i<=node;i++)
            {
                if(!linked[i]&&!visited[i])
                {
                    visited[i]=1;
                    printf("%d ",i);
                    for(j=1;j<=node;j++)
                    {
                        if(graph[i][j]) linked[j]-=1;
                    }
                }
            }
            counter-=1;
        }
        printf("\n");
    }
    return 0;
}
