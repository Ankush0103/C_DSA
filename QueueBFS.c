#include <stdio.h>
#include <stdlib.h>

struct queue
{
    int size;
    int f;
    int r;
    int *arr;
};

struct queue * createQueue(int size)
{
    struct queue *q = (struct queue *)malloc(sizeof(struct queue));
    q->size = size;
    q->f = q->r = -1;
    q->arr = (int *)malloc(q->size * sizeof(int));
    return q;
}

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

void enqueue(struct queue *q, int val){
    int x;
    x = isFull(q);
    if(x==1){
        printf("Queue is full\n");
    }
    else{
        // printf("Enter element to be pushed\n");
        // scanf("%d", &val);
        q->r++;
        q->arr[q->r] = val;
    }
}

int dequeue(struct queue *q){
    int y;
    int a = -1;
    y = isEmpty(q);
    if(y==1){
        printf("Queue is Empty\n");
        return -1;
    }
    else{
        q->f++;
        a = q->arr[q->f];
        // printf("Dequeued element: %d\n", q->arr[q->f]);
        return a;
    }
}

/*void display(struct queue *q){
    int i;
    int y;
    y = isEmpty(q);
    if(y==1){
        printf("Queue is Empty\n");
    }
    else{
        printf("Status of element in queue: \n");
        for(i=q->f +1 ;i<=q->r;i++){
            printf("%d\n", q->arr[i]);
        }
    }
}*/

// int main()
// {
//     int val;
//     struct queue *q = (struct queue *)malloc(sizeof(struct queue));
//     q->size = 100;
//     q->f = q->r = -1;
//     q->arr = (int *)malloc(q->size * sizeof(int));

//     int option;
//     while (1)
//     {
//         printf(" 1.Enqueue\n 2.Dequeue\n 3.Display\n 4.Exit\n");
//         scanf("%d", &option);
//         switch (option)
//         {
//         case 1:
//             enqueue(q, val);
//             break;
//         case 2:
//             dequeue(q);
//             break;
//         case 3:
//             display(q);
//             break;
//         case 4: 
//              exit(1);
//         default: printf("Select correct choice\n");
//        }
//    }

//     return 0;
// }