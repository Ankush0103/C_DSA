// BST Opeartions
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
    // Now we will check previous pointer the place where it points is greater than or less than key.
    struct Node* new = createNode(key);
    if(key<prev->data){
        prev->left = new;
    }
    else{
        prev->right = new;
    }
}

struct Node* inOrderPredecessor(struct Node* root){
    // InorderPredeccessor is leftsubtree's rightmost child.
    root = root->left;
    while(root->right != NULL){
        root = root->right;
    }
    return root;
}

struct Node* deleteNode(struct Node* root, int value){
    struct Node* iPre;
    if(root == NULL){
        return NULL;
    }
    if(root->left == NULL && root->right == NULL){
        free(root);
        return NULL;
    }
    //Search for the node to be deleted
    if(value < root->data){
        root->left = deleteNode(root->left, value);
    }
    else if(value > root->data){
        root->right = deleteNode(root->right, value);
    }
    // Deletion Startegy when the node is found
    else{
        iPre = inOrderPredecessor(root);
        root->data = iPre->data;
        root->left = deleteNode(root->left, iPre->data); // inorder predeccesor will be find in left of tree.
    }
    return root;
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

int height(struct Node* root)
{
    if (root == NULL)
        return -1;
    else {
        // computing the height of each subtree 
        int lside = height(root->left);
        int rside = height(root->right);

        // using the larger one 
        if (lside > rside)
            return (lside + 1);
        else
            return (rside + 1);
    }
}

int totalnodes(struct Node* root){
    if(root == NULL)
        return 0;
    else{
        return totalnodes(root->left) + totalnodes(root->right) + 1;
    }
}

int countLeave(struct Node *root){
    if(root == NULL)
    return 0;
    // Checking for leaf node 
    if(root->left == NULL && root->right == NULL)
        return 1;
    // For internal nodes, return the sum of leaf nodes in left and right sub-tree 
    return countLeave(root->left) + countLeave(root->right);
}

int totalinternalnodes(struct Node * root){
    if(root == NULL){
        return 0;
    }
    if(root->left == NULL && root->right == NULL){
        return 0;
    }
    else{
        return totalinternalnodes(root->left) + totalinternalnodes(root->right) + 1;
    }
}

int totalexternalnodes(struct Node * root){
    if(root == NULL)
        return 0;
    else if(root->left == NULL && root->right == NULL){
        return 1;
    }
    else{
        return totalexternalnodes(root->left) + totalexternalnodes(root->right);
    }
}

int main(){

    struct Node *p = createNode(7);
    p->left = createNode(3);
    p->right = createNode(9);
    p->left->left = createNode(1);
    p->left->right = createNode(4);
    
    //      7
    //     / \
    //    3   9
    //   / \    
    //  1   4

    printf("\nPrinting preOrder\n");
    preOrder(p);
    printf("\n");
    printf("\nPrinting postOrder\n");
    postOrder(p);
    printf("\nPrinting inOrder\n");
    inOrder(p);    
    printf("\nNumber of leaf node: %d\n", countLeave(p));
    printf("\nHeight of binary search tree : %d\n" , height(p));
    printf("\nTotal nodes of binary search tree: %d\n", totalnodes(p));
    printf("\nTotal internalnodes of binary search tree: %d\n", totalinternalnodes(p));
    printf("\nTotal nodes externalnodes of binary search tree: %d\n", totalexternalnodes(p));

    insert(p, 16);

    //      7
    //     / \
    //    3   9
    //   / \   \   
    //  1   4   16
    printf("\nElement Inserted: %d\n", p->right->right->data);
    printf("\nHeight of binary search tree after insertion: %d\n" , height(p));
    printf("\nTotal nodes of binary search tree after insertion: %d\n", totalnodes(p));
    printf("\nNumber of leaf node after insertion: %d\n", countLeave(p));
    printf("\nTotal internalnodes of binary search tree after insertion: %d\n", totalinternalnodes(p));
    printf("\nTotal nodes externalnodes of binary search tree after insertion: %d\n", totalexternalnodes(p));
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

    printf("Initial inorder traversal\n");
    inOrder(p);
    printf("\n");
    printf("Initially: %d\n", p->left->data);
    deleteNode(p, 7);
    printf("Data at root now is %d\n", p->data);
    printf("Finally: %d\n", p->left->data);

    printf("After deletion inorder traversal\n");
    inOrder(p);
    return 0;
}