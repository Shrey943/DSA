#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *nextNode;
};

void createNode(struct Node *node, int data, struct Node *nextNode);
void transverseLL(struct Node *head);
struct Node *insertAtFirst(struct Node *head, int data);
struct Node *insertNode(struct Node *head, int index, int data);
struct Node *append(struct Node *head, int data);
struct Node *insertAfterNode(struct Node *head, struct Node *node, int data);
struct Node *deleteNode(struct Node *head, int index);
struct Node *deleteByVal(struct Node *head, int value);

int main()
{
    //Creating containers for our structure(We could have directly created out struct but it would create them in stack memory)
    struct Node *head, *element2, *element3, *element4, *element5, *element6, *element7, *element8, *element9, *element10;

    //Requesting memory from heap
    head = (struct Node *)malloc(sizeof(struct Node));
    element2 = (struct Node *)malloc(sizeof(struct Node));
    element3 = (struct Node *)malloc(sizeof(struct Node));
    element4 = (struct Node *)malloc(sizeof(struct Node));
    element5 = (struct Node *)malloc(sizeof(struct Node));
    element6 = (struct Node *)malloc(sizeof(struct Node));
    element7 = (struct Node *)malloc(sizeof(struct Node));
    element8 = (struct Node *)malloc(sizeof(struct Node));
    element9 = (struct Node *)malloc(sizeof(struct Node));
    element10 = (struct Node *)malloc(sizeof(struct Node));

    createNode(head, 123, element2);
    createNode(element2, 234, element3);
    createNode(element3, 345, element4);
    createNode(element4, 465, element5);
    createNode(element5, 567, element6);
    createNode(element6, 687, element7);
    createNode(element7, 789, element8);
    createNode(element8, 890, element9);
    createNode(element9, 990, element10);
    createNode(element10, 1000, NULL);

    transverseLL(head);

    printf("\nInsert at first : \n");
    head = insertAtFirst(head, 001);
    transverseLL(head);

    printf("\nInsert at first using index test: \n");
    head = insertNode(head, 0, 002);
    transverseLL(head);

    printf("\nInsert at index 6: \n");
    head = insertNode(head, 6, 777);
    transverseLL(head);

    printf("\nAppend i.e. insert at last: \n");
    head = append(head, 9999);
    transverseLL(head);

    printf("\nInsert after node: \n");
    head = insertAfterNode(head, element4, 555);
    transverseLL(head);

    printf("\nDelete first element using index: \n");
    head = deleteNode(head, 0);
    transverseLL(head);

    printf("\nDelete element at index 6: \n");
    head = deleteNode(head, 6);
    transverseLL(head);

    printf("\nDelete first element using value: \n");
    head = deleteByVal(head, 001);
    transverseLL(head);

    printf("\nDelete element having value 9999: \n");
    head = deleteByVal(head, 9999);
    transverseLL(head);

    printf("\nDelete element not present in list: \n");
    head = deleteByVal(head, 4342543);
    transverseLL(head);
    //Insert at first

    // head = insertAtFirst(head, 999);
    // transverseLL(head);

    //Inserting at any position will
    // printf("Head: %d\n", *head);
    // head = insertNode(0, 100001, head);
    // // printf("Head: %d\n", *head);
    // transverseLL(head);
    // head = deleteByVal(head, 100001);
    // transverseLL(head);

    // deleteNode(0, head);
    // transverseLL(head);
    // append(100990, head);
    // transverseLL(head);

    // insertAfterNode(element2, 555);
    // transverseLL(head);

    return 0;
}

void createNode(struct Node *currentNode, int data, struct Node *nextNode)
{
    currentNode->data = data;
    currentNode->nextNode = nextNode;
}

void transverseLL(struct Node *head)
{
    printf("Linked List:\t");
    while (head != NULL)
    {
        printf("%d, ", head->data);
        head = head->nextNode;
    }
    printf("\n");
}

struct Node *insertAtFirst(struct Node *head, int data)
{
    struct Node *new = (struct Node *)malloc(sizeof(struct Node));
    new->data = data;
    new->nextNode = head;

    return new;
}

struct Node *insertNode(struct Node *head, int index, int data)
{

    struct Node *new = (struct Node *)malloc(sizeof(struct Node)), *temp = head;
    new->data = data;

    if (index == 0)
    {
        new->nextNode = head;
        return new;
    }

    int i = 0;
    while (i < index - 1) //Index-1 is used as we want the node after which we want to insert(i.e node at index-1)
    {                     //As we can get the pointer of next node from node at index-1 itself.
        temp = temp->nextNode;
        i++;
    }

    new->nextNode = temp->nextNode;
    temp->nextNode = new;
    return head;
}

struct Node *append(struct Node *head, int data)
{
    struct Node *new = (struct Node *)malloc(sizeof(struct Node)), *temp = head;

    while (temp->nextNode != NULL)
    {
        temp = temp->nextNode;
    }

    new->data = data;
    new->nextNode = NULL;
    temp->nextNode = new;

    return head;
}

struct Node *insertAfterNode(struct Node *head, struct Node *node, int data)
{
    struct Node *new = (struct Node *)malloc(sizeof(struct Node));
    new->data = data;
    new->nextNode = node->nextNode;
    node->nextNode = new;

    return head;
}

struct Node *deleteNode(struct Node *head, int index)
{
    struct Node *p = head, *q = head->nextNode;

    if (index == 0)
    {
        free(p);
        return q;
    }

    for (int i = 0; i < index - 1; i++)
    {
        p = q;
        q = q->nextNode;
    }
    p->nextNode = q->nextNode;
    free(q);

    // temp = node->nextNode;
    // temp = temp->nextNode;
    // free(node->nextNode);
    // node->nextNode = temp;

    // free(node->nextNode);
    // printf("Freed memory\n");
    return head;
}

struct Node *deleteByVal(struct Node *head, int value)
{
    struct Node *p = head, *q = head->nextNode;
    if (head != NULL && head->data == value)
    {
        free(p);
        return q;
    }
    while (q != NULL && q->data != value)
    {
        p = q;
        q = q->nextNode;
    }
    if (q == NULL)
    {
        return head;
    }

    p->nextNode = q->nextNode;
    free(q);

    return head;
}