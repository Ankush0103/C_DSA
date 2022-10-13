// LAb Circular queue
#include <stdio.h>
#include <stdlib.h>

// In circular queue element deleted from array can be used again.

struct cqueue
{
    int size;
    int f;
    int r;
    int *arr;
};

int isEmpty(struct cqueue *q)
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

int isFull(struct cqueue *q)
{
    if ((q->r+1)%q->size == q->f)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void enqueue(struct cqueue *q, int val){
    int x;
    x = isFull(q);
    if(x==1){
        printf("Queue is full\n");
    }
    else{
        printf("Enter element to be enqueued\n");
        scanf("%d", &val);
        q->r = (q->r+1)%q->size;
        q->arr[q->r] = val; 
    }
}
int dequeue(struct cqueue *q){
    int y;
    int a = -1;
    y = isEmpty(q);
    if(y==1){
        printf("Queue is Empty\n");
        return -1;
    }
    else{
        q->f = (q->f+1)%q->size;
        a = q->arr[q->f];
        printf("Dequeued element: %d\n", q->arr[q->f]);
        return a;
    }
}

void display(struct cqueue *q){
    int i;
    int y;
    y = isEmpty(q);
    if(y==1){
        printf("Queue is Empty\n");
    }
    else{
        printf("Status of element in queue: \n");
        for(i = (q->f + 1)%q->size; i<=q->r; i++){
            printf("%d\n", q->arr[i]);
        }
    }

}

int main()
{
    int val;
    struct cqueue *q = (struct cqueue *)malloc(sizeof(struct cqueue));
    q->size = 100;
    q->f = q->r = -1;
    q->arr = (int *)malloc(q->size * sizeof(int));

    int option;
    while (1)
    {
        printf(" 1.Enqueue\n 2.Dequeue\n 3.Display\n 4.Exit\n");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            enqueue(q, val);
            break;
        case 2:
            dequeue(q);
            break;
        case 3:
            display(q);
            break;
        case 4: 
             exit(1);
        default: printf("Select correct choice\n");
       }
   }
   return 0;
}