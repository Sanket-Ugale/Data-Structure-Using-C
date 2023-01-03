#include<stdio.h>
#include<conio.h>
int main(){
    int a[50], size, i, pos, num;
    printf("Enter size of array: ");
    scanf("%d",&size);
    printf("Enter elements of arraty: ");
    for ( i = 0; i < size; i++)
    {
        scanf("%d",&a[i]);
    }
    printf("Array elements are: ");
     for ( i = 0; i < size; i++)
    {
        printf("\t %d",a[i]);
    }
    printf("\nEnter position at which you want to insert element: ");
    scanf("%d",&pos);
    printf("Enter element to insert at %d position: ",pos);
    scanf("%d",&num);
    for ( i = size-1; i >= pos-1; i--)
    {
        a[i+1]=a[i];
    }
    a[pos-1]=num;
    size++;
     printf("Array elements are after insertion: ");
     for ( i = 0; i < size; i++)
    {
        printf("\t %d",a[i]);
    }
}