#include<stdio.h>
void swap(int *a, int *b) {
 int t = *a;
 *a = *b;
 *b = t;
}
void heapify(int arr[],int n, int i){
     int left = 2*i;
        int lar = i;
        int right = 2*i+1;
        if(left<=n && arr[left]>arr[i]){
            lar = left;
        }if(right<=n && arr[right]>arr[lar]){
            lar = right;
        }
        if(lar!=i){
            swap(&arr[lar],&arr[i]);
            heapify(arr,n,lar);
        }
}

void heapsort(int arr[],int n ){
    for(int i = n/2; i>0;i--){
       heapify(arr,n,i);
    }
    for(int i = n ; n>0;i--){
        swap(&arr[1],&arr[i]);
        heapify(arr,i-1,1);
    }
}
void main() {
 int arr[] = {2,3,7,5,4};
 int n = 5;
 heapsort(arr, n);
 for(int i = 0; i<n; i++) {
 printf("%d ", arr[i]);
 }
}