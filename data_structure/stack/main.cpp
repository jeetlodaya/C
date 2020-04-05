#include <stdio.h>
#include<stdlib.h>
#include<malloc.h>

void pop();
void push();
void display();

struct node
{
    int data ;
    node *next ;
};

node *top = NULL;


int main()
{
    int op;
    while(1)
    {
        printf("enter option\n1.push 2.pop 3.display 4.exit ");
        scanf("%d",&op);
        switch(op)
        {
        case 1:
            push();
            break ;
        case 2:
            pop();
            break ;
        case 3:
            display();
            break;
        case 4:
            exit(1);
            break;
        default :
            printf("wrong option\n");
        }
    }

    return 0;
}

void pop()
{
    if(top==NULL)
    {
        printf("no elements in stack\n");
    }
    else
    {
        node *temp;
        temp = top;
        top=top->next ;
        free(temp);
    }
}

void push()
{
    if(top==NULL)
    {
        top = (node *) malloc(sizeof(node));
        printf("enter data to be pushed into stack \n");
        scanf("%d",&top->data);
        top->next = NULL ;
    }
    else
    {
        node *temp = (node *) malloc(sizeof(node));
        printf("enter data to be pushed into stack \n");
        scanf("%d",&temp->data);
        temp->next = top ;
        top = temp ;
    }
}

void display()
{
    node *temp ;
    temp  = top ;
    if(temp == NULL)
    {
        printf("no element in stack\n");
    }
    else
    {
        do
        {
            printf("%d->",temp->data);
            temp = temp->next ;
        }
        while(temp != NULL );
        printf("NULL\n");
    }
}
