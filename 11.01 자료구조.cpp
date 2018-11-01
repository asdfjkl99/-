#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
}Node;

typedef struct list {
    Node *head;
    Node *crnt;
}List;

void Initialize(List* list)
{
    list->head = nullptr;
    list->crnt = nullptr;

    printf("Initializing is succeed ! \n");
}

Node* CreateNode(int x)
{
    Node* newNode = (Node*)calloc(1, sizeof(Node));

    if (newNode == nullptr)
        printf("Memory allocation failed ! \n");

    else {
        newNode->data = x;
        newNode->next = nullptr;
    }

    if (newNode == nullptr)
        printf ("Node creation is falied ! \n");

    else
        printf("Node is created. Data : %d \n", newNode->data);

    return newNode;
}

void InsertFront(List *list, int x)
{
    Node* newNode = CreateNode(x);

    if(!newNode)
        return;

    newNode->next = list->head;
    list->head = newNode;
    list->crnt = newNode;
}

void InsertRear(List* list, int x)
{
    Node* newNode = CreateNode(x);
    Node* LastNode = list->head;
    
    if (newNode == nullptr)
        return;

    if (list->head == nullptr)
    {
        list->head = newNode;
        list->crnt = newNode;
        return;
    }

    while(LastNode->next != nullptr)
    {
        LastNode = LastNode->next;
    }

    LastNode->next = newNode;
    list->crnt = newNode;
}

void PrintList(List *list)
{
    Node* temp = list->head;

    if(list->head == nullptr)
    {
        printf("List is empty ! \n");
        return;
    }

    while(temp != nullptr)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf(" \n");
}

void main()
{
    List mylist;
    List yourlist;

    Initialize(&mylist);
    InsertFront(&mylist, 5);
    InsertFront(&mylist, 4);
    InsertFront(&mylist, 3);
    InsertRear(&mylist, 2);
    PrintList(&mylist);

    Initialize(&yourlist);
    InsertRear(&yourlist, 5);
    InsertRear(&yourlist, 5);
    InsertFront(&yourlist, 3);
    InsertRear(&yourlist, 5);
    InsertRear(&yourlist, 5);
    PrintList(&yourlist);
}