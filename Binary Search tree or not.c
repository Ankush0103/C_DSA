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

void postOrder(struct Node* root){
    if(root!=NULL){
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->data);
    }
}

void inOrder(struct Node* root){
    if(root!=NULL){
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

int isBST(struct Node* root){
    static struct Node *prev = NULL;
    if(root!=NULL){
        if(!isBST(root->left)){
            return 0;
        }
        if(prev!=NULL && root->data <= prev->data){
            return 0;
        }
        prev = root;
        return isBST(root->right);
    }
    else{
        return 1;
    }
}


int main(){
   // Constructing the root node - using function(recommended)
   struct Node *p = createNode(5);
   struct Node *p1 = createNode(3);
   struct Node *p2 = createNode(6);
   struct Node *p3 = createNode(1);
   struct Node *p4 = createNode(4);
   /* Tree looks like
            5
          /   \
        3       6
      /   \
    1       4  */
   // Linking the root node with left and right children
   p->left = p1;
   p->right = p2;
   p1->left = p3;
   p1->right = p4;

//    printf("Printing preOrder\n");
//    preOrder(p);
//    printf("\n");
//    printf("Printing postOrder\n");
//    postOrder(p);
//    printf("\n");
   printf("Printing inOrder\n");
   inOrder(p);
   printf("\n");
   //printf("%d", isBST(p));
   if(isBST(p)){
       printf("This is a BST\n");
   }
   else{
       printf("This is not a BST\n");
   }
   return 0;
}  