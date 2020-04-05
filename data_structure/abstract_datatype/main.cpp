#include<stdio.h>

int add(int,int);
int sub(int,int);
int mul(int,int);
int div(int,int);
int (*fp[4]) (int, int);

int main()
{
    int a, b,op,result;
    printf("enter two numbers \n");
    scanf("%d%d",&a,&b);

    fp[1] = add ;
    fp[2] = sub ;
    fp[3] = mul ;
    fp[4] = div ;

    do
    {
        printf("\n 1.add \n 2.sub \n 3.mul \n 4.div \n 5.exit \n");
        scanf("%d",&op);
        result = (*fp[op])(a,b);
        printf (" result is %d ", result);
    }
    while(op!=5);
    return 0 ;
}


int add(int a, int b)
{
    return a+b ;
}

int sub(int a, int b)
{
    return a-b ;
}

int mul(int a, int b)
{
    return a*b ;
}

int div(int a, int b)
{
    return a/b ;
}

