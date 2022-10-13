// Searching in BST
#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data){
    struct Node *n; // creating a Node pointer
    n = (struct Node *) malloc(sizeof(struct Node)); // Allocating memory in the heap
    n->data = data; // Setting the data
    n->left = NULL; // Setting the left and right children to NULL
    n->right = NULL; // Setting the left and right children to NULL
    return n; // Finally returning the created Node
}

void preOrder(struct  Node* root){
    if(root!=NULL){
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void postOrder(struct  Node* root){
    if(root!=NULL){
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->data);
    }
}

void inOrder(struct  Node* root){
    if(root!=NULL){
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

int isBST(struct  Node* root){
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

void insert(struct Node* root, int key){
    struct Node* prev = NULL;
    while(root!=NULL){
        prev = root;
        if(key == root->data){
            printf("Cannot insert %d. It is already in BST", root->data);
            return;
        }
        else if(key<root->data){
            root = root->left;
        }
        else{
            root= root->right;
        }
    }
    struct Node* new = createNode(key);
    if(key<prev->data){
        prev->left = new;
    }
    else{
        prev->right = new;
    }
}

struct Node * search(struct Node* root, int key){
    if(root==NULL){
        return NULL;
    }
    if(key==root->data){
        return root;
    }
    else if(key<root->data){
        return search(root->left, key);
    }
    else{
        return search(root->right, key);
    }
}

int main(){
     
    // Constructing the root Node - Using Function (Recommended)
    struct Node *p = createNode(5);
    struct Node *p1 = createNode(3);
    struct Node *p2 = createNode(6);
    struct Node *p3 = createNode(1);
    struct Node *p4 = createNode(4);
    // Finally The tree looks like this:
    //      5
    //     / \
    //    3   6
    //   / \
    //  1   4  

    // Linking the root Node with left and right children
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

    printf("\nPrinting preOrder\n");
    preOrder(p);
    printf("\n");
    printf("\nPrinting postOrder\n");
    postOrder(p);
    printf("\nPrinting inOrder\n");
    inOrder(p);    

    insert(p, 16);
    printf("\nElement Inserted: %d\n", p->right->right->data);
    printf("\nAfter insertion Printing preOrder\n");
    preOrder(p);
    printf("\nAfter insertion Printing postOrder\n");
    postOrder(p);
    printf("\nAfter insertion Printing inOrder\n");
    inOrder(p);
    struct Node* n = search(p, 16);
    if(n!=NULL){
    printf("\nFound: %d\n", n->data);
    }
    else{
        printf("\nElement not found\n");
    }
    return 0;
}