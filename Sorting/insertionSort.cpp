#include<stdio.h>

void insertionSort(int arr[], int n){
	
	int temp; // temporarily store a num
	
	for(int i=1; i<n; i++){
		temp = arr[i];
		
		int j = i-1;
		// loop until temp is smaller than other
		// each loop increment 1 array up
		while( j >= 0 && arr[j] > temp){
			arr[j+1] = arr[j];
			j--;
		}
		// until temp found where it belongs
		arr[j+1] = temp;
	}
	
}

int main(){
	
	int arr[10] = {6,8,1,4,9,2,5,10,3,7};
	int n = 10;
	
	insertionSort(arr, n);
	
	for(int i=0; i<n; i++){
		printf("%d ",arr[i]);
	}
}
