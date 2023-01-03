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
        printf("%d \t",a[i]);
    }
}