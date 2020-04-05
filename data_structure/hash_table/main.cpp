#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void insert_data();
void display_all();
void search_hashtable();
void exit_pmg();
void (*fp[4])();

struct node
{
    char *key_name;
    char *value_phonenumber;
    node *next;
};

node *roots[24] = {0};

int main()
{
    fp[1] = insert_data;
    fp[2] = display_all;
    fp[3] = search_hashtable;
    fp[4] = exit_pmg;

    while(1)
    {
        printf("1.insert data into hash table\n2.display the hash table\n3.search inside the hash table\n4.exit\n");
        int op;
        scanf("%d",&op);
        fflush(stdin);
        fp[op]();
    }
    return 0;
}

int hash_function(char str[])
{
    return str[0]%24;
}

void insert_data()
{
    node *temp;

    char buf[30];
    printf("enter the name\n");
    gets(buf);

    int hash_index;
    hash_index = hash_function(buf);

    if(roots[hash_index] == NULL)
    {
        temp = (node *) malloc(sizeof(node));
        roots[hash_index] = temp;
    }
    else
    {
        temp = roots[hash_index];
        while(temp->next != NULL)
            temp = temp->next;

        temp->next = (node *) malloc(sizeof(node));
        temp = temp->next;
    }


    temp->key_name = (char *) malloc((strlen(buf)+1)*sizeof(char));
    strcpy(temp->key_name,buf);

    printf("enter the phone number\n");
    gets(buf);
    temp->value_phonenumber = (char *) malloc((strlen(buf)+1)*sizeof(char));
    strcpy(temp->value_phonenumber,buf);

    temp->next = NULL;
}


void search_hashtable()
{
    char str[20];
    printf("enter the name to be searched\n");
    gets(str);
    int hash_index = hash_function(str);
    node *temp = roots[hash_index];

    bool found = 0;
    while(temp != NULL)
    {
        if(!strcmp(temp->key_name,str))
        {
            printf("found! %s and the phone knumber is %s\n",str,temp->value_phonenumber);
            found = 1;
        }
        temp = temp->next;
    }
    if(!found)
        printf("sorry couldn't find %s\n",str);
}

void display_all()
{
    for(int i=0;i<=23;i++)
    {
        node *temp = roots[i];
        while(temp != NULL)
        {
            printf("%s %s->",temp->key_name,temp->value_phonenumber);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

void exit_pmg()
{
    exit(0);
}




