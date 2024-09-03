#include<stdio.h>
#include<conio.h>

//Function to create a Adjacency matrix
void createAdja(int adj[50][50],int earr[50][2],int v,int e)
{
    int i=0,j=0,x,y;

    for(i=1;i<=v;i++)
    {
        for(j=1;j<=v;j++)
        adj[i][j]=0;
    }

    for(i=0;i<e;i++)
    {
       x=earr[i][0];
       y=earr[i][1];

       adj[x][y]=1;
       adj[x][y]=1;
    }
}

void printAdjMartix(int adj[50][50],int v)
{
    int i=0,j=0;

    for(i=1;i<=v;i++)
    {
        printf("\n");
        for(j=1;j<=v;j++)
        printf("%d\t",adj[i][j]);
    }
}

void main()
{
    int v=0,e=0,i=0,j=0;
    int earr[50][2];//For Edges
    int adj[50][50];//For Adjacency Matrix
    
    printf("Enter the no. of vertices and edges");
    scanf("%d%d",&v,&e);

    printf("Enter the paths:\n");

    for(i=0;i<e;i++)
    {
        for(j=0;j<2;j++)
        scanf("%d",&earr[i][j]);
    printf("\n");
    }
    createAdja(adj,earr,v,e);
    printf("\n");
    printAdjMartix(adj,v);
    getch();

}