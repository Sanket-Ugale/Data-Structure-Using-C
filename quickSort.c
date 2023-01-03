#include <stdio.h>
#include <conio.h>
#define N 10
int arr[N];
int pivot=0, start=0, end=0,loc, lb = 0, ub = N - 1,temp;

int Partition(int arr[],int lb,int ub)
{
    pivot = arr[lb];
    start = lb;
    end = ub;
    while (start < end)
    {
        while (arr[start] <= pivot)
        {
            start++;
        }
        while (arr[end] > pivot)
        {
            end--;
        }
        if (start < end)
        {
                temp=arr[start];
    arr[start]=arr[end];
    arr[end]=temp;
            // swap(arr[start], arr[end]);
        }
    }
    temp=arr[lb];
    arr[lb]=arr[end];
    arr[end]=temp;
    // swap(arr[lb], arr[end]);
    return end;
}
int QuickSort(int arr[],int lb,int ub)
{
    // int loc,lb = 0, ub = N - 1;
    if (lb < ub)
    {
        loc = Partition(arr, lb, ub);
        QuickSort(arr, lb, loc - 1);
        QuickSort(arr, loc + 1, ub);
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
    QuickSort(arr, lb, ub);
    printf("\nSorter array is: ");
    for (int i = 0; i < N; i++)
    {
        printf("\t%d", arr[i]);
    }
}