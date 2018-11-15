#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    node* next;
}ListNode;

ListNode* create_node(int data, ListNode* next)
{
    ListNode* newNode = (ListNode*)calloc(1, sizeof(ListNode));
    
    newNode->data = data;
    newNode->next = next;

    return newNode;
}

void insert_first(ListNode** list, ListNode* node)
{
    if(*list == NULL)
    {
        *list = node;
        return;
    }

    node->next = (*list)->next;
    (*list)->next = node;
}

void insert_last(ListNode** list, ListNode* node)
{
    if(*list == NULL)
    {
        insert_first(list, node);
        return;
    }

    ListNode* temp = *list;

    while(temp->next != nullptr)
    {
        temp = temp->next;
    }

    temp->next = node;
    node->next = nullptr;
}

void display(ListNode* list)
{
    while(list != nullptr)
    {
        printf("%d -> ", list->data);
        list = list->next;
    }
}

int main()
{
    ListNode* list1 = NULL;
    //list1 = 20->10->30

    insert_first(&list1,create_node(10,NULL));
    insert_first(&list1,create_node(20,NULL));
    insert_last(&list1,create_node(30,NULL));

    display(list1);

    return 0;
}