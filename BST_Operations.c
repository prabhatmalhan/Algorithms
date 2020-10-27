#include <stdio.h>
#include <stdlib.h>

typedef struct tree // basic tree node structure
{
    struct tree *left;
    int data;
    struct tree *right;
} tree_node;

tree_node *create(int num)
{
    tree_node *temp = (tree_node *)malloc(sizeof(tree_node));
    temp->data = num;
    temp->left = temp->right = NULL;
    return temp;
}

void insert(tree_node *root, tree_node *temp)
{
    if (root->data > temp->data)
    {
        if (root->left == NULL)
            root->left = temp;
        else
            insert(root->left, temp);
    }
    else
    {
        if (root->right == NULL)
            root->right = temp;
        else
            insert(root->right, temp);
    }
    return;
}

int count_nodes(tree_node *root, int count)
{
    if (root != NULL)
    {
        count++;
        count = count_nodes(root->left, count);
        count = count_nodes(root->right, count);
    }
    return count;
}

int count_leaves(tree_node *root, int count)
{
    if (root != NULL)
    {
        if (root->left == NULL && root->right == NULL)
            count++;
        count = count_leaves(root->left, count);
        count = count_leaves(root->right, count);
    }
    return count;
}

int count_leftChild(tree_node *root, int count)
{
    if (root != NULL)
    {
        if (root->left != NULL && root->right == NULL)
            count++;
        count = count_leftChild(root->left, count);
        count = count_leftChild(root->right, count);
    }
    return count;
}

int count_rightChild(tree_node *root, int count)
{
    if (root != NULL)
    {
        if (root->left == NULL && root->right != NULL)
            count++;
        count = count_rightChild(root->left, count);
        count = count_rightChild(root->right, count);
    }
    return count;
}

int main()
{
    char opt;
    tree_node *root = NULL;
    do
    {
        int n;
        printf("Enter the value of node :");
        scanf("%d", &n);
        tree_node *temp = create(n);
        if (root == NULL)
            root = temp;
        else
            insert(root, temp);
        do
        {
            fflush(stdin);
            printf("Do you want to add more nodes y/n :");
            scanf("%c", &opt);
        } while (opt != 'y' && opt != 'n');
        printf("\n");
    } while (opt != 'n');

    printf("No. of nodes in the BST = %d\n", count_nodes(root, 0));
    printf("No. of leaf nodes in the BST = %d\n", count_leaves(root, 0));
    printf("No. of nodes having left child only = %d\n", count_leftChild(root, 0));
    printf("No. of nodes having right child only = %d\n", count_rightChild(root, 0));
    printf("Nodes having data greater than root = %d\n", count_nodes(root->right, 0));
    return 0;
}
