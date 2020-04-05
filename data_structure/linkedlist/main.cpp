#include <stdio.h>
#include<malloc.h>
#include<stdlib.h>

void ins();
void del();
void display();
void create();

struct node
{
    int data;
    node *next = NULL;
};
node *head = NULL;

int main()
{
    int op ;
    while (1)
    {
        printf("select a option\n1.create 2.display 3.delete 4.insert 5.exit ");
        scanf("%d",&op);
        switch(op)
        {
        case 1:
            create();
            break ;
        case 2:
            display();
            break;
        case 3:
            del();
            break;
        case 4:
            ins();
            break ;
        case 5 :
            exit(0);
        }
    }

    return 0;
}

void create ()
{
    node *temp;
    temp = (node *) malloc(sizeof(node));
    char ch;

    do
    {
        if(head == NULL )
        {
            head = temp ;
        }
        else
        {
            temp->next = (node *) malloc(sizeof(node));
            temp = temp->next;
        }
        printf("enter data\n");
        scanf("%d",&temp->data);
        printf("do you want to enter another data?\n");
        scanf(" %c",&ch);
    } while(ch == 'y' || ch == 'Y');

    temp->next = NULL;
}

void display()
{
    node *temp;
    temp = head;
    if(temp == NULL)
    {
        printf("linked list is not created/empty\n");
    }
    else
    {
        do
        {
            printf("%d->",temp->data);
            temp = temp->next;
        } while(temp != NULL);

        printf("NULL\n");
    }
}

void del()
{
    if(head == NULL)
        printf("linked list is empty\n");

    else
    {
        node *temp;
        temp = head;
        head = head->next ;
        free(temp);
    }

}

void ins()
{
    node *temp;
    temp = (node *) malloc(sizeof(node));
    printf("enter data\n");
    scanf("%d",&temp->data);
    temp->next = head ;
    head = temp ;
}



