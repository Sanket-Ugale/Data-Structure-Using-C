#include<stdio.h>
void main(){

	int arr1[10][10];
    int arr2[10][10];
	int i,j,n,m,temp=0,avg=0;

	printf("\nEnter number of rows: ");
	scanf("%d",&n);

	printf("\nEnter number of columns: ");
	scanf("%d",&m);

	printf("\nEnter elements of Matrix 1: ");
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
        {
			scanf("%d",&arr1[i][j]);
            }
	}
    printf("\nEnter elements of Matrix 2: ");
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
        {
			scanf("%d",&arr2[i][j]);
        }
	}
	
    // Addition of Matrix 1 and 2
    printf("\nAddition of Matrix 1 and 2: \n");
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
        {
			printf("%d\t",arr1[i][j] + arr2[i][j]);
        }
        printf("\n");
	}

    // Multiplication of Matrix 1 and 2
    printf("\nMultiplication of Matrix 1 and 2:  \n");
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
        {
			printf("%d\t",arr1[i][j] * arr2[i][j]);
        }
        printf("\n");
	}
    
    // Transpose of Matrix 1
    printf("\nTranspose of Matrix 1: \n");
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
        {
			printf("%d\t",arr1[j][i]);
        }
        printf("\n");
	}    
    
    // Transpose of Matrix 2
    printf("\nTranspose of Matrix 2: \n");
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
        {
			printf("%d\t",arr2[i][j]);
        }
        printf("\n");
	}
}