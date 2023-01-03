#include <stdio.h>
#include <conio.h>
#include <malloc.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head, *newnode, *temp;
int loop = 1, choice, pos, count = 0, i = 1;

void displayLinkedList()
{
    if (head == 0)
    {
        printf("List is empty.");
    }
    else
    {
        temp = head;
        while (temp != 0)
        {
            printf("\t%d", temp->data);
            temp = temp->next;
        }
    }
}

void insertAtBeginning()
{
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter data you want to insert: ");
    scanf("%d", &newnode->data);
    newnode->next = head;
    head = newnode;
    count++;
    printf("\n Elements of linked list after inserting data at beginning are: ");
    displayLinkedList();
}

void insertAtPosition()
{
    printf("\nEnter position at which you want to insert element: ");
    scanf("%d", &pos);
    // count=0;
    // getLength();
    if (pos > count)
    {
        printf("\nInvalid position.");
    }
    else
    {
        temp = head;
        while (i < pos)
        {
            temp = temp->next;
            i++;
        }
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("\nEnter data you want to insert: ");
        scanf("%d", &newnode->data);
        newnode->next = temp->next;
        temp->next = newnode;
        count++;
    }
    printf("\n Elements of linked list after inserting data at end are: ");
    displayLinkedList();
}

void insertAtEnd()
{
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter data you want to insert: ");
    scanf("%d", &newnode->data);
    newnode->next = 0;
    temp = head;
    while (temp->next != 0)
    {
        temp = temp->next;
    }
    count++;
    temp->next = newnode;
    printf("\n Elements of linked list after inserting data at end are: ");
    displayLinkedList();
}

void deleteFromBeginning()
{
    if (head == 0)
    {
        printf("List is empty.");
    }
    else
    {
        temp = head;
        head = head->next;
        free(temp);
        count--;
        printf("\n Elements of linked list after Delete data from beginning are: ");
        displayLinkedList();
    }
}

void deleteFromPosition()
{
    struct node *nextNode;
    int delPos, i = 1;
    temp = head;
    printf("\nEnter position to delete element from linked list: ");
    scanf("%d", &delPos);
    while (i < delPos)
    {
        temp = temp->next;
        i++;
    }
    nextNode = temp->next;
    temp->next = nextNode->next;
    free(nextNode);
    count--;
    printf("\nElements of linked list are: ");
    displayLinkedList();
}

void deleteFromEnd()
{
    if (head == 0)
    {
        printf("List is empty.");
    }
    else
    {
        struct node *prevNode;
        temp = head;
        while (temp->next != 0)
        {
            prevNode = temp;
            temp = temp->next;
        }
        if (temp == head)
        {
            head = 0;
        }
        else
        {
            prevNode->next = 0;
        }
        free(temp);
        count--;
        printf("\n Elements of linked list after Delete data from End are: ");
        displayLinkedList();
    }
}

void getLength()
{
    temp = head;
    count = 0;
    while (temp != 0)
    {
        count++;
        temp = temp->next;
    }
    printf("Number of nodes are: %d", count);
    count = 0;
}

void reverseLinkedList()
{
    struct node *prevNode, *currentNode, *nextNode;
    prevNode = 0;
    currentNode = nextNode = head;
    while (nextNode != 0)
    {
        nextNode = nextNode->next;
        currentNode->next = prevNode;
        prevNode = currentNode;
        currentNode = nextNode;
    }
    head = prevNode;
    displayLinkedList();
}

int main()
{

    head = 0;
    printf("\n\n------------------------------------------------------------------------------------\n");
    while (loop)
    {
        newnode = (struct node *)malloc(sizeof(struct node));

        printf("\nEnter data:");
        scanf("%d", &newnode->data);
        newnode->next = 0;
        if (head == 0)
        {
            head = temp = newnode;
        }
        else
        {
            temp->next = newnode;
            temp = newnode;
        }
        count++;
        printf("\nTo add new node press 1 otherwise 0: ");
        scanf("%d", &loop);
    }
    printf("\nElements of linked list are: ");
    displayLinkedList();

    while (1)
    {
        printf("\n\n------------------------------------------------------------------------------------\n");
        printf("\n1. Enter 1 to insert element at Beginning in linked list.");
        printf("\n2. Enter 2 to insert element after given position in linked list.");
        printf("\n3. Enter 3 to insert element at End in linked list.");
        printf("\n4. Enter 4 to Delete element from Beginning in linked list.");
        printf("\n5. Enter 5 to Delete element from given position in linked list.");
        printf("\n6. Enter 6 to Delete element from End in linked list.");
        printf("\n7. Enter 7 to get Linked list length.");
        printf("\n8. Enter 8 to Reverse Linked list.");
        printf("\n9. Enter 9 to EXIT.\n");
        printf("\nEnter your choice:");
        scanf("%d", &choice);
        printf("\n");
        switch (choice)
        {
        case 1:
            insertAtBeginning();
            break;

        case 2:
            insertAtPosition();
            break;

        case 3:
            insertAtEnd();
            break;

        case 4:
            deleteFromBeginning();
            break;

        case 5:
            deleteFromPosition();
            break;

        case 6:
            deleteFromEnd();
            break;

        case 7:
            getLength();
            break;

        case 8:
            reverseLinkedList();
            break;

        case 9:
            exit(0);
            break;

        default:
            printf("\n Please enter valid choice.");
            break;
        }
    }
    return 0;
}