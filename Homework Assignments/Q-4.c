#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{char mode[10];
struct node *left,*right;
}*root;
 struct node* create(struct node*temp,char a[])
{if(temp==NULL)
{
struct node* newnode;
newnode=(struct node*)malloc(sizeof(struct node));
strcpy(newnode->mode,a);
newnode->left=NULL;
newnode->right=NULL;
return newnode;
}
else
{
    if((strcmp(temp->mode,a)<0))
    temp->right=create(temp->right,a);
    else
    temp->left=create(temp->left,a);
}
}
int main()
{  root=NULL;
    int a=0;
    char names[6][10]={"Arthi","Christy","Dorothy","Fraser","Eliza","David"};
    while(a!=5)
    {root=create(root,names[a]);
     a++;
    }
    printf("The inorder representation before insertionion of David:");
    in(root);
    printf("\n");
    printf("The preorder representation before insertionion of David:");
    preorder(root);
     printf("\n");
    insertion(names[5]);
    printf("The inorder representation after insertionion of David:");
    in(root);
    printf("\n");
    printf("The preorder representation after insertionion of David:");
    preorder(root);
}
void in( struct node *temp)
{
    if(temp==NULL)
    { return;
    }
    else
        {
    in(temp->left);
printf("%s,",temp->mode);
in(temp->right);
}
}
void preorder( struct node *temp)
{
    if(temp==NULL)
    {
        return ;
    }
    else
        {
printf("%s,",temp->mode);
preorder(temp->left);
preorder(temp->right);
}
}
void insertion(char y[])
{
root=create(root,y);
}
