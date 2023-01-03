#include <stdio.h>
#include <conio.h>
#include <malloc.h>

struct node
{
    int data;
    struct node *next;
};

struct node *temp, *tail, *newnode;
int choice = 1, numberOfNodes = 0, option;

void displayCircularLL()
{
    temp = tail->next;
    printf("\nData in circular linked list is: ");
    while (temp->next != tail->next)
    {
        printf("\t%d", temp->data);
        temp = temp->next;
    }
    printf("\t%d\n", temp->data);

    // printf("\n\t\t%d",numberOfNodes);
}

void createCircularLL()
{
    tail = 0;
    while (choice)
    {
        printf("\n-----------------------------------------------------------------\n");
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("\nEnter data: ");
        scanf("%d", &newnode->data);
        newnode->next = 0;
        if (tail == 0)
        {
            tail = newnode;
            tail->next = newnode;
        }
        else
        {
            newnode->next = tail->next;
            tail->next = newnode;
            tail = newnode;
        }

        numberOfNodes++;
        printf("\nEnter 1 to insert another node otherwise 0: ");
        scanf("%d", &choice);
    }
    displayCircularLL();
}

void insertAtBeg()
{
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->next = 0;
    printf("\nEnter Data: ");
    scanf("%d", &newnode->data);
    if (tail == 0)
    {
        tail = newnode;
        tail->next = newnode;
    }
    else
    {
        newnode->next = tail->next;
        tail->next = newnode;
    }
    numberOfNodes++;

    displayCircularLL();
}

void insertAtEnd()
{
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter Data: ");
    scanf("%d", &newnode->data);
    if (tail == 0)
    {
        tail = newnode;
        tail->next = newnode;
    }
    else
    {
        newnode->next = tail->next;
        tail->next = newnode;
        tail = newnode;
    }
    numberOfNodes++;
    displayCircularLL();
}

void insertAtPos()
{
    int pos;
    printf("\nEnter Position at which you want to add new node: ");
    scanf("%d", &pos);
    if (pos == 1)
    {
        insertAtBeg();
    }
    else if (pos == numberOfNodes)
    {
        insertAtEnd();
    }
    else if (pos > numberOfNodes || pos < 0)
    {
        printf("\nInvalid Position.");
    }
    else
    {
        temp = tail->next;
        int i = 1;
        newnode = (struct node *)malloc(sizeof(struct node));
        newnode->next = 0;
        printf("\nEnter Data: ");
        scanf("%d", &newnode->data);

        while (i < pos - 1)
        {
            temp = temp->next;
            i++;
        }
        newnode->next = temp->next;
        temp->next = newnode;
    }
    numberOfNodes++;

    displayCircularLL();
}

void deleteFromBeg()
{
    temp = tail->next;
    if (tail == 0)
    {
        printf("\nList is Empty.");
    }
    else if (temp->next == temp)
    {
        tail = 0;
        free(temp);
    }
    else
    {
        tail->next = temp->next;
        free(temp);
        numberOfNodes--;
    }
    displayCircularLL();
}

void deleteFromEnd()
{
    struct node *current, *previous;
    current = tail->next;
    if (tail == 0)
    {
        printf("\nList is Empty.");
    }
    else if (current->next == current)
    {
        tail = 0;
        free(current);
    }
    else
    {
        while (current->next != tail->next)
        {
            previous = current;
            current = current->next;
        }
        previous->next = tail->next;
        tail = previous;
        free(current);
        numberOfNodes--;
    }
    displayCircularLL();
}

void deleteFromPos()
{
    struct node *current,*nextnode;
    int pos,i=1;
    current=tail->next;
    printf("\nEnter position to delete node of that position: ");
    scanf("%d",&pos);
    if (pos < 0 || pos > numberOfNodes)
    {
        printf("\nInvalid Postion.");
    }
    else if (pos==1)
    {
        deleteFromBeg();
    }
    else if (pos==numberOfNodes)
    {
        deleteFromEnd();
    }
    else
    {
        while (i<pos-1)
        {
            current=current->next;
            i++;
        }
        nextnode=current->next;
        current->next=nextnode->next;
        free(nextnode);
    }
    displayCircularLL();
}

void reverseCLL(){
    struct node *previous,*current,*nextnode;
    current=tail->next;
    nextnode=current->next;
    if (tail==0)
    {
        printf("\nCircular Linked list is empty.");
    }
    else
    {
        while (current!=tail)
        {
            previous=current;
            current=nextnode;
            nextnode=current->next;
            current->next=previous;
        }
        nextnode->next=tail;
        tail=nextnode;        
    }
    displayCircularLL();
    
}

int main()
{
    createCircularLL();
    while (1)
    {
        printf("\n--------------------------------------------------------------\n");
        printf("\n1. Enter 1 to Insert data at Beginning of Circular LL.");
        printf("\n2. Enter 2 to Insert data at Position in Circular LL.");
        printf("\n3. Enter 3 to Insert data at End of Circular LL.");
        printf("\n4. Enter 4 to Delete data from Beginning of Circular LL.");
        printf("\n5. Enter 5 to Delete data from Position of Circular LL.");
        printf("\n6. Enter 6 to Delete data from End of Circular LL.");
        printf("\n7. Enter 7 to Reverse circular linked list.");
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
