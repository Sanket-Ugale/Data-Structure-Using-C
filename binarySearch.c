#include <stdio.h>
#include <conio.h>
#define N 10
int arr[N];
int main()
{
    int element, found = 0, l, r, mid;
    printf("\nEnter array elements: ");
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("\nEnter element to find position in array using binary search: ");
    scanf("%d", &element);
    l=0;
    r=N-1;
    while (l <= r)
    {
        mid = (l + r) / 2;
        if (element == arr[mid])
        {
            printf("\n%d found at %dth position.", element, mid);
            found = 1;
            break;
        }
        else if (element < arr[mid])
        {
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    if (found == 0)
    {
        printf("\n%d not found.", element);
    }
}