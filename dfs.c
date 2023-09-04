// An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically.
//  You may assume all four edges of the grid are all surrounded by water. 
//  Given an m x n 2D binary grid which represents a map of '1's (land) and '0's (water),
//   return the number of islands using DFS algorithm. Design and develop a program in C to
//    print all the lands reachable from a given starting land in a digraph by using DFS method.
//     Repeat the experiment for different values of n and plot a graph of the time taken versus n(n=no of nodes)
#include<stdio.h>
#include<time.h>
    int k=0;

void dfs(int n, int a[10][10], int u, int trav[10][10], int visited[10]);
int main()
{
        int n,i,j,u,a[10][10],visited[10],t[10][10];
        double clk;
        clock_t starttime,endtime;
        printf("\n\t\t\t DEPTH FIRST SEARCH \n");
        printf("\n Enter number of vertices:");
        scanf("%d",&n);
        printf("\n Enter the adjacency matrix (Enter 0/1)\n");
	    for(i=0;i<n;i++)
	     for(j=0;j<n;j++)
	    	scanf("%d",&a[i][j]);
	   	printf("\n Enter the source vertex:");
        scanf("%d",&u);
    	for(i=0;i<n;i++)
       {	
          	visited[i]=0;
       }
       dfs(n,a,u,t,visited);
       for(i=0;i<n;i++)  
            if(visited[i]==1)
                 printf("%d is reachable",i);
            else
                printf("%d is not reachable",i);
                
                printf("DFS traversal : Edges visited\n");
                for(i=0;i<n-1;i++)
                printf("%d %d\n",t[i][0],t[i][1]);
                
       
}

void dfs(int n, int a[10][10], int start, int trav[10][10], int visited[10]){
    visited[start]= 1;
    for(int i = 0; i<n;i++){
        if(!visited[i] && a[start][i]==1){
            trav[k][0]= start;
            trav[k][1]= i;
            k++;
            dfs(n,a,i,trav,visited);
        }
    }
}