#include <stdio.h>
#include <stdlib.h>

typedef struct tree
{
    int data;
    struct tree *left;
    struct tree *right;
} Tree;

// Create a new Node
Tree *createNode(int value)
{
    Tree *newNode = malloc(sizeof(Tree));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Insert on the leftt of the node
Tree *insertLeft(Tree *root, int value)
{
    root->left = createNode(value);
    return root->left;
}
// Insert on the right of the node
Tree *insertRight(Tree *root, int value)
{
    root->right = createNode(value);
    return root->right;
}

// // Traversal

// Preorder Traversal
void preorderTraversal(Tree *root)
{
    if (root == NULL)
        return;
    printf("%d ->", root->data);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

// Postorder Traversal
void postorderTraversal(Tree *root)
{
    if (root == NULL)
        return;
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%d ->", root->data);
}

// Inorder Traversal
void inorderTraversal(Tree *root)
{
    if (root == NULL)
        return;
    inorderTraversal(root->left);
    printf("%d ->", root->data);
    inorderTraversal(root->right);
}

int main()
{
    Tree *root = createNode(1);
    insertLeft(root, 2);
    insertRight(root, 3);
    insertLeft(root->left, 4);

    printf("Inorder traversal \n");
    inorderTraversal(root);

    printf("\nPreorder traversal \n");
    preorderTraversal(root);

    printf("\nPostorder traversal \n");
    postorderTraversal(root);
    printf("\n");
}