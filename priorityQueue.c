// To implement Priority queue using array.
#include <stdio.h>
#include <stdlib.h>
#define MAX 10

void create_queue();
void insert_element(int);
void delete_element(int);
void check_priority(int);
void display_priorityqueue();

int pqueue[MAX];
int front, rear;

void main()
{
    int n, choice;

    create_queue();
    while (1)
    {
        printf("\n\nEnter 1 to insert element by priority ");
        printf("\nEnter 2 to delete element by priority ");
        printf("\nEnter 3 to display priority queue ");
        printf("\nEnter 4 to exit");
        printf("\nEnter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\nEnter element to insert : ");
            scanf("%d", &n);
            insert_element(n);
            break;
        case 2:
            printf("\nEnter element to delete : ");
            scanf("%d", &n);
            delete_element(n);
            break;
        case 3:
            display_priorityqueue();
            break;
        case 4:
            exit(0);
        default:
            printf("\n Please enter valid choice");
        }
    }
}
void create_queue()
{
    front = rear = -1;
}
void insert_element(int data)
{
    if (rear >= MAX - 1)
    {
        printf("\nQUEUE OVERFLOW");
        return;
    }
    if ((front == -1) && (rear == -1))
    {
        front++;
        rear++;
        pqueue[rear] = data;
        return;
    }
    else
        check_priority(data);
    rear++;
}
void check_priority(int data)
{
    int i, j;
    for (i = 0; i <= rear; i++)
    {
        if (data >= pqueue[i])
        {
            for (j = rear + 1; j > i; j--)
            {
                pqueue[j] = pqueue[j - 1];
            }
            pqueue[i] = data;
            return;
        }
    }
    pqueue[i] = data;
}
void delete_element(int data)
{
    int i;
    if ((front == -1) && (rear == -1))
    {
        printf("\nEmpty Queue");
        return;
    }
    for (i = 0; i <= rear; i++)
    {
        if (data == pqueue[i])
        {
            for (; i < rear; i++)
            {
                pqueue[i] = pqueue[i + 1];
            }
            pqueue[i] = -99;
            rear--;
            if (rear == -1)
                front = -1;
            return;
        }
    }
    printf("\n%d element not found in queue", data);
}
void display_priorityqueue()
{
    if ((front == -1) && (rear == -1))
    {
        printf("\nEmpty Queue ");
        return;
    }
    for (; front <= rear; front++)
    {
        printf(" %d ", pqueue[front]);
    }
    front = 0;
}