#include<stdio.h>
struct Node{
    int data;
    struct Node* next;
};
int isEmpty(struct Node* top){
    if(top==NULL){
        return 1;
    }
    else{
        return 0;
    }
}

int isFull(struct Node* top){
    struct Node* p = (struct Node*)malloc(sizeof(structNode));
    if(p==NULL){
        return 1;
    }
    else{
        return 0;
    }

}

struct Node* push(struct Node* top, int x){
    if(isFull){
        printf("Stack Overflow\n");
    }
    else{
        struct Node* n = (struct Node*)malloc(sizeof(struct Node));
        n->data = x;
        n->next = top;
        return top;
    }
}
int main(){
    struct Node* top = NULL;
    top = push(top, 78);
    return 0;
}