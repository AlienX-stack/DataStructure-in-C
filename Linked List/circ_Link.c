/*
*  Circular Linked List
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} Node;

Node *head;
// Createion of circular Linked List
void createCir()
{
    int n, data;
    Node *newNode, *prev;
    head = (Node *)malloc(sizeof(Node));
    printf("Enter the number of nodes-> ");
    scanf("%d", &n);

    if (head == NULL)
        printf("Memory not allocated");

    // first node
    printf("Enter data for node 1: ");
    scanf("%d", &data);

    head->data = data;
    head->next = NULL;
    prev = head;

    for (int i = 1; i < n; i++)
    {
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &data);

        newNode = (Node *)malloc(sizeof(Node));
        newNode->data = data;
        newNode->next = NULL;
        //Link new node with previous node
        prev->next = newNode;
        // Make new node as the previous node
        prev = newNode;
    }
    // Link last node with the first node
    prev->next = head;
    printf("\nCircular Linked List created successfully\n");
}

// Insert at the Beginning
void insertBegCir()
{
    Node *prev, *newNode;
    int data;
    printf("Enter data-> ");
    scanf("%d", &data);

    newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = head;

    prev = head;
    while (prev->next != head)
    {
        prev = prev->next;
    }
    // Connecting last node with the new Node
    prev->next = newNode;
    // Making new Node as Head
    head = newNode;

    printf("Node Inserted at the beginning successfully\n");
}

void insertEndCir()
{
    Node *prev, *newNode;
    int data;
    printf("Enter the data-> ");
    scanf("%d", &data);

    newNode = (Node *)malloc(sizeof(Node *));
    newNode->data = data;
    newNode->next = NULL;

    prev = head;
    while (prev->next != head)
    {
        prev = prev->next;
    }
    newNode->next = prev->next;
    prev->next = newNode;
}

void nthinsertCir()
{
    int pos, data;
    Node *prev, *cur, *newNode;
    printf("Enter the position where you want to enter-> ");
    scanf("%d", &pos);
    printf("\nEnter the data-> ");
    scanf("%d", &data);

    if (pos == 1)
        insertBegCir();
    else
    {
        newNode = (Node *)malloc(sizeof(Node *));
        newNode->data = data;

        prev = head;
        cur = head;
        for (int i = 2; i <= pos - 1; i++)
        {
            cur = cur->next;
        }

        newNode->next = cur->next;
        cur->next = newNode;
        printf("Node Created Successfully");
    }
}

void delFirst()
{
    Node *cur;
    if (head == NULL)
        printf("The List is empty");
    // Check if there is only one node
    else if (head->next == head)
    {
        head = NULL;
        free(head);
        printf("Beginning node is deleted successfully\n");
    }
    else
    {
        // Loop over till last element(not head)
        cur = head;
        while (cur->next != head)
        {
            cur = cur->next;
        }
        // last node pointing to the next node
        cur->next = head->next;
        free(head);
        head = cur->next;
        printf("Beginning node is deleted successfully\n");
    }
}

void delLast()
{
    Node *prev, *toDel;
    if (head == NULL)
        printf("The list is empty\n");
    else if (head->next == head)
    {
        head = NULL;
        free(head);
        printf("The last node deleted successfully\n");
    }
    else
    {
        // prev = head;
        toDel = head;
        while (toDel->next != head)
        {
            prev = toDel;
            toDel = toDel->next;
        }
        prev->next = toDel->next;
        // toDel->next = NULL;
        free(toDel);
        printf("The last node deleted successfully\n");
    }
}

void nthDelete()
{
    int pos;
    Node *toDel, *prev;
    printf("Enter the position you want to delete-> ");
    scanf("%d", &pos);
    if (head == NULL)
        printf("There is no element present to be deleted \n");
    else if (pos == 1)
    {
        delFirst();
    }
    else
    {
        toDel = head;
        for (int i = 2; i <= pos; i++)
        {
            prev = toDel;
            toDel = toDel->next;
        }
        prev->next = toDel->next;
        free(toDel);
        printf("Node %d is deleted successfully\n", pos);
    }
}

void displayRes()
{
    Node *temp;
    if (head == NULL)
    {
        printf("List is empty\n");
    }

    temp = head;

    do
    {
        printf("%d\n", temp->data);
        temp = temp->next;
    } while (temp != head);
}

int main()
{
    createCir();
    int choice;
    do
    {
        printf("\n1.Display Circular Linked List\n2.Insert At the Beginning \n3.Insert At the End\n4.Insert At the nth position\n5.Delete an element from the beginning\n6.Delete an element from the end\n7.Delete nth element from the list\n0.Exit\n");
        printf("\n......................\nEnter your Choice -> ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 0:
            break;
        case 1:
            displayRes();
            break;

        case 2:
            insertBegCir();
            break;

        case 3:
            insertEndCir();
            break;

        case 4:
            nthinsertCir();
            break;

        case 5:
            delFirst();
            break;
        case 6:
            delLast();
            break;

        case 7:
            nthDelete();
            break;

        default:
            printf("Invalid Choice of options!!! Please check again\n");
            break;
        }
    } while (choice != 0);
}