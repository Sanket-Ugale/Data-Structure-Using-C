#include <stdio.h>
#include <conio.h>
#define N 10
int arr[N];
int lb = 0,i,j, ub = N - 1,mid,temp,k;
int arr2[N];
int merge(int arr[],int lb,int mid,int ub)
{
    i = lb;
    j = mid+1;
    k=lb;
    while (i<=mid &&j<=ub)
    {
        if (arr[i]<=arr[j])
        {
            arr2[k]=arr[i];
            i++;
        }
        else
        {
            arr2[k]=arr[j];
            j++;
        }
        k++;
        
    }
    if (i>mid)
    {
        while (j<=ub)
        {
            arr2[k]=arr[j];
            j++;
            k++;
        }
        
    }
    else
    {
        while (i<=mid)
        {
            arr2[k]=arr[i];
            i++;
            k++;
        }
        
    }
    for (k = lb; k <= ub; k++)
    {
        arr[k]=arr2[k];
    }
    
    
}
int mergeSort(int arr[],int lb,int ub)
{
    // int loc,lb = 0, ub = N - 1;
    if (lb < ub)
    {
        mid = (lb+ ub)/2;
        mergeSort(arr, lb, mid);
        mergeSort(arr,mid+1, ub);
        merge(arr,lb,mid, ub);        
    }
}
int main()
{
     printf("\nEnter array elements: ");
    for (int a = 0; a < N; a++)
    {
        scanf("%d", &arr[a]);
    }
    printf("Original array is: ");
    for (int i = 0; i < N; i++)
    {
        printf("\t%d", arr[i]);
    }
    int start=0,end=N-1;
    while (start<end)
    {
        mergeSort(arr, lb, ub);
        start++;
    }
    
    printf("\nSorter array is: ");
    for (int i = 0; i < N; i++)
    {
        printf("\t%d", arr[i]);
    }
}