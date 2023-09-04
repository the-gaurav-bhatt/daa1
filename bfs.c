// Online C compiler to run C program online
#include<stdio.h>
#include<time.h>
void bfs(int a[10][10],int n, int start){
    int queue[50],s=0,e=0;
    int visited[n];
    for(int i= 0;i<n;i++){
        visited[i]=0;
    }
    visited[start]= 1;
    int node = start;
    queue[s]= node;
    do{
        node=queue[s++];
        for(int i = 0; i<n;i++){
            if(a[node][i]==1 && !visited[i]){
                printf("%d %d \n",node,i);
                visited[i]= 1;
                queue[++e]= i;
            }
        }
    }while(s<e);
    
}

int main()
{
 	int a[10][10],n,i,j,s;
      double clk;
      clock_t starttime,endtime;
	printf("\n Enter the number of vertices\n");
 	scanf("%d",&n);
	printf("\nEnter the matrix represention:");
 	for(i=0;i<n;i++)
 	for(j=0;j<n;j++)
  	scanf("%d",&a[i][j]);
 	printf("\nEnter the source vertix");
 	scanf("%d",&s);
      starttime=clock(); 
 	bfs(a,n,s);
      endtime=clock();
      clk=(double)(endtime-starttime)/CLOCKS_PER_SEC;
      printf("\nThe run time is %f\n",clk);
 
}
