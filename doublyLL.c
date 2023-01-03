#include <stdio.h>
#include <conio.h>
#include <malloc.h>
struct node
{
    struct node *prevAdd;
    int data;
    struct node *nextAdd;
};
struct node *head, *newnode, *temp, *tail;
int numberOfNodes = 0;
void displayDoublyLL()
{
    temp = head;
    while (temp != 0)
    {
        printf("\t%d", temp->data);
        temp = temp->nextAdd;
    }
    printf("\n");
}
void createNode()
{
    head = 0;
    int choice = 1;
    printf("\n--------------------------------------------------------------------------------------------\n");
    while (choice)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("\nEnter Data: ");
        scanf("%d", &newnode->data);
        newnode->nextAdd = 0;
        newnode->prevAdd = 0;
        if (head == 0)
        {
            head = temp = newnode;
            // numberOfNodes++;
        }
        else
        {
            temp->nextAdd = newnode;
            newnode->prevAdd = temp;
            temp = newnode;
            tail = temp;
        }
        numberOfNodes++;
        printf("\nEnter 1 to add one more node otherwise 0: ");
        scanf("%d", &choice);
    }
    printf("Elements of doubly Linked list are: ");
    displayDoublyLL();
}
void insertAtBeg()
{
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter data to insert at beginning of doubly Linked List: ");
    scanf("%d", &newnode->data);
    head->prevAdd = newnode;
    newnode->nextAdd = head;
    head = newnode;
    numberOfNodes++;
    printf("\nData in doubly linked list are: ");
    displayDoublyLL();
}
void insertAtEnd()
{
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter data to insert at End of doubly Linked List: ");
    scanf("%d", &newnode->data);
    newnode->nextAdd = 0;
    tail->nextAdd = newnode;
    newnode->prevAdd = tail;
    tail = newnode;
    printf("\nData in doubly linked list are: ");
    displayDoublyLL();
}
void insertAtPos()
{
    int i = 1, pos;
    printf("\nEnter Posiotion at which you want to insert new node: ");
    scanf("%d", &pos);
    if (pos > numberOfNodes && pos < 0)
    {
        printf("\nInvalid position");
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
        temp = head;
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("\nEnter data you want to insert in newnode: ");
        scanf("%d", &newnode->data);
        while (i < pos - 1)
        {
            temp = temp->nextAdd;
            i++;
        }
        newnode->prevAdd = temp;
        newnode->nextAdd = temp->nextAdd;
        temp->nextAdd = newnode;
        newnode->nextAdd->prevAdd = newnode;
        printf("Elements in doubly linked list are: ");
        displayDoublyLL();
    }
}
void DeleteFromBeg()
{
    if (head == 0)
    {
        printf("List is empty.");
    }
    else
    {
        temp = head;
        head = head->nextAdd;
        head->prevAdd = 0;
        free(temp);
        numberOfNodes--;
        printf("Elements in doubly linked list are: ");
        displayDoublyLL();
    }
}
void DeleteFromPos()
{
    int pos, i = 0;
    temp = head;
    printf("\nEnter position at which node you want to delete.");
    scanf("%d", &pos);
    if (pos == 1)
    {
        DeleteFromBeg();
    }
    else
    {
        while (i < pos)
        {
            temp = temp->nextAdd;
            i++;
        }
        temp->prevAdd->nextAdd = temp->nextAdd;
        temp->nextAdd->prevAdd = temp->prevAdd;
        free(temp);
        numberOfNodes--;
        printf("Elements in doubly linked list are: ");
        displayDoublyLL();
    }
}
void DeleteFromEnd()
{
    if (tail == 0)
    {
        printf("List is empty.");
    }
    else
    {
        temp = tail;
        tail->prevAdd->nextAdd = 0;
        tail = tail->prevAdd;
        free(temp);
        numberOfNodes--;
        printf("Elements in doubly linked list are: ");
        displayDoublyLL();
    }
}
void reverseDoublyLL(){
    struct node *nextNode;
    temp=head;
    while (temp!=0)
    {
        nextNode=temp->nextAdd;
        temp->nextAdd=temp->prevAdd;
        temp->prevAdd=nextNode;  
        temp=nextNode;      
    }
    temp=tail;
    tail=head;
    head=temp;
    printf("\nReversed Doubly Linked list is: ");
    displayDoublyLL();
}
int main()
{
    int option = 0;
    createNode();
    while (1)
    {
        printf("\n--------------------------------------------------------------------------------------------\n");
        printf("\n1.press 1 to insert new node at beginning.");
        printf("\n2.press 2 to insert new node at position.");
        printf("\n3.press 3 to insert new node at end.");
        printf("\n4.press 4 to delete node from beginning.");
        printf("\n5.press 5 to delete node from position.");
        printf("\n6.press 6 to delete node from end.");
        printf("\n7.press 7 to Reverse Doubly linked list.");
        printf("\n8.press 8 to Exit.");
        printf("\nEnter your choice: ");
        scanf("%d", &option);
        printf("\n--------------------------------------------------------------------------------------------\n");
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
            DeleteFromBeg();
            break;

        case 5:
            DeleteFromPos();
            break;

        case 6:
            DeleteFromEnd();
            break;

        case 7:
             reverseDoublyLL();
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