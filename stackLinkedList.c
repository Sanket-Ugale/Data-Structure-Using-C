#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <malloc.h>
struct node
{
    int data;
    struct node *next;
};
struct node *top, *temp, *newnode;
void push(int data)
{

    newnode = (struct node *)malloc(sizeof(struct node));
    // printf("\nEnter data to push: ");
    // scanf("%d", &newnode->data);
    newnode->data = data;
    if (top == 0)
    {
        top = newnode;
        newnode->next = 0;
    }
    else
    {
        newnode->next = top;
        top = newnode;
    }
    printf("\nData Pushed.");
}
void pop()
{
    if (top == 0)
    {
        printf("\nStack is Empty.");
    }
    else
    {
        temp = top;
        top = temp->next;
        printf("\n%d poped", temp->data);
        free(temp);
    }
}
void peek()
{
    if (top == 0)
    {
        printf("\nStack is Empty.");
    }
    else
    {
        printf("\nTop element is: %d", top->data);
    }
}
void display()
{
    if (top == 0)
    {
        printf("\nStack is Empty.");
    }
    else
    {
        temp = top;
        while (temp != 0)
        {
            printf("\n%d", temp->data);
            temp = temp->next;
        }
    }
}
void main()
{
    int choice;
    int data;
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
            printf("\nEnter data to push: ");
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