#include <stdio.h>
#include <stdlib.h>

struct queue
{
    int size;
    int f;
    int r;
    int *arr;
};

int isEmpty(struct queue *q)
{
    if (q->r == q->f)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(struct queue *q)
{
    if (q->r == q->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void enqueue(struct queue *q, int val)
{
    if (isFull(q))
    {
        printf("Queue Overflow!");
    }
    else
    {
        q->r++;
        q->arr[q->r] = val;
    }
}

int dequeue(struct queue *q)
{
    int a = -1;
    if (isEmpty(q))
    {
        printf("No element to dequeue!");
    }
    else
    {
        q->f++;
        a = q->arr[q->f];
    }
    return a;
}

int main()
{
    struct queue q;
    q.size = 100;
    q.f = q.r = -1;
    q.arr = (int *)malloc(q.size * sizeof(int));

    int option;
    while (option != 3)
    {
        printf(" 1.Enqueue\n 2.Dequeue\n 3.Exit\n");
        scanf("%d", &option);
        switch (option)
        {
        case 1: // Enqueue
            enqueue(&q, 12);
            enqueue(&q, 15);
            enqueue(&q, 1);
            if (isEmpty(&q))
            {
                printf("Queue is empty\n");
            }

            if (isFull(&q))
            {
                printf("Queue is full\n");
            }
            else
            {
                printf("Queue is not full\n");
            }
            break;

        case 2: // Dequeue
            printf("Dequeuing element %d\n", dequeue(&q));
            printf("Dequeuing element %d\n", dequeue(&q));
            if (isEmpty(&q))
            {
                printf("Queue is empty\n");
            }

            if (isFull(&q))
            {
                printf("Queue is full\n");
            }
            else
            {
                printf("Queue is not full");
            }
            break;

        case 3: //Exit
            printf("Exit\n");
        }
    }

    if (isEmpty(&q))
    {
        printf("Queue is empty\n");
    }

    if (isFull(&q))
    {
        printf("Queue is full\n");
    }
    else
    {
        printf("Queue is not full");
    }

    return 0;
}