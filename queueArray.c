#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

#define N 5

int queue[N];
int front=-1;
int rear=-1;

void enqueue(int data){
    if (rear==N-1)
    {
        printf("Queue Overflow.");
    }
    else if (rear==-1 && front==-1)
    {
        front=rear=0;
        queue[rear]=data;
    }
    else
    {
        rear++;
        queue[rear]=data;
    }
}

void dequeue(){
    if (rear==-1 && front==-1)
    {
        printf("\nQueue is Empty.");
    }
    else if (front==rear)
    {
        front=rear=-1;
    }
    else
    {
        printf("\n%d",queue[front]);
        front++;
    }
}

void display(){
    if (rear==-1 && front==-1)
    {
        printf("\nQueue is empty.");
    }
    else
    {
        printf("\nQueue: ");
        for (int i = front; i < rear+1; i++)
        {
            printf("\t%d",queue[i]);
        }   
    }
}

void peek(){
        if (rear==-1 && front==-1)
    {
        printf("\nQueue is empty.");
    }
    else
    {
        printf("\nTop most Queue element is: %d",queue[front]);   
    }
}

int main(){
    int choice,data;
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
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            printf("\nEnter data to perform Enqueue operation: ");
            scanf("%d",&data);
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
            break;
        }
    }
    
}