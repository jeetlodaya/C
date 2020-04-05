#include <iostream>
#include <string.h>

using namespace std;

int look_up(char c)
{
    switch(c)
    {
        case 'I':
            return 1;
            break;
        case 'V':
            return 5;
            break;
        case 'X':
            return 10;
            break;
        case 'L':
            return 50;
            break;
        case 'C':
            return 100;
            break;
        case 'D':
            return 500;
            break;
        case 'M':
            return 1000;
            break;
        default:
            return -1;
    }
}

long int Roman2Decimal(char *str)
{
    long int deci=0;
    int cur_val,prv_val=1000;
    while(*str)
    {
        cur_val = look_up(*(str++));
        if(cur_val == -1)
            return -1;
        else if(cur_val > prv_val)
            deci += cur_val - 2*prv_val;
        else
            deci += cur_val;
        prv_val = cur_val;

    }
    return deci;
}

int main()
{
    char str[20];
    long int deci;

    while(1)
    {
        cin>>str;
        deci = Roman2Decimal(str);
        if(deci == -1)
        {
            cout<<"ERROR";
            return -1;
        }
        else
            cout<<deci<<endl;
    }

    return 0;
}
