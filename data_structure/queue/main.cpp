#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

void enq();
void deq();
void display();

struct node
{
    int data ;
    node *next ;
};
node *f = NULL ;
node *r = NULL ;

int main()
{
    int op ;
    while(1)
    {
        printf("enter option 1.enqueue 2.dequeue 3.display 4.exit\n");
        scanf("%d",&op);
        switch(op)
        {
        case 1:
            enq();
            break;
        case 2:
            deq();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("wrong option\n");
        }
    }

    return 0;
}

void enq()
{
    if(r == NULL && f == NULL)
    {
        f = (node *) malloc(sizeof(node));
        r = f;
        printf("enter data to be enqueued\n");
        scanf("%d",&r->data);
        r->next = NULL ;
    }
    else
    {
        r->next = (node *) malloc(sizeof(node));
        r = r->next ;
        printf("enter data to be enqueued\n");
        scanf("%d",&r->data);
        r->next = NULL ;
    }
}

void deq()
{
    if(f == NULL)
    {
        printf("queue is empty\n");
    }
    else
    {
        node *temp;
        temp = f;
        f = f->next;
        if(f == NULL)
            r = f;
        free(temp);
    }
}

void display()
{
    if(f == NULL)
    {
        printf("queue is empty\n");
    }
    else
    {
        node *temp = f  ;
        while(temp != NULL)
        {
            printf("%d->",temp->data);
            temp= temp->next ;
        }
        printf("NULL\n");
    }
}
