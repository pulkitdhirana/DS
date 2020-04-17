#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char pre[50];
int i=0;
struct node
{char data;
    struct node*link;
};
struct node* top=NULL;
void main()
{ char c;
    char infix[50]="A+B-C*D+(P^O)*X/Y/V*Z+Q";
    printf("%c",infix[1]);
    int n,m=strlen(infix);
    n=m;
    printf("%d\n",n);
    while(m)
    {
        if(infix[m-1]==('^')||infix[m-1]==('*')||infix[m-1]==('/')||infix[m-1]==('+')||infix[m-1]==('-')||infix[m-1]==('(')||infix[m-1]==(')'))
        {
          c=infix[m-1];
         stack(c);
        }
        else
        {
            printf("%c",infix[m-1]);
            pre[i]=infix[m-1];
            i++;
        }
        m--;

    }
    while(top)
    {
        pop();
    }
    while(i+1)
    {
    printf("%c",pre[i]);
    i--;
    }
}
void stack (char c)
{
if(top==NULL||c==')'||c=='^')
    push(c);
else
com(c);
}
void push( char z)
{
    struct node*temp;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=z;
    temp->link=top;
    top=temp;
}
void pop()
{    struct node *temp;
    if(top==NULL)
    {
        printf("No data to delete\n");
    }
    else
    {
        printf("%c",top->data);
        pre[i]=top->data;
        i++;
        top=top->link;

    }
}
void com(char y)
{
    if(y==top->data||(y=='+'&&top->data=='-')||(y=='-'&&top->data=='+')||(y==''&&top->data=='/')||(y=='/'&&top->data==''))
    {
        if(y=='^')
        {
          pop();
          stack(y) ;
        }
        else
            push(y);
    }
    else
    {
        if(top->data=='+'||top->data=='-'||top->data=='(')
            push(y);
        else
        {
            if(top->data=='*'&&y=='^')
                push(y);
                else
                {
                    if((y=='+'||y=='-')&&(top->data=='^'||top->data=='*'||top->data=='/'))
                    {
                        pop();
                        stack(y);
                    }
                    else
                    {
                        if((y=='*'||y=='/')&&(top->data=='^'))
                        {
                                pop();
                        stack(y);
                    }
                    else
                    {
                        while(top->data!=')')
                        {
                            pop();
                        }
                        top=top->link;
                    }
                        }
                }

        }
    }
}
