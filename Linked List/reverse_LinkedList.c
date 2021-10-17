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

void revreseList()
{
    struct node *prev, *cur;

    if (head != NULL)
    {
        prev = head;
        cur = head->next;
        head = head->next;

        // Make 1st node as last
        prev->next = NULL;

        while (head != NULL)
        {
            // Move head to the next node from the first
            head = head->next;
            // connecting cur from backwards
            cur->next = prev;

            // Point to the current node to connect more nodes
            prev = cur;
            // point to the current head node
            cur = head;
        }
        head = prev; //After reversed start from head
        printf("\nSuccessfully reversed list\n");
    }
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
    createList();
    printf(".......................\nOriginal list \n");
    displayRes();

    printf(".......................\nReverse list \n");
    revreseList();
    displayRes();
}