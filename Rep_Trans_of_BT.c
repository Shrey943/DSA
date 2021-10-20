#include <stdio.h>
#include <stdlib.h>

struct Node
{

    struct Node *left; // Remember, we can not initiate them with null here as a memory isn't allocated to them they are just datatype
    int data;
    struct Node *right;
};

struct Node *createNode(int data)
{ // We did not took left and right as parameter as they aren't created till now

    struct Node *p = (struct Node *)malloc(sizeof(struct Node));
    p->data = data;
    p->left = NULL;
    p->right = NULL;

    return p;
}

void PreorderTransversal(struct Node *root) // Root - Left sub tree - Right sub tree
{

    // printf("%d, ", root->data); // Sbse pehle root ko print kiye fir ghusna chaalu kiye, tb tk ghus ke print krte rahe jb tk left right dono null na ho

    // if (root->left != NULL)
    // {
    //     PreorderTransversal(root->left);
    // }
    // if (root->right != NULL)
    // {
    //     PreorderTransversal(root->right);
    // }

    // Same cheez chote mai:

    if (root != NULL)
    {
        printf("%d, ", root->data);
        PreorderTransversal(root->left);
        PreorderTransversal(root->right);
    }
}

void PostorderTransversal(struct Node *node) // Left sub tree - Right sub tree - node
{

    // if (node->left != NULL) // Left will always be before right
    // {                       // Dekho, isse ye tb tk ghusta rahega jb tk left null na ho jaye aur fir return hona chaalu hoga
    //     PostorderTransversal(node->left);
    // }

    // if (node->right != NULL)
    // { // Ab ho skta h left null ho, pr right bhi toh dekhna h na, left null hone ke baad hi yaha aayega aur tb tk ghusega jb tk right null na ho
    //     PostorderTransversal(node->right);
    // }

    // // Finally, Ab left right dono null h toh root hi toh data kehlaaaya, bs print karo aur return karo.
    // printf("%d, ", node->data);

    // Same cheez chote mai:

    if (node != NULL)
    {
        PostorderTransversal(node->left);
        PostorderTransversal(node->right); // NOTICE: Bs printf ko uper neeche krna h
        printf("%d, ", node->data);
    }
}

void inorderTransversal(struct Node *node) // Left - Root - Right
{
    // if(node->left != NULL){
    //     inorderTransversal(node->left);
    // }

    // printf("%d, ", node->data);                   // Bs is line ki position hi toh change krna h pre, post aur in ke according

    // if (node->right != NULL){
    //     inorderTransversal(node->right);
    // }

    // Same cheez chote mai:

    if (node != NULL)
    {
        inorderTransversal(node->left);
        printf("%d, ", node->data); // NOTICE: Bs printf ko uper neeche krna h
        inorderTransversal(node->right);
    }
}

int main()
{
    struct Node *root, *first, *second, *third, *fourth, *fifth, *sixth;

    root = createNode(1);
    first = createNode(2);
    second = createNode(3);
    third = createNode(4);
    fourth = createNode(5);
    fifth = createNode(6);
    sixth = createNode(7);

    // Till now they are just nodes

    root->left = first; // now it's a Binary Treee
    root->right = second;
    first->left = third;
    first->right = fourth;
    second->right = fifth;
    third->right = sixth;

    /*
    |
    |            1
    |          /  \
    |         2    3
    |        / \    \
    |       4   5    6
    |        \
    |         7
    |
    */

    printf("\nPre-order Transversal of Binary Tree: ");
    PreorderTransversal(root);

    printf("\n\nPost-order Transversal of Binary Tree: ");
    PostorderTransversal(root);

    printf("\n\nPost-order Transversal of Binary Tree: ");
    inorderTransversal(root);

    return 0;
}