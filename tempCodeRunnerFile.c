#include<stdio.h>
#include<malloc.h>
 
typedef struct node{
    int data;
    struct node* left;
    struct node* right;
}node;
 
struct node* createNode(int data){
    struct node *n; // creating a node pointer
    n = (struct node *) malloc(sizeof(struct node)); // Allocating memory in the heap
    n->data = data; // Setting the data
    n->left = NULL; // Setting the left and right children to NULL
    n->right = NULL; // Setting the left and right children to NULL
    return n; // Finally returning the created node
}
 
node *inOrderPredecessor(node *node) // The right most node of left sub tree is the inorder predecessor
{
    node = node->left;
    while (node != NULL && node->right != NULL)
    {
        node = node->right;
    }
    return node;
}

node *delete (node *root, int data)
{
    // Pehle toh search karna padega toh recursive ya iterative koi bhi choose kr lo

    if (root == NULL)
    {
        return root; // Which is null only.
    }

    else if (data < root->data)
    {
        root->left = delete (root->left, data);
    }
    else if (data > root->data)
    {
        root->right = delete (root->right, data);
    }
    else
    {
        if (root->left == NULL) // This will cover both the cases, leaf node and 1 child node
        {                       // Left null h mtlb right mai h
            node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            node *temp = root->left;
            free(root);
            return temp;
        }
        else
        {
            node *pre = inOrderPredecessor(root);
            root->data = pre->data;
            root->left = delete (root->left, pre->data);
        }
    }
    return root;
}
void preOrder(struct  node* root){
    if(root!=NULL){
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}
 
void postOrder(struct  node* root){
    if(root!=NULL){
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->data);
    }
}
 
void inOrder(struct  node* root){
    if(root!=NULL){
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}
 
int isBST(struct  node* root){
    static struct node *prev = NULL;
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
 
struct node * searchIter(struct node* root, int key){
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
 
void insert(struct node *root, int key){
    struct node *prev = NULL;
    while(root!=NULL){
        prev = root;
        if(key==root->data){
            printf("Cannot insert %d, already in BST", key);
            return;
        }
        else if(key<root->data){
            root = root->left;
        }
        else{
            root = root->right;
        }
    }
    struct node* new = createNode(key);
    if(key<prev->data){
        prev->left = new;
    }
    else{
        prev->right = new;
    }
}

// struct node *inOrderPredecessor(struct node* root){
//     root = root->left;
//     while (root->right!=NULL)
//     {
//         root = root->right;
//     }
//     return root;
// }

// struct node *deleteNode(struct node *root, int value){

//     struct node* iPre;
//     if (root == NULL){
//         return NULL;
//     }
//     if (root->left==NULL&&root->right==NULL){
//         free(root);
//         return NULL;
//     }

//     //searching for the node to be deleted
//     if (value < root->data){
//         root-> left = deleteNode(root->left,value);
//     }
//     else if (value > root->data){
//         root-> right = deleteNode(root->right,value);
//     }
//     //deletion strategy when the node is found
//     else{
//         iPre = inOrderPredecessor(root);
//         root->data = iPre->data;
//         root->left = deleteNode(root->left, iPre->data);
//     }
//     return root;
// }
 
int main(){
     
    // Constructing the root node - Using Function (Recommended)
    struct node *p = createNode(5);
    struct node *p1 = createNode(3);
    struct node *p2 = createNode(6);
    struct node *p3 = createNode(1);
    struct node *p4 = createNode(4);
    // Finally The tree looks like this:
    //      5
    //     / \
    //    3   6
    //   / \
    //  1   4  
 
    // Linking the root node with left and right children
    p->left = p1;
    p->right = p2;
    // p1->left = p3;
    p1->right = p4;

    inOrder(p);
    printf("\n");
    delete(p, 3);
    inOrder(p);

    return 0;
}
