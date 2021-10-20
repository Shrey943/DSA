#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct Node
{
    int data;
    struct Node *right;
    struct Node *left;
} node;

node *createNode(int data)
{
    node *new = (node *)malloc(sizeof(node));
    new->data = data;
    new->right = NULL;
    new->left = NULL;

    return new;
}

int checkBST(node *node, int min, int max) // Main Working Function
{
    if (node == NULL) // so that at end it returns true
        return 1;

    int data = node->data;

    if (data < min || data > max)
        return 0;

    return checkBST(node->left, min, data - 1) && checkBST(node->right, data + 1, max); // && is used so that both conditions satisfies
}

int isBST(node *root)
{
    checkBST(root, INT_MIN, INT_MAX);
}

void inorderTransversal(struct Node *node) // Left - Root - Right
{
    if (node != NULL)
    {
        inorderTransversal(node->left);
        printf("%d, ", node->data);
        inorderTransversal(node->right);
    }
}

int search(node *root, int data)
{
    if (root == NULL)
        return 0;

    if (root->data == data)
        return 1;

    if (data > root->data)
        return search(root->right, data);

    return search(root->left, data);
}

int search2(node *root, int data)
{
    while (root != NULL){
        if(root->data == data) return 1;

        if (data > root->data) root = root->right;
        else root = root->left;
    }
    return 0;
}

int main()
{
    node *root, *second, *third, *fourth, *fifth, *sixth, *seventh, *eightth, *nineth;

    root = createNode(10);
    second = createNode(6);
    third = createNode(13);
    fourth = createNode(2);
    fifth = createNode(8);
    sixth = createNode(19);
    seventh = createNode(9);

    /*
|
|           10
|          /  \      // In checkBST function, min and max is setted accordingly so that on whole left sub tree of 10, all values are less than 10
|         6    13
|        / \    \
|       2   8    19
|        \
|         9            //NOT A BST AS 6 KE LEFT SUB TREEE MAI DEKHO 9 BADA AA GAYA
|
  |
  |           10
  |          /  \
  |         6    13
  |        / \    \
  |       2   8    19
  |            \
  |             9
  |
  */

    // root->left = second;    // NOT A BST (First one)
    // root->right = third;
    // second->left = fourth;
    // second->right = fifth;
    // third->right = sixth;
    // fourth->right = seventh;

    root->left = second; // BST (second one)
    root->right = third;
    second->left = fourth;
    second->right = fifth;
    third->right = sixth;
    fifth->right = seventh;

    inorderTransversal(root);
    printf("\n");

    // printf("IS BST : %d\n", isBST(root));
    if (isBST(root))
    {
        printf("\nThis is a BST\n");
    }
    else
    {
        printf("\nThis is not a BST\n");
    }

    if (search(root, 11))
    {
        printf("\nFound 11\n");
    }
    else
    {
        printf("\nNot found 11\n");
    }

    if (search(root, 9))
    {
        printf("\nFound 9\n");
    }
    else
    {
        printf("\nNot found 9\n");
    }

    if (search(root, 76))
    {
        printf("\nFound 76\n");
    }
    else
    {
        printf("\nNot found 76\n");
    }
    if (search(root, 19))
    {
        printf("\nFound 19\n");
    }
    else
    {
        printf("\nNot found 19\n");
    }

    printf("\nNOW USING ITERATIVE SEARCH...\n");
    if (search(root, 11))
    {
        printf("\nFound 11\n");
    }
    else
    {
        printf("\nNot found 11\n");
    }

    if (search(root, 9))
    {
        printf("\nFound 9\n");
    }
    else
    {
        printf("\nNot found 9\n");
    }

    if (search(root, 76))
    {
        printf("\nFound 76\n");
    }
    else
    {
        printf("\nNot found 76\n");
    }
    if (search(root, 19))
    {
        printf("\nFound 19\n");
    }
    else
    {
        printf("\nNot found 19\n");
    }

    return 0;
}