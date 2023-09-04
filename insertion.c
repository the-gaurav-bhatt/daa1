#include<stdio.h>
#include<time.h>
#include<stdlib.h>
void insertionsort(int a[],int n);

int main()
{
        int n,i,a[100],key,f;
        double clk;
        clock_t starttime,endtime;
        printf("\n\t\t\t Insertion sort \n");
        printf("\n Enter number of elements");
        scanf("%d",&n);

        for(i=0;i<n;i++)
	     	a[i]=rand()%1000;
	     
  	  starttime=clock(); 
 	  insertionsort(a,n);
     	  endtime=clock();
                
        printf("\nThe sorted elements are:\n");
	  for(i=0;i<n;i++)
 		printf("%d\t",a[i]);

        clk=(double)(endtime-starttime)/CLOCKS_PER_SEC;
        printf("\nThe run time is %f\n",clk);
 }
  

void swap(int *a, int *b ){
 int temp;
 temp = *a;
 *a = *b;
 *b = temp;
}
	void insertionsort(int a[],int n)
	{
        int i,j,key;
          for (i = 1;i<n;i++){
            key =  a[i];
            j = i -1 ;
	
            while(j>=0 && a[j]>a[j+1]){
              swap(a[j],a[j+1]);
              j--;
          
            }
		      }
    }
