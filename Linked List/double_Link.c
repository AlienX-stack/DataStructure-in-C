#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    struct node *prev;
    struct node *next;
    int data;
} Node;

Node *head;

// Create a double Linked List
void createDouble()
{
    int n, data;
    Node *newNode, *temp;
    head = (Node *)malloc(sizeof(Node));
    printf("Enter the number of nodes -> ");
    scanf("%d", &n);

    if (head == NULL)
        printf("Memory not allocated");

    // First Node
    printf("Enter data for node 1: ");
    scanf("%d", &data);

    head->prev = head->next = NULL;
    head->data = data;

    temp = head;

    for (int i = 2; i <= n; i++)
    {
        newNode = (Node *)malloc(sizeof(Node));
        printf("Enter data for node %d: ", i);
        scanf("%d", &data);

        newNode->data = data;
        // Link new node with the previous node
        newNode->prev = temp;
        newNode->next = NULL;
        //Link previous node with the new node
        temp->next = newNode;
        // Make newNode the last node
        temp = newNode;
    }
    printf("Double Linked List created successfully\n");
}

void traverseFirst()
{
    Node *temp;
    temp = head;
    while (temp != NULL)
    {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}

void traverseLast()
{
    Node *temp;

    for (temp = head; temp->next != NULL; temp = temp->next)
        ;
    for (; temp != NULL; temp = temp->prev)
        printf("%d\n", temp->data);
}

void insBeg()
{
    Node *newNode;
    int data;

    if (head == NULL)
        printf("List is empty");

    else
    {
        newNode = (Node *)malloc(sizeof(Node));
        printf("Enter the data you want to enter-> ");
        scanf("%d", &data);

        newNode->data = data;
        newNode->prev = NULL;
        // Point to the next node which is currently head
        newNode->next = head;

        // Link previous of head with newNode
        head->prev = newNode;
        head = newNode;
        printf("Node created successfully at the beginning \n");
    }
}

void insEnd()
{
    Node *newNode, *prev;
    int data;
    if (head == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        newNode = (Node *)malloc(sizeof(Node));
        prev = head;
        while (prev->next != NULL)
        {
            prev = prev->next;
        }
        printf("Enter the data for the new node ->");
        scanf("%d", &data);
        newNode->data = data;
        newNode->prev = prev;
        prev->next = newNode;
        newNode->next = NULL;
        printf("The node created at the end successfully\n");
    }
}

void nthIns()
{
    Node *newNode, *temp;
    int n, data;
    if (head == NULL)
        printf("The list is empty");
    else
    {
        newNode = (Node *)malloc(sizeof(Node));
        printf("Enter the positon where you want to enter the node -> ");
        scanf("%d", &n);

        if (n == 1)
            insBeg();
        else
        {
            temp = head;
            for (int i = 1; i < n - 1; i++)
            {
                temp = temp->next;
            }

            printf("Enter the data for the newNode - > ");
            scanf("%d", &data);
            newNode->data = data;
            // Link previous of newNode to the previous Node
            newNode->prev = temp;
            // Link next of newNode to the next of the previous node
            newNode->next = temp->next;
            // Previous node pointing to the newNode
            temp->next = newNode;
        }
    }
}

void delBeg()
{
    Node *temp;
    if (head == NULL)
    {
        printf("The list is already empty");
    }
    temp = head;
    head = head->next;
    free(temp);
    printf("Node is deleted from the beginning successfully\n");
}

void delEnd()
{
    Node *temp, *prevNode;
    temp = head;
    if (head == NULL)
    {
        printf("The list is already empty");
    }

    while (temp->next != NULL)
    {
        prevNode = temp;
        temp = temp->next;
    }
    prevNode->next = NULL;
    temp->prev = NULL;
    free(temp);
    printf("Node is deleted from the end successfully \n");
}

void delAtPos()
{
    Node *temp, *prevNode;
    int pos;
    printf("Enter the position you want to delete the Node-> ");
    scanf("%d", &pos);
    temp = head;
    if (pos == 1)
        delBeg();
    else
    {
        for (int i = 1; i <= pos - 1; i++)
        {
            prevNode = temp;
            temp = temp->next;
        }
        prevNode->next = temp->next;
        temp->next = temp->prev = NULL;
        free(temp);
        printf("Node is successfully deleted from the %dth position", pos);
    }
}

int main()
{
    createDouble();
    int choice;
    do
    {
        printf("\n0. Exit \n1. Display Double Linked List from the first\n2. Display Double Linked List from the last\n3. Insert at the Beginning\n4. Insert at the End \n5. Insert at nth Node \n6. Delete from the beginning\n7. Delete from the End\n8. Delete from nth position\n.................................\n");
        scanf("%d", &choice);
        printf("\n");
        switch (choice)
        {
        case 0:
            break;
        case 1:
            traverseFirst();
            break;
        case 2:
            traverseLast();
            break;
        case 3:
            insBeg();
            break;
        case 4:
            insEnd();
            break;
        case 5:
            nthIns();
            break;
        case 6:
            delBeg();
            break;
        case 7:
            delEnd();
            break;
        case 8:
            delAtPos();
            break;
        default:
            printf("Invalid Choice\n");
        }
        /* code */
    } while (choice != 0);
}