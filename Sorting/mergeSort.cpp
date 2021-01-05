#include<stdio.h>

void merge(int arr[], int left, int mid, int right) {
   	int l, r, i;
   	int temp[10];

	for(l = left, r = mid+1 , i = left; l <= mid && r <= right; i++){
		if(arr[l] <= arr[r])
			temp[i] = arr[l++];
		else
			temp[i] = arr[r++];
	}
   
   	while(l <= mid)
    	temp[i++] = arr[l++];

   	while(r <= right)   
    	temp[i++] = arr[r++];

   	for(i = left; i <= right; i++)
      	arr[i] = temp[i];
}

void mergeSort(int arr[], int l, int r){
	
	if (l < r) {
		// get middle to separate into 2 array
        int m = l + (r - l) / 2;
 
 		// sort first and second array
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
 
        merge(arr, l, m, r);
    }
	
}

int main(){
	
	int arr[10] = {6,8,1,4,9,2,5,10,3,7};
	int n = 10;
	
	mergeSort(arr, 0, n-1);
	
	for(int i=0; i<n; i++){
		printf("%d ",arr[i]);
	}
}
