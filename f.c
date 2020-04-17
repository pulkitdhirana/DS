#include<stdio.h>
#include<stdlib.h>
struct node
{char data;
struct node*left,*right;
};
struct node *create()
{char x;
struct node *newnode=(struct node *)malloc(sizeof(struct node));
printf("Enter data (0 for No data)");
scanf("%c",&x);
fflush(stdin);
 if(x=='0')
 {return 0;
 }
 else
 {newnode->data=x;
 printf("Enter left child of %c\n",x);
 newnode->left=create();
 printf("Enter right child of %c\n",x);
 newnode->right=create();
 return newnode;
 }
}
void countnode(struct node *t)
{
    if(t==0)
    {
        return;
    }
    countnode(t->left);
    ty++;
    countnode(t->right);
}
void main()
{int choice,x,y,z;
struct node *root;
root=0;
root=create();
 while(1)
  {printf("1.Total nodes\n2.Exit\n");
   printf("Enter ur choice\n");
  scanf("%d",&choice);
  if(choice==2)
  {exit(1);
  }
  switch(choice)
     {
    case 1:countnode(root);
            printf("Total nodes is %d\n",ty);
            break;
    default:printf("Wrong choice\n");
            break;
     }
   }
}
