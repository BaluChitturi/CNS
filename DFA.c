#include<stdio.h>
int a=0;
void start(char c)
{
    if(c=='0')
    {
      a=2;  
      printf("|q%d|-----%c---->|q%d|\n",a-1,c,a);
    }
    else{
        a=-1;
    }
}
void state1(char c)
{
    if(c=='0')
    {
        a=2;
        printf("|q%d|-----%c---->|q%d|\n",a-1,c,a);
    }
    else{
        a=-1;
    }
}
void state2(char c)
{
    if(c=='0')
    {
        a=1;
        printf("|q%d|-----%c---->|q%d|\n",a+1,c,a);
    }
    else{
        a=-1;
    }
}
void main()
{
    char ar[100];
    int count=0;
    printf("DFA for Regular Expression--->(00)*\n");
    printf("Enter a String\n");
    scanf("%s",ar);
    for(int i=0;i<strlen(ar);i++)
    {
       if(a==0)
       {
           start(ar[i]);
       }
       else if(a==1)
       {
           state1(ar[i]);
       }
       else if(a==2)
       {
           state2(ar[i]);
       }
       else{
           break;
    }
    }
   if(a==1)
   {
       printf("string is accepted\n");
   }
   else{
       printf("String is not accepted\n");
   }
}
