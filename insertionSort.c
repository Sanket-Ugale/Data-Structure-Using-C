#include <stdio.h>
#include <conio.h>
#define N 10
int arr[N];
int main()
{
    int flag = 0, temp, i,j,a;
    printf("\nEnter array elements: ");
    for (a = 0; a < N; a++)
    {
        scanf("%d", &arr[a]);
    }
    printf("Original array is: ");
    for (i = 0; i < N; i++)
    {
        printf("\t%d", arr[i]);
    }
    for (i = 1; i < N; i++)
    {
        temp=arr[i];
        j=i-1;
        while (j>=0 && arr[j]>temp)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=temp;
    }
    printf("\nSorter array is: ");
    for (i = 0; i < N; i++)
    {
        printf("\t%d", arr[i]);
    }
}