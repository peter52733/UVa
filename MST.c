#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int cmp(const void* a,const void* b);
typedef struct edge{
    int from,to,dist;
}edge;
edge edges[500*500];
int main()
{
    int i,j,index,k,N,satellite,outpost,group[500],x[500],y[500],counter,visited[500];
    int distance[500*500];
    scanf("%d",&N);
    while(N--)
    {
        scanf("%d %d",&satillite,&outpost);
        for(i=0;i<outpost;i++) scanf("%d %d",&x[i],y[i]);
        for(i=0;i<outpost;i++)
        {
            group[i]=i;
            visited[i]=0;
        }
        for(i=0,counter=0;i<outpost-1;i++)
        {
            for(j=i+1;j<outpost;j++)
            {
                edges[counter].from=i;
                edges[counter].to=j;
                edges[counter].dist=(x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
                counter++;
            }
        }
        qsort(edges,counter,sizeof(edge),cmp);
        test=outpost;
        while(test)
        {
            for(i=0,k=0;i<outpost;i++)
            {
                if(find(group,edges[i].from)!=find(group,edges[i].to))
                {
                    distance[k]=edges[i].dist;
                    k++;
                    if(!visited[edges[i].from)
                    {
                        visited[edges[i].from]=1;
                        test--;
                    }
                    if(!visited[edges[i].to])
                    {
                        visited[edges[i].to]=1;
                        test--;
                    }
                }
            }
        }
        printf("%.2f\n",sqrt(distance[outpost-1-satellite-1]));
    }
}
int cmp(const void* a,const void* b)
{
    return *(edge*)a.dist-*(edge*)b.dist;
}
int find(int* group, int node)
{
    int tmp=node;
    while(tmp!=group[tmp]) tmp=group[tmp];
    return tmp;
}
