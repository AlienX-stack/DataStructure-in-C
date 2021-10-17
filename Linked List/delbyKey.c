#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
} * head;

void createList()
{
    struct node *newNode, *temp;
    int n, data;
    head = (struct node *)malloc(sizeof(struct node));
    printf("Enter the number of nodes you want to create-> ");
    scanf("%d", &n);

    // Check if memory is not allocated
    if (head == NULL)
        printf("Memory is not allocated\n");
    else
    {
        // Input data for the first node
        printf("Enter data for node 1: ");
        scanf("%d", &data);
        head->data = data;
        head->next = NULL;

        // create n-1 nodes
        temp = head;
        for (int i = 1; i < n; i++)
        {
            newNode = (struct node *)malloc(sizeof(struct node));
            if (newNode == NULL)
            {
                printf("Memory not allocated\n");
                break;
            }
            else
            {
                printf("Enter data node for %d: ", i + 1);
                scanf("%d", &data);
                newNode->data = data;
                temp->next = newNode; //Link previous node to newNode
                temp = temp->next;    //Move to current node
            }
        }
    }
}

void delFirstKey()
{
    int key;
    struct node *toDel;
    struct node *prev;
    printf("Enter the key element to delete-> ");
    scanf("%d", &key);
    toDel = head;
    if (head != NULL && head->data == key)
    {
        head = head->next;
        free(toDel);
        printf("Key element %d is deleted from the index 0", key);
    }
    else
    {
        prev = head;
        while (toDel->data != key)
        {
            prev = toDel;
            toDel = toDel->next;
        }
        // Make the previous node link to the next Node
        prev->next = toDel->next;
        // Set the toDel next to NUll for deletion
        toDel->next = NULL;
        free(toDel);
        printf("Successfully Deleted from the list\n");
    }
}

// Delete last node having data as the given key
void delLastKey()
{
    int key;
    struct node *prevToLast, *lastNodeToDel, *prev, *cur;
    printf("Enter the key element you want to delete-> ");
    scanf("%d", &key);

    prev = NULL;
    prevToLast = NULL;
    lastNodeToDel = NULL;

    /* Check if head node contains key */
    if (head != NULL && head->data == key)
    {
        // Copy head node reference to last node to del
        lastNodeToDel = head;
    }

    cur = head;

    /* For each node in the list */
    while (cur != NULL)
    {
        // Current node contains key
        if (cur->data == key)
        {
            lastNodeToDel = cur;

            // Adjust links for previous node
            if (prev != NULL)
            {
                prevToLast = prev;
            }
        }
        prev = cur;
        cur = cur->next;
    }

    // Delete last element if key found
    if (lastNodeToDel != NULL)
    {
        // Link prev last with node next to last node to delete
        if (prevToLast != NULL)
        {
            prevToLast->next = lastNodeToDel->next;
        }

        // Adjust head link if head needs to be deleted
        if (lastNodeToDel == head)
        {
            head = head->next;
        }

        // Delete node
        free(lastNodeToDel);
    }
}

void delAllKey()
{
    int key;
    struct node *toDel, *cur, *prev;
    printf("Enter the key to delete-> ");
    scanf("%d", &key);

    while (head != NULL && head->data == key)
    {
        toDel = head;
        head = head->next;
        free(toDel);
    }

    prev = NULL;
    cur = head;

    // For each node in the list
    while (cur != NULL)
    {
        if (cur->data == key)
        {
            // If key element
            if (prev != NULL)
            {
                prev->next = cur->next;
            }
            // Delete current node
            free(cur);
            // Move to next node
            cur = prev->next;
        }

        // If not key element
        else
        {
            prev = cur;
            cur = cur->next;
        }
    }

    printf("The key elements are deleted successfully\n");
}

void displayRes()
{
    struct node *temp;
    if (head == NULL)
    {
        printf("List is empty");
        return;
    }
    temp = head;
    while (temp != NULL)
    {
        printf("%d\n", temp->data);
        temp = temp->next; //Move to next Node
    }
}

int main()
{
    int choice;
    createList();
    do
    {
        printf("\nDeleting element by key\n.............................. \n1. Delete an key element from first\n2. Delete an key element from last\n3. Delete all the key elements\n4. Display Result\n0. Exit \n Enter your choice ->");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            delFirstKey();
            break;

        case 2:
            delLastKey();
            break;

        case 3:
            delAllKey();
            break;

        case 4:
            displayRes();
            break;

        case 0:
            exit(0);
            break;

        default:
            printf("Invalid choice");
        }
    } while (choice != 0);
}