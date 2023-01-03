#include <stdio.h>
#include <conio.h>
#define N 10
int arr[N];
int main()
{
    int flag = 0, temp, i, j, a,min;
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

    for (i = 0; i < N - 1; i++)
    {
        min = i;
        for (j = i + 1; j < N; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
        if (min != i)
        {
            temp=arr[i];
            arr[i]= arr[min];
            arr[min]=temp;
        }
    }
    printf("\nSorter array is: ");
    for (i = 0; i < N; i++)
    {
        printf("\t%d", arr[i]);
    }
}