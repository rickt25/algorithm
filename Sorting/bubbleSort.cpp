#include<stdio.h>

void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

void bubbleSort(int arr[], int n){
	
	for(int i=0; i<n-1; i++){
		for(int j=0; j<n-i-1; j++){
			if(arr[j] > arr[j+1])
				swap(&arr[j], &arr[j+1]);
		}
	}
	
}

int main(){
	
	int arr[10] = {6,8,1,4,9,2,5,10,3,7};
	int n = 10;
	
	bubbleSort(arr, n);
	
	for(int i=0; i<n; i++){
		printf("%d ",arr[i]);
	}
}
