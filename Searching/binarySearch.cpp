#include<stdio.h>

int binarySearch(int arr[], int l, int r, int key) 
{ 
    while (l <= r) {
    	// Get middle
        int m = l + (r - l) / 2;
  
  		// Check if found
        if (arr[m] == key) return m;
        // If x greater, ignore left half 
        else if (arr[m] < key) l = m + 1; 
        // If x is smaller, ignore right half 
        else r = m - 1; 
    } 
  
    // not found
    return -1; 
} 

int main(){
	
	int arr[10] = {1,2,3,4,5,6,7,8,9,10};
	int n = 10;
	int key = 9; // find key
	
	printf("%d is on index %d",key, binarySearch(arr, 0, n-1, key));
	
}
