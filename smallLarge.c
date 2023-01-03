#include<stdio.h>
void main(){
	int arr[100];
	int n,i,temp1=0,temp2=0,large,small;
	printf("Enter number of elements: ");
	scanf("%d",&n);
	printf("Enter array elements: ");
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	for(i=0;i<n;i++)
	{
		temp1=arr[i];
		if(temp1>temp2)
		{
			large=temp1;
			temp2=temp1;
		}
		else if(temp1<temp2)
		{
			small=temp1;
		}
		else
		{
			printf("none");
		}
		
	}	
	printf("Array smallest elements is: %d \n",small);
	printf("Array largest elements is: %d\n",large);
}