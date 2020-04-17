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
void inorder(struct node *t)
{if(t)
 {inorder(t->left);
  printf("%c",t->data);
  inorder(t->right);
 }
}
void preorder(struct node *t)
{if(t)
 {printf("%c",t->data);
    inorder(t->left);
  inorder(t->right);
 }
}
void postorder(struct node *t)
{if(t)
 {inorder(t->left);
  inorder(t->right);
 printf("%c",t->data);
 }
}
void main()
{int choice,x,y,z;
struct node *root;
root=0;
root=create();
 while(1)
  {printf("1.Inorder\n2.Preorder\n3.Postorder\n4.Exit\n");
   printf("Enter ur choice\n");
  scanf("%d",&choice);
  if(choice==4)
  {exit(1);
  }
  switch(choice)
     {case 1:inorder(root);
            break;
     case 2:preorder(root);
            break;
    case 3:postorder(root);
           break;
    default:printf("Wrong choice\n");
            break;
     }
   }
}

