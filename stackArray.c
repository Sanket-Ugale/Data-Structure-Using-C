// Write a program to implement stack ADT using array
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define N 5
int stack[N];
int top = -1, data;
void push(int data)
{
    if (top == N - 1)
    {
        printf("\nStack Overflow.");
    }
    else
    {
        top++;
        stack[top] = data;
    }
}
void pop()
{
    int item;
    if (top == -1)
    {
        printf("\nStack underflow.");
    }
    else
    {
        item = stack[top];
        top--;
        printf("\n%d poped.", item);
    }
}
void peek()
{
    if (top == -1)
    {
        printf("\nStack underflow.");
    }
    else
    {
        printf("\n%d.", stack[top]);
    }
}
void display()
{
    int i;
    for (i = top; i >= 0; i--)
    {
        printf("\n%d\t%d", i, stack[i]);
    }
    printf("\nIndex\tData");
}
void main()
{
    int choice;
    while (1)
    {
        printf("\n------------------------------------------------------------------\n");
        printf("\n1. Press 1 to perform Push() operation.");
        printf("\n2. Press 2 to perform pop() operation.");
        printf("\n3. Press 3 to perform peek() operation.");
        printf("\n4. Press 4 to perform display() operation.");
        printf("\n5. Press 5 to EXIT.");
        printf("\n------------------------------------------------------------------\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\nEnter data to push in stack: ");
            scanf("%d", &data);
            push(data);
            break;

        case 2:
            pop();
            break;

        case 3:
            peek();
            break;

        case 4:
            display();
            break;

        case 5:
            exit(0);
            break;

        default:
            printf("\nPlease Enter valid choice.");
            break;
        }
    }
}