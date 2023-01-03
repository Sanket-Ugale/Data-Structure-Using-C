#include <stdio.h>
#include <conio.h>
#define N 10
int arr[N];
int main()
{
    int flag = 0, temp, i;
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
    for (i = 0; i < N - 1; i++)
    {
        flag = 0;
        for (int j = 0; j < N - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                flag = 1;
            }
        }
        if (flag == 0)
        {
            break;
        }
    }
    printf("\nNumber of pass = %d", i);
    printf("\nSorter array is: ");
    for (int i = 0; i < N; i++)
    {
        printf("\t%d", arr[i]);
    }
}