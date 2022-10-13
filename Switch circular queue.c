// Switch circular queue
#include <stdio.h>
#include <stdlib.h>

// In circular queue the element deleted from array can be used in particular index unlike linear array.

struct circularqueue
{
    int size;
    int f;
    int r;
    int *arr;
};

int isEmpty(struct circularqueue *q)
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

int isFull(struct circularqueue *q)
{
    if ((q->r + 1) % q->size == q->f)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void enqueue(struct circularqueue *q, int val)
{
    if (isFull(q))
    {
        printf("Queue Overflow!");
    }
    else
    {
        q->r = (q->r + 1) % q->size;
        q->arr[q->r] = val;
        printf("Enqueued element: %d\n", val);
    }
}

int dequeue(struct circularqueue *q)
{
    int a = -1;
    if (isEmpty(q))
    {
        printf("No element to dequeue!");
    }
    else
    {
        q->f = (q->f + 1) % q->size;
        a = q->arr[q->f];
    }
    return a;
}

int main()
{
    struct circularqueue q;
    q.size = 4;
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
                printf("Queue is not full\n");
            }
            break;
        case 3: // Exit
            printf("Exit\n");
            break;
        }
    }

    return 0;
}