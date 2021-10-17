#include <stdio.h>
#include <stdlib.h>

typedef struct Queue
{
    int size;
    int front;
    int rear;
    int *Q;
} queue;

void createQ(queue *q)
{
    int size;
    printf("Enter the size of the queue->");
    scanf("%d", &size);
    q->size = size;
    q->front = q->rear = -1;
    q->Q = (int *)malloc(q->size * sizeof(int));
}

void Enqueue(queue *q)
{
    int data;

    if (q->rear == q->size - 1)
        printf("Queue is full\n");
    else
    {
        printf("Enter the data you want to enter -> ");
        scanf("%d", &data);
        q->rear++;
        q->Q[q->rear] = data;
        printf("Inserted %d\n", data);
    }
}

void Dequeue(queue *q)
{
    if (q->front == q->rear)
        printf("Queue is empty\n");
    else
    {
        q->front++;
        printf("Deleted %d\n", q->Q[q->front]);
    }
}

void DisplayQ(queue q)
{
    int i = 0;
    printf("The elements of the Queue\n");
    for (i = q.front + 1; i <= q.rear; i++)
        printf("%d ", q.Q[i]);
    printf("\n");
}

void choice()
{
    printf("****************/Queue Operations'\'****************\n");
    printf("1. Enqueue \n2. Dequeue \n3. Display \n0. Exit\n");
}

int main()
{
    int opt;
    queue q;
    createQ(&q);
    do
    {
        choice();
        printf("Enter your choice --> ");
        scanf("%d", &opt);
        switch (opt)
        {
        case 0:
            break;
        case 1:
            Enqueue(&q);
            break;
        case 2:
            Dequeue(&q);
            break;
        case 3:
            DisplayQ(q);
            break;
        default:
            printf("Invalid Operations");
        }
    } while (opt != 0);
}