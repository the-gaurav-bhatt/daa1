// Online C compiler to run C program online
#include<stdio.h>
#include<time.h>
int n;
int choose(int dis[],int vis[]){
    int min = 100;
    int ind = 1;
    for(int i = 1; i <=n;i++){
        if(dis[i]<min && !vis[i]){
            min = dis[i];
            ind = i;
        }
    }return ind;
}
void shortestPath(int source, int cost[][n+1],int dis[]){
    int vis[n+1];
    for(int i = 1; i<=n; i++){
        vis[i]= 0;
        dis[i] = cost[source][i];
    }
    vis[source]= 0;
    dis[source ]= 0;
    for(int i = 2; i<=n;i++){
        int res = choose(dis,vis);
        vis[res] = 1;
        for(int v = 1 ; v<=n;v++){
            if(dis[res]+cost[res][v]<dis[v] && !vis[v]){
                dis[v]= dis[res]+cost[res][v];
            }
        }
    }
}

void main() {
 printf("Enter the number of vetices: ");
 scanf("%d",&n);
 printf("Enter the source vertex: ");
 int source;
 scanf("%d",&source);
 int cost[n+1][n+1];
 printf("Enter the cost matrix: \n");
 for(int i = 1; i<=n; i++) {
 for(int j = 1; j<=n; j++) {
 scanf("%d",&cost[i][j]);
 }
 }
 int distance[n+1];
 shortestPath(source,cost,distance);
 for(int i = 1; i<=n; i++) {
 printf("%d to %d = %d \n", source, i, distance[i]);
 }
}
