//PROGRAM
#include<stdio.h>
#include<time.h>
double clk;
clock_t starttime,endtime;

int min(int a,int b)
{
	if(a<b)
	return a;
	else
	return b;
}

void floyd(int n,int W[10][10],int D[10][10])
{
   	int i,j,k;
	for(i=0;i<n;i++)
	for(j=0;j<n;j++)
	D[i][j]=W[i][j];
	for(k=0;k<n;k++)
	{
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				D[i][j]=min(D[i][j],D[i][k]+D[k][j]);
			}
		}
	}
}

void main()
{
	int i,j,n,D[10][10],W[10][10];
	printf("Enter no.of vertices: \n");
	scanf("%d",&n);
	printf("Enter the cost matrix: \n");
	for(i=0;i<n;i++)
	for(j=0;j<n;j++)
	scanf("%d",&W[i][j]);
	starttime=clock();
            floyd(n,W,D);	
endtime=clock();
clk=(double)(endtime-starttime)/CLOCKS_PER_SEC;
 printf("All pair shortest path matrix is\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%d\t",D[i][j]);
		}
		printf("\n");
	}
   printf("\nThe run time is %f\n",clk);
}


/*
Sample input and output
Enter no of vertices : 4
Enter the cost matrix
0	999	3	999
2	0	999	999
999	7	0	1	
6	999	999	0
All pairs shortest path matrix is:
0	10	3	4
2	0	5	6
7	7	0	1
6	16	9	0
The time taken is 0.989011
*/