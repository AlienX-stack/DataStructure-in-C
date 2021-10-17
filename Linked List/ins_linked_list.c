#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

// Insertion at the beginning
void insert_Atbegin(struct Node **ptr)
{
    struct Node *newNode;
    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = 77;
    newNode->next = *ptr;
    *ptr = newNode;
}

// Insertion at any position
void insert_AtPosition(struct Node **ptr, int pos)
{
    struct Node *newNode;
    struct Node *temp;
    int i = 1;
    newNode = (struct Node *)malloc(sizeof(struct Node));
    temp = *ptr;
    newNode->data = 84;
    if (pos - 1 == 0)
    {
        newNode->next = *ptr;
        *ptr = newNode;
    }
    else
    {
        while (i != pos - 1)
        {
            // Skip to next node until the position is found
            temp = temp->next;
            i++;
        }
        // Link to next node
        newNode->next = temp->next;
        // Link the previous node to new Node
        temp->next = newNode;
    }
}

// Insert after a node
void insert_AftNode(struct Node **ptr, int position)
{
    struct Node *newNode;
    struct Node *temp;
    newNode = (struct Node *)malloc(sizeof(struct Node));
    temp = *ptr;
    int i = 0;
    while (i != position - 1)
    {
        temp = temp->next;
        i++;
    }
    newNode->data = 90;
    newNode->next = temp->next;
    temp->next = newNode;
}

// Insert at the end
void insert_End(struct Node **ptr)
{
    struct Node *temp;
    struct Node *newNode;
    newNode = (struct Node *)malloc(sizeof(struct Node));

    temp = *ptr;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    newNode->data = 111;
    newNode->next = NULL;
    temp->next = newNode;
}

// Traversal
void traversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }
}

int main()
{
    // Creation
    struct Node *head;
    struct Node *second;
    struct Node *third;

    // Allocate memory for nodes in the linked list in heap
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));

    // Link first and second nodes
    head->data = 7;
    head->next = second;

    // Link second and third nodes
    second->data = 14;
    second->next = third;

    // End of linked list
    third->data = 70;
    third->next = NULL;

    // insert_Atbegin(&head);
    // traversal(head);

    int position = 2;
    // insert_AtPosition(&head, position);
    // traversal(head);

    // insert_End(&head);
    // traversal(head);

    insert_AftNode(&head, position);
    traversal(head);

    return 0;
}