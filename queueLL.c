#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <malloc.h>

struct node
{
    int data;
    struct node *next;
};
struct node *front, *rear, *newnode, *temp;

void enqueue(int data)
{
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->next = 0;
    if (rear == 0 && front == 0)
    {
        front = rear = newnode;
        newnode->data = data;
    }
    else
    {
        rear->next = newnode;
        newnode->data = data;
        rear = newnode;
    }
}

void dequeue()
{
    if (rear == 0 && front == 0)
    {
        printf("\nQueue is Empty.");
    }
    else if (front == rear)
    {
        temp = front;
        printf("\ndequeued element is: %d ", temp->data);
        free(temp);
        front = rear = 0;

    }
    else
    {
        temp = front;
        printf("\ndequeued element is: %d ", temp->data);
        front = temp->next;
        free(temp);
    }
}

void display()
{
    if (rear == 0 && front == 0)
    {
        printf("\nQueue is empty.");
    }
    else
    {
        temp = front;
        printf("\nQueue: ");
        while (temp != 0)
        {
            printf("\t%d", temp->data);
            temp = temp->next;
        }
    }
}

void peek()
{
    temp = front;
    if (rear == 0 && front == 0)
    {
        printf("\nQueue is empty.");
    }
    else
    {
        printf("\nTop most Queue element is: %d", temp->data);
    }
}

int main()
{
    int choice, data;
    front = rear = 0;
    while (1)
    {
        printf("\n-----------------------------------------------------------------\n");
        printf("\n1. Enter 1 to perform Enqueue operation.");
        printf("\n2. Enter 2 to perform Dequeue operation.");
        printf("\n3. Enter 3 to perform peek operation.");
        printf("\n4. Enter 4 to perform Display operation.");
        printf("\n5. Enter 5 to EXIT.");
        printf("\n-----------------------------------------------------------------\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\nEnter data to perform Enqueue operation: ");
            scanf("%d", &data);
            enqueue(data);
            break;

        case 2:
            dequeue();
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
            printf("\nPlease enter valid choice.");
            break;
        }
    }
}