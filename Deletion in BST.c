#include<stdio.h>
#include<malloc.h>

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

struct Node * searchIter(struct Node* root, int key){
    while(root!=NULL){
            if(key == root->data){
            return root;
        }
        else if(key<root->data){
            root = root->left;
        }
        else{
            root = root->right;
        }
    }
    return NULL;
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

    printf("Initial inorder traversal\n");
    inOrder(p);
    printf("\n");
    printf("Initially: %d\n", p->left->data);
    deleteNode(p, 3);
    printf("Data at root now is %d\n", p->data);
    printf("Finally: %d\n", p->left->data);

    printf("After deletion inorder traversal\n");
    inOrder(p);
    return 0;
}