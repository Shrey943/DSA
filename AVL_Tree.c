#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct Node
{
    int data;
    struct Node *right;
    struct Node *left;
    int height; // Will be needed for BF (Balancing factor re baba)

} node;

node *createNode(int data)
{
    node *new = (node *)malloc(sizeof(node));
    new->data = data;
    new->right = NULL;
    new->left = NULL;
    // AS: The height of a node is the number of edges present in the longest path connecting that node to a leaf node. Ab khus

    new->height = 1; // LOOK, VESE HEIGHT OF A LEAF IS 0 but apan NULL ki height 0 return kr raye h toh isiliye apan ko 1 se start karna pad ra h height
    return new;
}

int getHeight(node *node)
{ // Ye function isiliye likhna pada taaki har jagah null check na krna pade
    if (node == NULL)
        return 0;

    return node->height;
}
int max(int a, int b)
{
    // if (a > b)
    //     return a;

    // return b;

    // Same cheez ko uper h, using Ternary operator(?:)
    return (a > b) ? a : b; // Iska mtlb h, if a > b return a else return b
}

int balancingFactor(node *node)
{
    if (node == NULL)
        return 0; // BF of null will be 0

    // abs: abstract function, used to convert negative to positive values.

    return (getHeight(node->right) - getHeight(node->left)); // Agar get height na likhe hote toh check karna padta ki kahi right ya left null toh nai h
}

node *leftRotate(node *root)
{
    node *working = root->right;
    node *temp = working->left;

    working->left = root;

    root->right = temp;

    // Since apan ne working and root ko change kia h, hence unki heights bhi change hongi
    root->height = 1 + max(getHeight(root->left), getHeight(root->right)); // Root working ke neeche h isiliye pehle iski height update hogi
    working->height = 1 + max(getHeight(working->left), getHeight(working->right));

    // HEIGHT FORMULA: kisi bhi node ki height badhani ho toh check karo ki uske left subtree ki height aur right sub tree ki height mai se bada
    //                 kon h, jiski bhi height badi hogi, usse ek zyada height iski hogi, simple.

    return working;
}

node *rightRotate(node *root)
{
    node *working = root->left;
    node *temp = working->right;

    working->right = root;
    root->left = temp;

    root->height = 1 + max(getHeight(root->left), getHeight(root->right)); // Root working ke neeche h isiliye pehle iski height update hogi
    working->height = 1 + max(getHeight(working->left), getHeight(working->right));

    return working;
}

node *insert(node *root, int data)
{

    // static int prev = 0; // let 0 represent left and 1 represent right, Well this may look tough on seeing hence here a even simple way
    // Dekho, apan isko abhi bs isiliye use kr raye the taaki next node mai humaari value kaha mudi ye pata laga paaye, toh paaji ye toh apan
    // Uski value bhi pata laga skte h na, agar next node ki value, given key(jo insert karni thi) usse badi h toh left side nai toh right side
    if (root == NULL)
        return createNode(data);

    if (data == root->data)
    {
        printf("Can't insert %d!! Element already present.", data);
    }
    else if (data < root->data)
    {
        root->left = insert(root->left, data);

        root->height = 1 + max(getHeight(root->left), getHeight(root->right));

        if (balancingFactor(root) > 1 || balancingFactor(root) < -1)
        {
            // Ye method best h, bs ek variable space jyada leti h, isliye ek aur method likh ra mai neeche
            // if (prev == 0) // LL condition - Right rotate once wrt first imbalanced node(which is this node)
            // {
            //     root = rightRotate(root);
            // }
            // if (prev == 1) // LR condition - Left rotate once wrt to next node of first imbalanced node that is in path of new node
            // {              //                then rotate right once wrt first imbalanced node

            //     root->left = leftRotate(root->left);
            //     root = rightRotate(root);
            // }

            // Dekho itna toh pata hi h ki yaha se toh left gaya h, ab agar left ke data se chota hua toh fir left nai toh right jayega
            if (data < root->left->data)
            { // LL condition - Right rotate once wrt first imbalanced node(which is this node)
                root = rightRotate(root);
            }
            else
            { // LR condition - Left rotate once wrt to next node of first imbalanced node that is in path of new node
              //                then rotate right once wrt first imbalanced node
                root->left = leftRotate(root->left);
                root = rightRotate(root);
            }
        }

        // prev = 0;
    }
    else
    {
        root->right = insert(root->right, data);

        root->height = 1 + max(getHeight(root->left), getHeight(root->right));

        if (balancingFactor(root) > 1 || balancingFactor(root) < -1)
        {
            // // Badhiya method thaa
            // if (prev == 1) // RR condition - Left rotate once wrt first imbalanced node(which is this node)
            // {

            //     root = leftRotate(root);
            // }
            // if (prev == 0) // RL condition - Right rotate once wrt to next node of first imbalanced node that is in path of new node
            // {              //                then rotate Left once wrt first imbalanced node

            //     root->right = rightRotate(root->right); // jo node return aayega usko set bhi toh krna padega na
            //     root = leftRotate(root);
            // }

            // Keep in mind, greater sign
            if (data > root->right->data) // RR condition - Left rotate once wrt first imbalanced node(which is this node)
            {
                root = leftRotate(root);
            }
            else // RL condition - Right rotate once wrt to next node of first imbalanced node that is in path of new node
            {    //                then rotate Left once wrt first imbalanced node

                root->right = rightRotate(root->right);
                root = leftRotate(root);
            }
        }

        // prev = 1;
    }

    return root;
}

void PreorderTransversal(struct Node *root) // Root - Left sub tree - Right sub tree
{

    if (root != NULL)
    {
        printf("%d, ", root->data);
        PreorderTransversal(root->left);
        PreorderTransversal(root->right);
    }
}

void PostorderTransversal(struct Node *node) // Left sub tree - Right sub tree - node
{

    if (node != NULL)
    {
        PostorderTransversal(node->left);
        PostorderTransversal(node->right); // NOTICE: Bs printf ko uper neeche krna h
        printf("%d, ", node->data);
    }
}

void inorderTransversal(struct Node *node) // Left - Root - Right
{

    if (node != NULL)
    {
        inorderTransversal(node->left);
        printf("%d, ", node->data); // NOTICE: Bs printf ko uper neeche krna h
        inorderTransversal(node->right);
    }
}

int main()
{
    node *root = insert(NULL, 10);
    insert(root, 6);
    insert(root, 13);
    insert(root, 2);
    insert(root, 8);
    insert(root, 19);

    /*
  |           10
  |          /  \
  |         6    13
  |        / \    \
  |       2   8    19
  |
  |

  */

    inorderTransversal(root);
    printf("\n");
    PreorderTransversal(root);
    printf("\n");

    /*
    |                       RR TESTING - In simple case, 20 will create imbalance, in complex case 21 will create imbalance
    */
    // insert(root, 20); -- Simple RR testing

    // insert(root, 12); -- Complex RR testing - This gives an tree like
    // insert(root, 15);             10
    // insert(root, 20);           /   \                                  
    // insert(root, 21);          6     13    -- 13 ki BF 2 ho gayi, Aur 13 se 21 jaane ke raste mai pehle 2 right nodes h isiliye RR case h
    //                           / \    / \      19, 13 ki jagah chala jayega, 13 ka left 15 aur 19 ka left 13, Bs
    //                          2   8  12  19    // Since 13 and 20 dono ki height 2 h(abhi nai h pr ho jayegi) isliye 19 ki height 3 ho jayegi
    //                                     / \
   //                                     15  20
    //                                          \
   //                                           21

    /*
    |                   LL TESTING - inserting 0 will create unbalance
    |
    |                  10                                     10
    |                 /  \                                   /  \
    |                6    13                   ->           2    13
    |               / \    \                               / \    \
    |              2   8    19                            1   6    19
    |             / \                                    /   / \
    |            1   3                                  0   3   8
    |           /
    |          0
    */

    // insert(root, 1);
    // insert(root, 3);
    // insert(root, 0); // This is the imposter

    /*
    |                                    LR TESTING -- 3 will be the imposter
    |
    |             10                                     10                                       10
    |            /  \           1st left rotation       /  \             2nd Right rotation      /  \
    |           6    13               ->               6    13                 ->               4    13
    |          / \    \              wrt 2            / \    \                wrt 6            / \    \
    |         2   8    19                            4   8    19                              2   6    19
    |        / \                                    /                                        / \   \
    |       1   4                                  2                                        1   3   8
    |          /                                  / \
    |         3                                  1   3
    |         ^
    |         |-- This 3 will imbalance this AVL tree. 6 will be the first imbalanced node while 2 will be the next to path of first imbalanced tree and new node 3
    |                                                   ** WELL KEEP AN EYE ON 3 KI POSITION, MST H **
    */

    // insert(root, 1);
    // insert(root, 4);
    // insert(root, 3);

    /*
    |                                                RL TESTING -- 17 will be the imposter
    |
    |             10                                               10                                            10
    |            /  \               1st Right rotation            /  \                2nd Left rotation         /  \
    |           6    13                   ->                     6    13                      ->               6    15
    |          /\    / \                 wrt 19                 /\    / \                   wrt 13            /\    / \
    |         2  8  12  19                                     2  8  12  15                                  2  8  13  19
    |                   / \                                                \                                       /   / \
    |                  15  20                                               19                                    12  17  20
    |                   \                                                   / \
    |                    17                                                17  20
    |         ___________|
    |         |-- This 17 will imbalance this AVL tree. 13 will be the first imbalanced node while 19 will be the next to path of first imbalanced tree and new node 3
    |                                                   ** WELL KEEP AN EYE ON 17 KI POSITION, MST H **
    |
    |         ***** 17 ki jagah agar koi or number 15 ke left mai hota toh bhi ye RL hi kehlata kyo ki first imbalanced node(13) se 15 ke next tk
    |               aane ke liye pehle Right fir left turn hi lena padta, uske baad fark nai padta ki kaha ghus ra h element. *****
    */

    insert(root, 12);
    insert(root, 15);
    insert(root, 20);
    insert(root, 17); // -- Ye waala insert ghoomayega poore tree ko

    printf("\nIn-order: ");
    inorderTransversal(root); // for testing ki abhi bhi BST h na
    printf("\n");

    printf("\nPre-order: ");
    PreorderTransversal(root); // for testing ki rotation hu ki nai
    printf("\n");

    return 0;
}