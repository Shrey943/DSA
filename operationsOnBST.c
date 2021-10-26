#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct Node
{
    int data;
    struct Node *right;
    struct Node *left;
} node;

node *createNode(int data);
int checkBST(node *node, int min, int max);
void inorderTransversal(struct Node *node);
int isBST(node *root) { checkBST(root, INT_MIN, INT_MAX); }
int search(node *root, int data);
node *insert(node *node, int data);
node *delete (node *node, int data);

int main()
{
    node *root, *second, *third, *fourth, *fifth, *sixth, *seventh, *eightth, *nineth, *tenth, *eleventheth;

    // root = createNode(10);
    // second = createNode(6);
    // third = createNode(13);
    // fourth = createNode(2);
    // fifth = createNode(8);
    // sixth = createNode(19);
    // seventh = createNode(9);
    // eightth = createNode(14);
    // nineth = createNode(12);

    root = createNode(10);
    second = createNode(6);
    third = createNode(13);
    fourth = createNode(4);
    fifth = createNode(8);
    sixth = createNode(19);
    seventh = createNode(2);
    eightth = createNode(5);
    nineth = createNode(9);
    tenth = createNode(1);
    eleventheth = createNode(20);

    /*
    |           10
    |          /  \
    |         6    13
    |        / \    \
    |       2   8    19
    |            \
    |             9

    |           10
    |          /  \
    |         6    13
    |        / \    \
    |       4   8    19
    |      / \   \
    |     2   5   9
    |    /
    |   1
    |           10
    |          /  \
    |         6    13
    |        / \    \
    |       4   8    19
    |      / \   \
    |     1   5   9
    |      \
    |       2
    */

    root->left = second;
    root->right = third; // third waala
    second->left = fourth;
    second->right = fifth;
    third->right = sixth;
    fourth->left = tenth;
    fourth->right = eightth;
    fifth->right = nineth;
    tenth->right = seventh;
    sixth->right = eleventheth;

    printf("Original is BST: %d\n", isBST(root));

    inorderTransversal(root);
    printf("\n");

    insert(root, 3);

    insert(root, 12);

    inorderTransversal(root);
    printf("\n");

    insert(root, 6);

    inorderTransversal(root);
    printf("\n");

    printf("New is BST: %d\n", isBST(root));

    delete (root, 6);
    inorderTransversal(root);
    printf("\n");

    delete (root, 1);
    inorderTransversal(root);
    printf("\n");

    delete (root, 10);
    inorderTransversal(root);
    printf("\n");

    return 0;
}

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

node *insert(node *root, int data)
{
    // Neeche likha code new node ko beech mai insert krta h

    /*                    Insert 4 in belows tree                     how it should be       How I was doing it(below code)
    |                                10                                    10                          10
    |                               /  \                                  /  \                        /  \
    |                              6    13                               6    13                     6    13
    |                             / \    \            ->                / \    \                    / \    \
    |                            2   8    19                           2   8    19                 4   8    19
    |                                 \                                 \   \                     /     \
    |                                  9                                 4   9                   2       9

    *** WEll maine bahut try kia ki koi toh aisi condition hogi jb apan ko beech mai insert karna hoga, PR NAI. UPer side diye gaye har tree ko
        kisi na kisi leaf ko extend kr ke kiya ja skta h. Chalo neeche diye gaye ek aur mai dekh lo.

    |
    |                                                                                  Correct Way(as of all the algo's I found on internet)
    |           10                                              10                                      10
    |          /  \                    insert 3                /  \                                    /  \
    |         6    13                                         6    13                                 6    13
    |        / \    \                                        / \    \                                / \    \
    |       4   8    19                   ->                4   8    19                             4   8    19
    |      / \   \                                         / \   \                                 / \   \
    |     1   5   9                                       3   5   9                               1   5   9
    |      \                                             /                                        \
    |       2                                           1                                          2
    |                                                    \                                          \
    |                                                     2                                          3
    |
    ** Well mera algo bhi bilkul sahi h as it also gives the Binary search tree as an output. But... WEll as you can see ye poore tree ko
       disturb kr ra h, issiliye let's just go with the second one.**


    // if (root == NULL)
    //     return;

    // if (root->data == data)
    // {
    //     printf("Can't insert %d! Value already present.\n", data);
    //     return;
    // }
    // if (data < root->data)
    // { // value to be inserted is less than node value
    //     if (root->left == NULL || root->left->data < data)
    //     {
    //         node *new = createNode(data);
    //         new->left = root->left;
    //         root->left = new;
    //         return;
    //     }
    //     return insert(root->left, data);
    // }

    // // Condition likhne ki zarurat nai kyoki pehle hi return ho jayega agar uper ki true hui toh
    // if (root->right == NULL || root->right->data > data)
    // {
    //     node *new = createNode(data);
    //     new->right = root->right;
    //     root->right = new;
    //     return;
    // }
    // return insert(root->right, data);
   ---------------------------------------------------------------------------------------------------------
    */

    // This algo just waits till the null, checking that same value is not already present in tree.We can do it through recursion and iteration
    // both, so Lets go with the iteration this time.

    // ** IT INSERTS IN EMPTY TREE TOO **

    // node *prev = NULL;
    node *new = createNode(data); // It will return node with left and right as null

    while (root != NULL)
    {
        // prev = root;
        if (root->data == data)
        {
            printf("Can't insert %d ! Element already present.\n", data);
            return NULL;
        }
        if (data < root->data)
        {
            if (root->left == NULL) // Is if part ko apan loop ke bahar bhi likh skte the, bs usse 2 baar same if conditionlagti aur ek prev node ko store karene variable bhi lagta.
            {
                root->left = new;
                break;
            }
            root = root->left;
        }
        else
        {
            if (root->right == NULL)
            {
                root->right = new;
                break;
            }
            root = root->right;
        }
    }

    // if (prev->data < data){    // This would be required if we don't give conditions on while loop
    //     prev->left = new;
    // }
    // else{
    //     prev->right = new;
    // }

    return new;
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
    /* Dekho, deletion mai apne paas 3 cases hote h,
    |                      10
    |                     /  \
    |                    6    13         *** inorder predecessor: Right most child of left sub tree.
    |                   / \    \             inorder successor: Left most child of right sub tree. ***
    |                  4   8    19
    |                 / \   \
    |                1   5   9
    |                 \
    |                  2

    1. jisko delete karna h vo leaf node h, Simple se uda do usko aur null return kar do.(2,5,9,19)

    2. jisko delete karna h vo 1 bacche ka baap h(us bacche ke kitne bhi bacche ho skte h): Toh simple isko bhi uda do aur iske previous waale
       node ke pointer ko iske next pointer ki taraf point kar ko(deletion in linked list ki tarah)

       ex:
       agar 13 delete karna h, toh simply 13 ko free kar do aur 10 ke right ko 13 ke right se replace kar do, 10 seedha 19 ko point kare.
       (agar 19 ki jagah 12 hota aur left mai hota, toh 10 le right ko 19 ke left ke saath replace kr dete, dekh le bhai BST hi rahega )
       (agar 19 ke neech poora khandaan bhi hota toh bhi issi se kaam chal jata, 10 sooch lete hi uska 19 naam ka koi beta nahi, aur 19 ke bete
       ko apna beta maan lete, 19 ke bete ke bete toh vese hi rahenge)

    3. Jisko delete karna h vo 2 baccho ka baap h(uski bahut badi family bhi ho skti h, ya root node bhi ho skta h) Bs toh simply us node ka
       inorder predecessor ya inorder successor nikalo, AUR US NODE KI VALUE MAI DAAL DO(node delete nai kia h) Chinta nakko karo, BST hi rahega.
       pr ab jis value ko utha ke daala h uske liye delete node chala do...ye loop tb tk chalega jb tk koi leaf node na aa jaye ya 1 child na aa jaye.
       ex:

       maan lo 6 ko delete karna, toh sbse pehle uska inorder predecessor nikalenge(successor bhi nikaal skte the) jo ki hoga 5, ab 6 node ki
       data value ki jagah 5 rakh denge. Ab 5 ko delete karna h, toh dekho predecessor nikaale h toh itna toh fix h ki left tree mai h, bs toh
       fir ek baar 5(jo pehle 6 tha) ke left ko root maan ke delete function chala do (ab search value 5 rahegi)
    */

    // Pehle toh search karna padega toh recursive ya iterative koi bhi choose kr lo

    if (root == NULL)
    {
        return root; // Which is null only.
    }

    else if (data < root->data)
    {
        root->left = delete (root->left, data); // left ko set isiliye kr raye h taaki previous node store na karna pade.
    }                                           // last mai jo return h, vo left ko left mai hi rehne dega(vo nodes jinko change nai karna h)
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
            return temp; // iske pehle waale left ko iske baad waale left ke equal kr dega.
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
            root->data = pre->data;                      // Ye badla apan ne data ki value aur ab left side se pre ke data ko delete kr do
            root->left = delete (root->left, pre->data); // aise.
        }
    }
    return root; // ye return last 3 conditions ke liye h, agar root ko free karte h, toh pehle hi return kr denge.
} //(third case mai apan ne data badla h, left right same h toh ussi root ko return karna h)
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