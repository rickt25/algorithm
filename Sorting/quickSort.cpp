#include<stdio.h>

void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

void quickSort(int arr[], int first, int last){
	
	int i, j, pivot;

    if( first<last ){
    	pivot=first;
    	i=first;
    	j=last;

    	while(i<j){
      		
        	while(arr[i] <= arr[pivot] && i < last)
            	i++;
            	
        	while(arr[j] > arr[pivot])
            	j--;
            	
	    	if( i < j )
	        	swap(&arr[i], &arr[j]);
	         	
      	}

	    swap(&arr[pivot], &arr[j]);
	    
	    quickSort(arr,first,j-1);
	    quickSort(arr,j+1,last);
   }
	
}

int main(){
	
	int arr[10] = {6,8,1,4,9,2,5,10,3,7};
	int n = 10;
	
	quickSort(arr, 0, n-1);
	
	for(int i=0; i<n; i++){
		printf("%d ",arr[i]);
	}
}
