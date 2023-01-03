#include<stdio.h>
void main(){
	int arr1[10][10];
	int i,j,n,m,temp=0,avg=0;
	printf("\nEnter number of rows: ");
	scanf("%d",&n);
	printf("\nEnter number of columns: ");
	scanf("%d",&m);
	printf("\nEnter array elements: ");
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++){
			scanf("%d",&arr1[i][j]);}
	}
	printf("\nArray elements are:\n ");
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++){
			printf("%d\t",arr1[i][j]);
			temp=temp+arr1[i][j];
		}
		printf("\n");
	}
	avg=temp/2;
	printf("\nAverage is: %d\n",avg);
}

