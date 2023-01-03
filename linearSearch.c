#include <stdio.h>
#include <conio.h>
int main()
{
    int arrSize = 10, element, found = 0,
        arr[arrSize];
    printf("\nEnter array elements: ");
    for (int i = 0; i < arrSize; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("\nEnter element to find position in array: ");
    scanf("%d", &element);
    for (int i = 0; i <= arrSize; i++)
    {
        if (element == arr[i])
        {
            printf("\n%d found at %dth position.", element, i);
            found = 1;
            break;
        }
    }
    if (found == 0)
    {
        printf("\n%d not found.", element);
    }
}