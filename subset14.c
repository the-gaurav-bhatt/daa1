#include<stdio.h>

// Function to print the subset
void printSubset(int subset[], int k) {
    for (int i = 0; i <= k; i++) {
        printf("%d,", subset[i]);
    }
    printf("\n");
}

// Function to find the subsets
void subsetSum(int set[], int subset[], int n, int subSize, int total, int nodeCount , int sum) {
    int i;
    int subsequent;
    if( total == sum){
        printSubset(subset, subSize);
        subsetSum(set,subset,n,subSize-1,total-set[nodeCount],nodeCount+1,sum);
        return;
    }
    else{
        // Generate remaining subsets
        for( i = nodeCount; i < n; i++ ){ // For each item in the set
            subset[subSize] = set[i]; // Include the item in the subset
            // Move onto the next node
            subsequent = total + set[i];
            // Do not check same level node
            if( subsequent <= sum ){
                // Check if a subset with sum is possible
                subsetSum(set,subset,n,subSize+1,subsequent,i+1,sum);
            }
        }
    }
    return;
}

void findSubset(int set[], int size, int sum){
    int subset[size]; // To hold the subset configuration
    subsetSum(set, subset, size, 0, 0, 0, sum); // Generate subsets
}


int main(){
    int weights[] = {10, 7, 5, 18, 12, 20, 15};
    int size = 7;
    findSubset(weights, size, 35);
    return 0;
}
