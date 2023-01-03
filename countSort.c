#include <stdio.h>
#include <conio.h>
#define N 10
int arr[N], K = 0,i;
int CountSort(int arr[])
{
    for (int i = 0; i < N; i++)
    {
        if (K < arr[i])
        {
            K = arr[i];
        }
    }
    
    int count[K + 1]  , arr2[N];
    for (i = 0; i < N; i++)
    {
        ++count[arr[i]];
    }
    for (i = 1; i <= K; i++)
    {
        count[i] = count[i] + count[i - 1];
    }
    
    for (i = N - 1; i >= 0; i--)
    {
        // arr2[--count[arr[i]]] = arr[i];
         arr2[count[arr[i]] - 1] = arr[i];
        --count[arr[i]];
    }
    for (i = 0; i < N; i++)
    {
        arr[i] = arr2[i];
    }
}
int main()
{
    int flag = 0, temp, i, j, a, min;
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
    CountSort(arr);
    printf("\nSorter array is: ");
    for (i = 0; i < N; i++)
    {
        printf("\t%d", arr[i]);
    }
}