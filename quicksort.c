#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int partition(int a[],int s, int e){
    int p = a[s];
    int i = s+1;
    int j =e;
    while(i<=j){
        while(a[i]<=p) i++;
        while(a[j]>=p)j--;
        if(i<j){
            int t = a[i];
            a[i]= a[j];
            a[j]= t;
            i++;
            j--;
        }
        
    }
    a[s]= a[j];
    a[j]= p;
    return j;
}
void quick_sort(int a[],int s , int e){
    if(s>=e) return;
    int p = partition(a,s,e);
    quick_sort(a,s,p-1);
    quick_sort(a,p+1,e);
}
int main()
{
	int i, n,a[200000];
      double clk;
      clock_t starttime,endtime;
	printf("Enter the number of students records: \n");
	scanf("%d",&n);
       for(i=0;i<n;i++) 
       {
        	 a[i]=rand()%100;
         	printf("The roll numbers are \t%d",a[i]);
        }
        starttime=clock();
	quick_sort(a,0,n-1);
      endtime=clock();
      clk=(double)(endtime-starttime)/CLOCKS_PER_SEC;
	printf("\nSorted roll numbers are: \n");
	for(i=0;i<n;i++)
	printf("\t%d",a[i]);
      printf("\nThe run time is %f\n",clk);
}