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

void preOrder(struct Node* root){
    if(root!=NULL){
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

int main(){
   // Constructing the root node - using function(recommended)
   struct Node *p = createNode(4);
   struct Node *p1 = createNode(1);
   struct Node *p2 = createNode(6);
   struct Node *p3 = createNode(5);
   struct Node *p4 = createNode(2);
   /* Tree looks like
            4
          /   \
        1       6
      /   \
    5       2  */
   // Linking the root node with left and right children
   p->left = p1;
   p->right = p2;
   p1->left = p3;
   p1->right = p4;

   preOrder(p);
   return 0;
}