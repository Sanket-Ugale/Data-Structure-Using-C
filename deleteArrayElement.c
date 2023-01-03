#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
int main()
{
    // Variable declaration
    int deletePos, size, i, a[50], option;

    // Getting Number of elements user want's to insert.
    printf("Enter number of elements you wants to enter in array: ");
    scanf("%d", &size);

    // Get array elements one by one
    printf("Enter Array elements: ");
    for (i = 0; i < size; i++)
    {
        scanf("%d", &a[i]);
    }

    while (1)
    {
        printf("\n1. Enter 1 to delete starting element of array.");
        printf("\n2. Enter 2 to delete element of specified postion.");
        printf("\n3. Enter 3 to delete last element of array.");
        printf("\n4. Enter 4 to EXIT.");
        printf("\nEnter your choice: ");
        scanf("%d", &option);
        switch (option)
        {
            // case 1 to delete 1st element
        case 1:

            // Print all Array elements before deleting element from specific position
            printf("Array before deletion is: ");
            for (i = 0; i < size; i++)
            {
                printf("%d", a[i]);
            }

            // Run loop to delete element from array.
            for (i = 0; i < size - 1; i++)
            {
                a[i] = a[i + 1];
            }

            // reduce size of array after deleting element
            size--;

            // print array after deleting element from array.
            printf("\nArray after deletion is: ");
            for (i = 0; i < size; i++)
            {
                printf("%d", a[i]);
            }
            printf("\n");
            break;

        // case 2 to delete specified position element.
        case 2:
            // Get postion which user wants to delete.
            printf("Enter position of element which you want to delete: ");
            scanf("%d", &deletePos);

            // Print all Array elements before deleting element from specific position
            printf("Array before deletion is: ");
            for (i = 0; i < size; i++)
            {
                printf("%d", a[i]);
            }

            // Run loop to delete element from array.
            for (i = deletePos - 1; i < size - 1; i++)
            {
                a[i] = a[i + 1];
            }

            // reduce size of array after deleting element
            size--;
            // print array after deleting element from array.
            printf("\nArray after deletion is: ");
            for (i = 0; i < size; i++)
            {
                printf("%d", a[i]);
            }
            printf("\n");
            break;

        // Case 3 to delete last element from array.
        case 3:
            size--;
            // print array after deleting element from array.
            printf("\nArray after deletion is: ");
            for (i = 0; i < size; i++)
            {
                printf("%d", a[i]);
            }
            printf("\n");
            break;

        case 4:
            exit(0);
            break;

        default:
            printf("Please enter valid choice.");
            break;
        }
    }
}