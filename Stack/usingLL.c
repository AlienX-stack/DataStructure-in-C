// Stack Implementation using Linked List

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} Node;

Node *head;

void choiceOpt()
{
    printf("Choose from the options below\n 1. Push\n 2. Pop \n 3. Peek \n 4. Display \n 5. Stack Size \n 0. Exit \n.......................");
}

// Push Operation
void Push()
{
    int data;
    Node *ptr = (Node *)malloc(sizeof(Node));
    // If memory not allocated for the newNode
    if (ptr == NULL)
        printf("Not Able to push The element");
    else
    {
        printf("Enter the data you want to push -> ");
        scanf("%d", &data);
        // If the stack is empty
        if (head == NULL)
        {
            ptr->data = data;
            ptr->next = NULL;
            head = ptr;
        }
        else
        {
            ptr->data = data;
            ptr->next = head;
            head = ptr;
        }
        printf("Data Pushed Successfully\n");
    }
}

void Pop()
{
    Node *ptr;
    ptr = head;
    if (ptr == NULL)
        printf("The Stack is empty\n");
    else
    {
        head = head->next;
        free(ptr);
        printf("The Data is popped successfully\n");
    }
}

void Peek()
{
    printf("The Peek element of the stack is %d\n", head->data);
}

void Display()
{
    Node *ptr;
    ptr = head;
    // printf("The Elements of the stack");
    if (ptr == NULL)
    {
        printf("The Stack is Empty\n");
    }
    else
    {
        printf("The Stack elements .....\n");
        while (ptr != NULL)
        {
            printf("%d\n", ptr->data);
            ptr = ptr->next;
        }
    }
}

void sizeStack()
{
    Node *ptr;
    ptr = head;
    int c = 0;
    // printf("The Elements of the stack");
    printf("The size of the stack is ");
    if (ptr == NULL)
    {
        printf("%d", 0);
    }
    else
    {
        while (ptr != NULL)
        {
            ptr = ptr->next;
            c += 1;
        }
        printf("%d", c);
    }
    printf("\n");
}

int main()
{
    int choice = 0;
    do
    {
        choiceOpt();
        printf("\nEnter your Choice -> ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 0:
            break;
        case 1:
            Push();
            break;
        case 2:
            Pop();
            break;
        case 3:
            Peek();
            break;
        case 4:
            Display();
            break;
        case 5:
            sizeStack();
            break;
        default:
            printf("Invalid Input");
        }
    } while (choice != 0);
}