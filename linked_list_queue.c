#include<stdio.h>
#include <stdlib.h>
typedef struct node
{
    struct node *prev;
    int info;
    struct node *next;
}node_type;

void add_node(node_type **hd,node_type **tl,int num)
{
    node_type *p;
    p = (node_type*)malloc(sizeof(node_type));
    
    if(p == NULL)
        printf("\t** OUT OF MEMORY **\n");
    
    else
    {
        p->info = num;
        p->next = NULL;
        
        if(*tl == NULL)
        {
            *tl = p;
            *hd = p;
            p->prev = NULL;
        }

        else
        {
            (*tl)->next = p;
            p->prev = *tl;
            *tl = p;
        }
        
    }
    
}

void print_forward(node_type *hd)
{
    if(hd == NULL)
        printf("\t** LINKED LIST EMPTY **\n");
    else
    {
        printf("Elements in the linked list are : \n");
        while(hd!=NULL)
        {
            printf("%d\n",hd->info);
            hd = hd->next;
        }
    }
}

void print_reverse(node_type *tl)
{
    if(tl == NULL)
        printf("\t** LINKED LIST EMPTY **\n");
    else
    {
        printf("Elements in the linked list are : \n");
        while(tl != NULL)
        {
            printf("%d\n",tl->info);
            tl = tl->prev;
        }
    }
}

void del_node(node_type **hd,node_type **tl,int key)
{
	int loc=1;
	node_type *temp;
	temp = *hd;
	while(temp->info!=key && temp->next!=NULL)
	{
		loc++;
		temp=temp->next;
	}
	if(temp->next == NULL && temp->info==key)
	{
		printf("Found at location %d",loc);
		(temp->prev)->next = NULL;
		*tl = temp->prev;
		return;
	}
	if(temp->info == key)
	{
		if(*hd == *tl)
		{
			*tl = NULL;
			*hd = NULL;
		}
		else
		{
			(temp->prev)->next = temp->next;
			(temp->next)->prev = temp->prev;
		}
		return;
	}
	printf("No such key found");
}

int main()
{
    node_type *head = NULL,*tail =  NULL;
    int run = 1;
    
    while(run)
    {
        printf("Type :- \n");
        printf("1) INSERT NODE\n");
        printf("2) DELETE NODE\n");
        printf("3) PRINT FORWARD\n");
        printf("4) PRINT BACKWARD\n");
        int ch;
        scanf("%d",&ch);
    
        switch(ch)
        {
            case 1: printf("Enter number :");
                    int num;
                    scanf("%d",&num);
                    add_node(&head,&tail,num);
                    break;
    
            case 2: if(head == NULL)
                        printf("\n\t** LIST IS EMPTY **\n");
                    else
                    {
                        printf("Enter the key :");
                        int n;
                        scanf("%d",&n);
                        del_node(&head,&tail,num);
                    }
                    break;
    
            case 3: print_forward(head);
                    break;
            
            case 4: print_reverse(tail);
                    break;
            
            case 5: run = 0;
                    break;
        }
    }
    return 0;
}