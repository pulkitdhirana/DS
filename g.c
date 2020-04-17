#include<stdio.h>
#include<stdlib.h>
int ty=0;
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
int leaf(struct node *t)
{
    if(t==NULL)
        return 0;
    if((t->left==NULL)&&(t->right==NULL))
    return 1;
    else
     return(leaf(t->left)+leaf(t->right));
}
int nonleaf(struct node* t)
{   if (t == NULL || (t->left == NULL &&  t->right == NULL))
        return 0;
        else
    {return (1 + nonleaf(t->left) +  nonleaf(t->right));
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
  {printf("1.No of leaf nodes\n2.Non-Leaf nodes\n3.Total nodes\n4.Exit\n");
   printf("Enter ur choice\n");
  scanf("%d",&choice);
  if(choice==4)
  {exit(1);
  }
  switch(choice)
     {
    case 1:x=leaf(root);
           printf("No of leaf nodes is %d\n",x);
           break;
    case 2:y=nonleaf(root);
            printf("Non leaf nodes is %d\n",y);
            break;
    case 3:countnode(root);
            printf("Total nodes is %d\n",ty);
            break;
    default:printf("Wrong choice\n");
            break;
     }
   }
}
