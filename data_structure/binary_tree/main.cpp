#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

struct node
{
    int data ;
    node *left ;
    node *right ;
};


void ins();
void inorder(node *);
void preorder(node *);
void postorder(node *);


node *start = NULL ;
node *head ;


int main()
{
    int op;
    while(1)
    {
        printf("enter option\n1.insert 2.inorder 3.preorder 4.postorder 5.exit ");
        scanf("%d",&op);
        switch(op)
        {
        case 1:
            ins();
            break;
        case 2:
            inorder(start);
            break;
        case 3:
            preorder(start);
            break;
        case 4:
            postorder(start);
            break;
        case 5:
            exit(0);
            break;
        default:
            printf("wrong option\n");
        }
    }

    return 0;
}

void ins()
{
    char ch ;
    int flag = 0 ;
    if(start == NULL)
    {
        start = (node *) malloc(sizeof(node));
        printf("enter data\n");
        scanf("%d",&start->data);
        start->right = NULL ;
        start->left = NULL ;
    }
    else
    {
        head = start ;
        while(1)
        {
            printf("do you want to enter data to left or right of %d\n",head->data);
            scanf(" %c",&ch);
            if(ch == 'r' || ch == 'R')
            {
                if(head->right != NULL)
                {
                    head = head->right ;
                }
                else
                {
                    head->right = (node *) malloc(sizeof(node));
                    head = head -> right ;
                    flag = 1;
                    break;
                }
            }
            if(ch == 'l' || ch == 'L')
            {
                if(head->left != NULL)
                {
                    head = head->left ;
                }
                else
                {
                    head->left = (node *) malloc(sizeof(node));
                    head = head -> left ;
                    flag = 1;
                    break;
                }
            }
        }
        if(flag == 1)
        {
            head->right = NULL ;
            head->left = NULL ;
            printf("enter data\n");
            scanf("%d",&head->data);
            flag = 0 ;
        }
    }
}

void inorder(node *temp)
{
    if(temp!=NULL)
    {
        inorder(temp->left);
        printf("%d ",temp->data);
        inorder(temp->right);
    }

}

void postorder(node *temp)
{
    if(temp!=NULL)
    {
        postorder(temp->left);
        postorder(temp->right);
        printf("%d ",temp->data);
    }
}

void preorder(node *temp)
{
    if(temp!=NULL)
    {
        printf("%d ",temp->data);
        preorder(temp->left);
        preorder(temp->right);
    }
}
