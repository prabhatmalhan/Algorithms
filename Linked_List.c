#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node_type;

typedef struct
{
    node_type *start;
} Linked_List;

void insert(node_type **start)
{
    node_type *temp;
    temp = (node_type *)malloc(sizeof(node_type));

    if (temp == NULL)
        printf("Memory Full\n");
    else
    {
        //data input
        int n;
        printf("Enter the element : ");
        scanf("%d", &n);

        //inserting data in the node to be added
        temp->data = n;

        //inserting node in stack
        temp->next = *start;
        *start = temp;
    }
}

void delete (node_type **start)
{
    if (*start == NULL)
        printf("LIST EMPTY");
    else
    {
        int key;
        printf("Enter the key : ");
        scanf("%d", &key);
        node_type *temp = *start, *follow = *start;
        while (temp != NULL)
        {
            //if key is found
            if (temp->data == key)
            {
                printf("KEY FOUND");
                //if the first node is the key
                if (temp == *start)
                    *start = (*start)->next;
                else
                    follow->next = temp->next;
                free(temp); //deleted node
                return;
            }
            follow = temp;
            temp = temp->next;
        }
        //when key not found
        printf("KEY NOT FOUND!!");
    }
}

void display(node_type *start)
{
    if (start == NULL) //base condition
        return;
    else
    {
        //recursive case
        display(start->next); //recursive call
        printf("%d\t", start->data);
    }
}

int main()
{
    Linked_List linkedList;

    //initializing default values of the Linked List
    linkedList.start = NULL;

    int run = 1; //for the loop to run forever till broke

    while (run)
    {
        printf("Type :- \n");
        printf("1) INSERT NODE\n");
        printf("2) DELETE NODE\n");
        printf("3) DISPLAY LIST\n");
        printf("4) EXIT\n");

        int ch;
        printf("Enter the choice : ");
        scanf("%d", &ch);
        printf("\n");
        switch (ch)
        {
        case 1:
            insert(&(linkedList.start));
            printf("\n");
            break;

        case 2:
            delete (&(linkedList.start));
            printf("\n\nNEW ");

        case 3:
            printf("LIST : ");
            if (linkedList.start == NULL)
                printf("EMPTY");
            else
                display(linkedList.start);
            printf("\n\n");
            break;

        case 4:
            run = 0;
            break;

        default:
            printf("INVALID INPUT\n\n");
        } //close of switch
    } //close of switch
    return 0;
} //close of main
