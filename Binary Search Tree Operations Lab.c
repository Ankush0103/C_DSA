// BST Operations using switch case.
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *insert(struct Node *ptr, int inum)
{
    if (ptr == NULL)
    {
        ptr = (struct Node *)malloc(sizeof(struct Node));
        ptr->data = inum;
        ptr->left = NULL;
        ptr->right = NULL;
    }
    else if (inum < ptr->data)
        ptr->left = insert(ptr->left, inum);
    else if (inum > ptr->data)
        ptr->right = insert(ptr->right, inum);
    else
        printf("\nCannot insert %d. It is already present in BST\n", inum);
    return ptr;
}

struct Node *del(struct Node *ptr, int dnum)
{
    struct Node *tmp, *succ;

    if (ptr == NULL)
    {
        printf("\nNumber is not present in BST\n");
        return (ptr);
    }
    if (dnum < ptr->data)
        ptr->left = del(ptr->left, dnum);
    else if (dnum > ptr->data)
        ptr->right = del(ptr->right, dnum);
    else
    {

        if (ptr->left != NULL && ptr->right != NULL)
        {
            succ = ptr->right;
            while (succ->left)
                succ = succ->left;
            ptr->data = succ->data;
            ptr->right = del(ptr->right, succ->data);
        }
        else
        {
            tmp = ptr;
            if (ptr->left != NULL)
                ptr = ptr->left;
            else if (ptr->right != NULL)
                ptr = ptr->right;
            else
                ptr = NULL;
            free(tmp);
        }
    }
    return ptr;
}

struct Node *search(struct Node *ptr, int snum)
{
    if (ptr == NULL)
    {
        printf("%d is not present in BST\n", snum);
        return NULL;
    }
    else if (snum < ptr->data)
        return search(ptr->left, snum);
    else if (snum > ptr->data)
        return search(ptr->right, snum);
    else
        return ptr;
}

struct Node *Minimum(struct Node *ptr)
{
    if (ptr == NULL)
        return NULL;
    else if (ptr->left == NULL)
        return ptr;
    else
        return Minimum(ptr->left);
}

struct Node *Maximum(struct Node *ptr)
{
    if (ptr == NULL)
        return NULL;
    else if (ptr->right == NULL)
        return ptr;
    else
        return Maximum(ptr->right);
}

void preOrder(struct Node *ptr)
{
    if (ptr == NULL)
        return;
    printf("%d  ", ptr->data);
    preOrder(ptr->left);
    preOrder(ptr->right);
}

void inOrder(struct Node *ptr)
{
    if (ptr == NULL)
        return;
    inOrder(ptr->left);
    printf("%d  ", ptr->data);
    inOrder(ptr->right);
}

void postOrder(struct Node *ptr)
{
    if (ptr == NULL)
        return;
    postOrder(ptr->left);
    postOrder(ptr->right);
    printf("%d  ", ptr->data);
}

int height(struct Node *ptr)
{
    int h_left, h_right;

    if (ptr == NULL)

        return 0;
    if (ptr->left == NULL && ptr->right == NULL)
        return 0;
    // computing the height of each subtree
    int lside = height(ptr->left);
    int rside = height(ptr->right);

    // using the larger one
    if (lside > rside)
        return (lside + 1);
    else
        return (rside + 1);
}

int countLeaf(struct Node *Node)
{
    if (Node == NULL)
        return 0;
    if (Node->left == NULL && Node->right == NULL)
        return 1;
    else
        return countLeaf(Node->left) +
               countLeaf(Node->right);
}

int totalNodes(struct Node *root)
{
    if (root == NULL)
        return 0;
    else
    {
        return totalNodes(root->left) + totalNodes(root->right) + 1;
    }
}

void mirrorimage(struct Node *root)
{
    if (root != NULL)
    {
        struct Node *temp;
        mirrorimage(root->left);
        mirrorimage(root->right);
        temp = root->left;
        root->left = root->right;
        root->right = temp;
    }
}

int main()
{ // 50, 45, 35, 40, 25, 70, 60, 75, 80
    // Binary Seacrh Tree after insertion of required numbers will look like this.
    //      50
    //     / \
    //    35   70
    //   / \   /  \
    //  25  40 60  75
    //        \     \
    //          45     80
    struct Node *root = NULL, *ptr;
    int option, n;

    while (1)
    {
        printf("\n1.Insert, 2.Delete, 3.Search\n");
        printf("4.preOrder Traversal, 5.inOrder Traversal, 6.postOrder Traversal\n");
        printf("7.Height of tree\n");
        printf("8.Find Minimum and Maximum\n");
        printf("9.Count leaves or External Node, 10.Count the total number of Nodes\n");
        printf("11. Mirror Image\n");
        printf("12.Exit\n");
        printf("Enter your option : \n");
        scanf("%d", &option);

        switch (option)
        {

        case 1:
            printf("\nEnter the number to be inserted : ");
            scanf("%d", &n);
            root = insert(root, n); // We can verify insertion by search option or any of the preOrder, postOrder, inOrder traversal options.
            break;

        case 2:
            printf("\nEnter the number to be deleted : ");
            scanf("%d", &n);
            root = del(root, n); // We can verify deletion by search or any of the preOrder, postOrder, inOrder traversal options.
            break;

        case 3:
            printf("\nEnter the number to be searched : ");
            scanf("%d", &n);
            ptr = search(root, n);
            if (ptr != NULL)
                printf("\n Number found\n");

            break;
        case 4:
            printf("\nPrinting preOrder\n");
            preOrder(root);
            break;

        case 5:
            printf("\nPrinting inOrder\n");
            inOrder(root);
            break;

        case 6:
            printf("\nPrinting postOrder\n");
            postOrder(root);
            break;

        case 7:
            printf("\nHeight of tree is %d\n", height(root));
            break;

        case 8:
            ptr = Minimum(root);
            if (ptr != NULL)
                printf("\nMinimum number is %d\n", ptr->data);
            ptr = Maximum(root);
            if (ptr != NULL)
                printf("\nMaximum number is %d\n", ptr->data);
            break;

        case 9:
            printf("Total Leaves of the tree is %d\n", countLeaf(root));
            break;

        case 10:
            printf("Total Number of Nodes in BST  = %d\n", totalNodes(root));
            break;

        case 11:
            // 50, 45, 35,40,25,70,60,75,80
            printf("\npreOrder before mirror image\n");
            preOrder(root);
            mirrorimage(root);
            printf("\npreOrder after mirror image\n");
            preOrder(root);
            break;
        case 12:
            exit(1);
        default:
            printf("\nSelect correct option\n");
        }
    }

    return 0;
}
