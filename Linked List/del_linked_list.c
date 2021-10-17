#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
} * head;

void create()
{
    struct Node *newNode, *temp;
    int n, data;
    head = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter the number of nodes -> ");
    scanf("%d", &n);

    // Terminate if memory is not allocated
    if (head == NULL)
    {
        printf("Unable to allocate memory.");
        exit(0);
    }

    //Input data of node from the user
    printf("Enter the data for node 1: ");
    scanf("%d", &data);

    head->data = data; //Link data field with data
    head->next = NULL; //Link address field to NULL

    // Create n-1 nodes and add to list
    temp = head;
    for (int i = 1; i < n; i++)
    {
        newNode = (struct Node *)malloc(sizeof(struct Node));

        // If memory is not allocated for newNode
        if (newNode == NULL)
        {
            printf("Unable to allocate memory");
            break;
        }

        printf("Enter the data of node %d: ", i + 1);
        scanf("%d", &data);

        newNode->data = data; //Link data field of newNode
        newNode->next = NULL; //Make sure new node points to NULL

        temp->next = newNode; //Link previous node with newNode
        temp = temp->next;    //Make current node as previous node(Point to next Node)
    }
}

void traverseList()
{
    struct Node *temp;
    // Return if list is empty
    if (head == NULL)
    {
        printf("List is empty.");
        return;
    }
    temp = head;
    while (temp != NULL)
    {
        printf("%d\n", temp->data); //Print data of current node
        temp = temp->next;          //Move to next node
    }
}

void del_Beg()
{
    struct Node *toDel;
    toDel = head;
    head = head->next;
    free(toDel);
    printf("Successfully deleted first node of the array\n");
}

void del_End()
{
    struct Node *toDelete, *secondLastNode;
    if (head == NULL)
    {
        printf("List is already empty.");
    }
    else
    {
        toDelete = head;
        secondLastNode = head;

        //Traverse to the last node of the list
        while (toDelete->next != NULL)
        {
            // getting the 2nd last element
            secondLastNode = toDelete;
            toDelete = toDelete->next;
        }
        if (toDelete == head)
            head = NULL;
        else
        {
            // Disconnect the second last node from the last nodes
            secondLastNode->next = NULL;
        }
        free(toDelete);
        printf("Successfully deleted last node of the array\n");
    }
}

void del_fromAny()
{
    struct Node *toDelete, *prev;

    int pos;
    printf("Enter the position you want to delete-> ");
    scanf("%d", &pos);
    if (head == NULL)
        printf("The list is already empty");
    else
    {
        toDelete = head;
        prev = head;
        for (int i = 1; i < pos; i++)
        {
            prev = toDelete;
            toDelete = toDelete->next;
            if (toDelete == NULL)
                break;
        }
        if (toDelete != NULL)
        {
            if (toDelete == head)
                head = head->next;
            else
            {

                // Previous node gets connected to the after node
                prev->next = toDelete->next;
                // Current requested node deleted
                toDelete->next = NULL;
            }
            free(toDelete);
            printf("Successfully deleted from the list\n");
        }
    }
}

void del_All()
{
    struct Node *temp;
    if (head == NULL)
        printf("List is already empty");

    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
    printf("All the nodes of the list are successfully deleted");
}

int main()
{
    int choice, info;
    do
    {
        printf("\n1.Create a link list\n2.Display Entire List\n3.Delete node from the beginning\n4.Delete node at the end\n5.Delete node from any position\n0.Exit\n\nEnter your choice->");
        scanf("%d", &choice);
        switch (choice)
        {

        case 1:
            create();
            break;

        case 2:
            traverseList();
            break;

        case 3:
            del_Beg();
            break;

        case 4:
            del_End();
            break;

        case 5:
            del_fromAny();
            break;

        case 6:
            del_All();
            break;

        case 0:
            exit(0);

        default:
            printf("\nEnter valid choice \n");
        }
    } while (choice != 0);
}
