#include <stdio.h>
struct node
{
    unsigned dist[20];
    unsigned from[20];
}rt[10];
int main()
{
    int dmat[20][20];
    int n,i,j,k,count=0;
    printf("enter the no of nodes:");
    scanf("%d",&n);
    printf("\n Enter the cost matrix:\n");
    for (i=0;i<n;i++)
        for(j=0;j<n;j++)
        {
            scanf("%d",&dmat[i][j]);
            dmat[i][i]=0;
            rt[i].dist[j]=dmat[i][j];
            rt[i].from[j]=j;
        }
    do
    {
     count=0;
     for(i=0;i<n;i++)
     for(j=0;j<n;j++)
     for(k=0;k<n;k++)
     if(rt[i].dist[j]>dmat[i][k]+rt[k].dist[j])
     {
        rt[i].dist[j]=rt[i].dist[k]+rt[k].dist[j];
        rt[i].from[j]=k;
        count++;
     }
    } while (count!=0);
    for(i=0;i<n;i++)
    {
        printf("\n\n State value for router %d is in \n",i+1);
        for(j=0;j<n;j++)
        {
            printf("\t\n node %d via %d distance %d",j+1,rt[i].from[j]+1,rt[i].dist[j]);

        }
    }
    printf("\n\n");
    
}

/*
OUTPUT:
enter the no of nodes:4

 Enter the cost matrix:
0 2 99 1         
2 0 5 9
99 5 0 6
1 99 6 0


 State value for router 1 is in

 node 1 via 1 distance 0
 node 2 via 2 distance 2
 node 3 via 2 distance 7
 node 4 via 4 distance 1

 State value for router 2 is in

 node 1 via 1 distance 2
 node 2 via 2 distance 0
 node 3 via 3 distance 5
 node 4 via 1 distance 3

 State value for router 3 is in

 node 1 via 2 distance 7
 node 2 via 2 distance 5
 node 3 via 3 distance 0
 node 4 via 4 distance 6

 State value for router 4 is in

 node 1 via 1 distance 1
 node 2 via 1 distance 3
 node 3 via 3 distance 6
 node 4 via 4 distance 0
*/