#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} node_type;

node_type *insert(node_type *root)
{
    node_type *temp;
    temp = (node_type *)malloc(sizeof(node_type));
    if (temp == NULL)
        printf("Memory Full !!");
    else
    {
        printf("Enter the element : ");
        scanf("%d", &(temp->data));
        temp->left = NULL;
        temp->right = NULL;
        if (root == NULL)
            return temp;
        else
        {
            node_type *itr = root;
            node_type *follow = root;
            while (itr != NULL)
            {
                follow = itr;
                if (temp->data < itr->data)
                    itr = itr->left;
                else
                    itr = itr->right;
            }
            if (temp->data < follow->data)
                follow->left = temp;
            else
                follow->right = temp;
            return root;
        }
    }
}

void search(node_type *root, int key)
{
    if (root == NULL)
    {
        printf("Key not found !!\n\n");
        return;
    }
    else
    {
        if (root->data == key)
        {
            printf("Key found !!\n\n");
            return;
        }
        else
        {
            if (root->data > key)
                search(root->left, key);
            else
                search(root->right, key);
        }
    }
}

void display(node_type *root)
{
    if (root == NULL)
        return;
    else
    {
        display(root->left);
        printf("%d\t", root->data);
        display(root->right);
    }
}

void display2D(node_type *root,int level)
{
    if (root == NULL)
        return;
    else
    {
        display2D(root->right,level+1);
        for(int i=0 ; i<level ; ++i)
            printf("\t");
        printf("%d\n\n", root->data);
        display2D(root->left,level+1);
    }
}

int main()
{
    node_type *root = NULL;
    while (1)
    {
        int ch;
        printf("Type :-\n");
        printf("1) Insert Node\n");
        printf("2) Search Key\n");
        printf("3) Display BST\n");
        printf("4) Display BST in 2D\n");
        printf("5) Exit\n");
        printf("Choice : ");
        scanf("%d", &ch);

        if (ch == 1)
        {
            root = insert(root);
            printf("\n");
        }

        else if (ch == 2)
        {
            int key;
            printf("Enter the key : ");
            scanf("%d", &key);
            search(root, key);
        }

        else if (ch == 3)
        {
            printf("B.S.T. = ");
            display(root);
            printf("\n\n");
        }

        else if (ch == 4)
        {
            printf("B.S.T. =\n");
            display2D(root,0);
            printf("\n\n");
        }

        else if (ch == 5)
            break;
        else
            printf("\n");
    }
    return 0;
} // close of main
