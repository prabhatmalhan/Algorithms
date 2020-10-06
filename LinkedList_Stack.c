#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node_type;

typedef struct
{
    node_type *top;
} STACK;

void push(node_type **top)
{
    node_type *temp;
    temp = (node_type *)malloc(sizeof(node_type));
    if (temp == NULL)
        printf("MEMORY FULL");
    else
    {
        scanf("%d", &(temp->data));
        temp->next = *top;
        *top = temp;
    }
}

void pop(node_type **top)
{
    if (*top == NULL)
        printf("LIST EMPTY");
    else
    {
        node_type *temp = *top;
        *top = (*top)->next;
        printf("Poped element is : %d", temp->data);
        free(temp);
    }
}

void display(node_type **t)
{
    node_type *top = *t;
    if (top == NULL)
        printf("LIST EMPTY");
    else
    {
        while (top != NULL)
        {
            printf("%d\t", top->data);
            top = top->next;
        }
    }
    printf("\n");
}

int main()
{
    STACK stack;
    stack.top = NULL;
    int run = 1;
    while (run)
    {
        int ch;
        printf("Enter the choice");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            push(&(stack.top));
            break;
        case 2:
            pop(&(stack.top));
            break;
        case 3:
            display(&(stack.top));
            break;
        default:
            run = 0;
        }
    }
    return 0;
}
