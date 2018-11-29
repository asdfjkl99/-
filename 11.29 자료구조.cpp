#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct bstNode {
    char data;
    struct bstNode* left;
    struct bstNode* right;
}BSTNode;

BSTNode* createNode(char x)
{
    BSTNode* newNode = (BSTNode*) calloc(1, sizeof(BSTNode));
    if(newNode != NULL)
    {
        newNode->data = x;
        newNode->left = NULL;
        newNode->right = NULL;
    }


    return newNode;
}

BSTNode* insert(BSTNode* root, char x)
{
    if (root == NULL)
    {
        root = createNode(x);
    }

    else if(x<=root->data)
        root->left=insert(root->left, x);
    else if(x>root->data)
        root->right=insert(root->right,x);
    else
    {
        printf("Something is wrong ! \n");
        exit(1);
    }

    return root;
}

// infix order : left subtree -> root -> right subtree
void printinfix(BSTNode* root)
{
    if (root == NULL)
        return;

    else
    {
        printinfix(root->left);
        printf("%c ", root->data);
        printinfix(root->right);
    }
}

// prefix order : root -> left subtree -> right subtree
void printprefix(BSTNode* root)
{
    if (root == NULL)
        return;

    else
    {
        printf("%c ", root->data);
        printprefix(root->left);
        printprefix(root->right);
    }
}

// postfix preder : left subtree -> right subtree -> root  
void printpostfix(BSTNode* root)
{
    if (root == NULL)
        return;

    else
    {
        printpostfix(root->left);
        printpostfix(root->right);
        printf("%c ", root->data);
    }
}

int search(BSTNode* root, char x)
{
    if(root->data == x)
        return true;
    else if (root->data < x)
    {
        if(search(root->right, x));
            return true;
    }
    else
    {
        if(search(root->left, x))
            return true;
    }

    return false;
}

void main()
{
    BSTNode* myroot = NULL;

    myroot = insert(myroot, 'F');
    insert(myroot, 'A');
    insert(myroot, 'C');

    printinfix(myroot);
}