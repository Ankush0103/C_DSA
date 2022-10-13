#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};

    struct Node* createNode(int data){
    struct Node *n; //creating a node pointer
    n = (struct Node *)malloc(sizeof(struct Node)); //Allocating memeory in heap
    n->data = data; // Setting the data
    n->left = NULL; // Setting the left and right children to NULL
    n->right = NULL; // Setting the left and right children to NULL
    return n; // Finally return the created node
}

int main(){
    /*
    //Constructing root Node
    struct Node *p;
    p = (struct Node *)malloc(sizeof(struct Node));
    p->data = 2; 
    p->left = NULL;
    p->right = NULL;
    //Constructing second Node
    struct Node *p1;
    p1 = (struct Node *)malloc(sizeof(struct Node));
    p->data = 1 
    p1->left = NULL;
    p1->right = NULL;
    //Constructing third Node
    struct Node *p2;
    p2 = (struct Node *)malloc(sizeof(struct Node));
    p->data = 4; 
    p2->left = NULL;
    p2->right = NULL;
    //Lining the root with left and right children
    p->left = p1;
    p->right = p2;
    */
   // Constructing the root node
   struct Node *p = createNode(2);
   struct Node *p1 = createNode(1);
   struct Node *p2 = createNode(4);

   // Linking the root node with left and right children
   p->left = p1;
   p->right = p2;
   return 0;
}