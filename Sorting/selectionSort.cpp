#include<stdio.h>

void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

void selectionSort(int arr[], int n){
	
	int min; // find minimum
	
	for(int i=0; i<n-1; i++){
		min = i;
		for(int j=i+1; j<n; j++){
			if(arr[j] < arr[min])
				min = j;
		}
		swap(&arr[min],&arr[i]); // swap minimum with first element
	}
	
}

int main(){
	
	int arr[10] = {6,8,1,4,9,2,5,10,3,7};
	int n = 10;
	
	selectionSort(arr, n);
	
	for(int i=0; i<n; i++){
		printf("%d ",arr[i]);
	}
}
