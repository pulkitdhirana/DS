#include<stdio.h>
#include<stdlib.h>
struct node
{char data;
struct node *left,*right;
}*root;
struct node* creation()
{ char x;
    struct node* newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("enter the node data");
    scanf("%c",&x);
    fflush(stdin);
    if(x=='A')
    {return NULL;
    }
    else
    { newnode->data=x;
    printf("Data of the left node of %c\n",x);
    newnode->left=creation();
    printf("Data of the right node of %c\n",x);
    newnode->right=creation();
    return newnode;
    }
}
int main()
{  root=creation();
   int s;
    while(1)
    {printf("Output of tree\n");
     printf("1.Inorder\n2.Preorder\n3.Postorder\n4.Exit\n");
     printf("Enter ur choice\n");
     scanf("%d",&s);
     if(s==4)
     {exit(1);
     }
     else
     { switch(s)
       {case 1:inorder(root);
          printf("\n");
            break;
       case 2: pre(root);
            printf("\n");
            break;
       case 3: post(root);
            break;
       default: printf("Wrong choice\n");
            break;
       }
      }
    }
}
void inorder(struct node *temp)
{if(temp==NULL)
    {
    return ;
    }
    else
        {
inorder(temp->left);
printf("%c",temp->data);
inorder(temp->right);
}
}
void pre( struct node *temp)
{    if(temp==NULL)
    {
        return ;
    }
    else
        {
 printf("%c",temp->data);
    pre(temp->left);
pre(temp->right);
}
}
void post( struct node *temp)
{
    if(temp==NULL)
    {
        return ;
    }
    else
        {
 post(temp->left);
 post(temp->right);
 printf("%c",temp->data);
      }
}
