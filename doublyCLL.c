#include <stdio.h>
#include <conio.h>
#include <malloc.h>

struct node
{
    struct node *previous;
    int data;
    struct node *next;
};

struct node *newnode, *head, *tail, *next, *previous, *temp;
int choice = 1, option, numberOfNodes = 0;

void displayCDLL()
{
    temp = head;
    if (head == 0)
    {
        printf("\nList is Empty.");
    }
    else
    {
        printf("\nData in doubly circular Linked list: ");
        while (temp != tail)
        {
            printf("\t%d", temp->data);
            temp = temp->next;
        }
        printf("\t%d", temp->data);
    }
}

void createCDLL()
{
    while (choice)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("\n--------------------------------------------------------------\n");
        printf("\nEnter data: ");
        scanf("%d", &newnode->data);
        if (head == 0)
        {
            head = tail = newnode;
            head->next = head;
            head->previous = head;
        }
        else
        {
            tail->next = newnode;
            newnode->previous = tail;
            newnode->next = head;
            head->previous = newnode;
            tail = newnode;
        }
        numberOfNodes++;
        printf("\nEnter 1 to insert new node otherwise 0: ");
        scanf("%d", &choice);
    }
    displayCDLL();
}

void insertAtBeg()
{

    newnode = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter data: ");
    scanf("%d", &newnode->data);
    if (head == 0)
    {
        head = tail = newnode;
        newnode->next = tail;
        newnode->previous = tail;
    }
    else
    {
        newnode->next = head;
        newnode->previous = tail;
        head->previous = tail;
        tail->next = newnode;
        head = newnode;
    }
    numberOfNodes++;
    displayCDLL();
}

void insertAtEnd()
{
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter data: ");
    scanf("%d", &newnode->data);
    if (head == 0)
    {
        head = tail = newnode;
        newnode->next = tail;
        newnode->previous = tail;
    }
    else
    {
        newnode->next = head;
        tail->next = newnode;
        newnode->previous = tail;
        head->previous = newnode;
        tail = newnode;
    }
    numberOfNodes++;
    displayCDLL();
}

void insertAtPos()
{
    int pos, i = 1;
    printf("\nEnter position at which you want to insert node: ");
    scanf("%d", &pos);
    if (pos > numberOfNodes || pos < 1)
    {
        printf("\nInvalid position.");
    }
    else if (pos == 1)
    {
        insertAtBeg();
    }
    else if (pos == numberOfNodes)
    {
        insertAtEnd();
    }
    else
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("\nEnter Data: ");
        scanf("%d", &newnode->data);
        temp = head;
        while (i < pos - 1)
        {
            temp = temp->next;
            i++;
        }
        newnode->previous = temp;
        newnode->next = temp->next;
        temp->next->previous = newnode;
        temp->next = newnode;
    }
    numberOfNodes++;
    displayCDLL();
}

void deleteFromBeg()
{
    temp = head;
    if (head == 0)
    {
        printf("\nList is Empty.");
    }
    else if (head->next == tail)
    {
        head = tail = 0;
        free(temp);
    }
    else
    {
        head = head->next;
        head->previous = tail;
        tail->next = head;
        free(temp);
        numberOfNodes--;
        displayCDLL();
    }
}

void deleteFromEnd()
{
    temp = tail;
    if (tail == 0)
    {
        printf("\nList is Empty.");
    }
    else if (head->next == tail)
    {
        head = tail = 0;
        free(temp);
    }
    else
    {
        tail = tail->previous;
        tail->next = head;
        head->previous = tail;
        free(temp);
        numberOfNodes--;
        displayCDLL();
    }
    numberOfNodes--;
    displayCDLL();
}

void deleteFromPos()
{
    int pos, i = 1;
    printf("\nEnter position to delete node: ");
    scanf("%d", &pos);
    if (pos > numberOfNodes || pos < 1)
    {
        printf("\nInvalid position.");
    }
    else if (pos == 1)
    {
        deleteFromBeg();
    }
    else if (pos == numberOfNodes)
    {
        deleteFromEnd();
    }
    else
    {
        temp = head;
        while (i < pos)
        {
            temp = temp->next;
            i++;
        }
        temp->previous->next = temp->next;
        temp->next->previous = temp->previous;
        if (temp->next == head)
        {
            tail = temp->previous;
        }

        free(temp);
        numberOfNodes--;
        displayCDLL();
    }
}

void reverseCLL()
{
    struct node *nextNode;
    temp=head;
    if (head==0)
    {
        printf("\nList is Empty.");
    }
    else
    {
        while (temp!=tail)
        {
            nextNode=temp->next;
            temp->next=temp->previous;
            temp->previous=nextNode;
            temp=nextNode;
        }
        temp->next=temp->previous;
        temp->previous=head;
        temp=head;
        head=tail;
        tail=temp;

    }
    
    displayCDLL();
}

int main()
{
    createCDLL();
    while (1)
    {
        printf("\n--------------------------------------------------------------\n");
        printf("\n1. Enter 1 to Insert data at Beginning of Circular DLL.");
        printf("\n2. Enter 2 to Insert data at Position in Circular DLL.");
        printf("\n3. Enter 3 to Insert data at End of Circular DLL.");
        printf("\n4. Enter 4 to Delete data from Beginning of Circular DLL.");
        printf("\n5. Enter 5 to Delete data from Position of Circular DLL.");
        printf("\n6. Enter 6 to Delete data from End of Circular DLL.");
        printf("\n7. Enter 7 to Reverse circular Doubly linked list.");
        printf("\n8. Enter 8 to Exit.");
        printf("\n\nEnter your choice: ");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            insertAtBeg();
            break;

        case 2:
            insertAtPos();
            break;

        case 3:
            insertAtEnd();
            break;

        case 4:
            deleteFromBeg();
            break;

        case 5:
            deleteFromPos();
            break;

        case 6:
            deleteFromEnd();
            break;

        case 7:
            reverseCLL();
            break;

        case 8:
            exit(0);
            break;

        default:
            printf("\nPlease enter valid choice.");
            break;
        }
    }
}