// ////////////////////////////////////////
// Implementation of Stack Using Array
// ///////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>

#define MAX 3
typedef struct Stack
{
    int arr[MAX];
    int top;
} stack;

int overflow(stack s)
{
    if (s.top == MAX - 1)
        return 1;
    return 0;
}

int underflow(stack *s)
{
    if (s->top == -1)
        return 1;
    return 0;
}

void push(stack *s, int n)
{
    s->arr[++s->top] = n;
}

int pop(stack *s)
{
    return s->arr[s->top--];
}

int peek(stack *s)
{
    return s->arr[s->top];
}

int stackSize(stack *s)
{
    return s->top + 1;
}

int main()
{
    stack s;
    int n, ch;
    // If there are no elements in the stack then the default value of the stack is -1
    s.top = -1;
    do
    {
        printf("\n\n1. Push \n2. Pop\n3. Peek \n4. Stack Size\n0. Exit\n------------------------------\n");
        scanf("%d", &ch);

        switch (ch)
        {
        case 0:
            break;

        case 1:
            if (overflow(s))
            {
                printf("Stack is full");
                break;
            }
            printf("\nEnter data-> ");
            scanf("%d", &n);
            push(&s, n);
            printf("Pushed\n");
            break;

        case 2:
            if (underflow(&s))
            {
                printf("Stack is empty");
                break;
            }
            n = pop(&s);
            printf("%d Popped\n", n);
            break;

        case 3:
            if (underflow(&s))
            {
                printf("Stack is empty");
                break;
            }
            n = peek(&s);
            printf("The peek or top element of the stack -> %d", n);
            break;

        case 4:
            printf("\nThe size of the stack is %d", stackSize(&s));
        }
        // printf("%d", s.arr[0]);
    } while (ch != 0);
}