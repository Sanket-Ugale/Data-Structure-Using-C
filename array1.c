
#include<stdio.h>
void main(){
	int arr[100];
	int n,i;
	printf("Enter number of elements: ");
	scanf("%d",&n);
	printf("Enter array elements: ");
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	printf("Array elements are: ");
	for(i=0;i<n;i++){
		printf("%d\t",arr[i]);
	}
}

