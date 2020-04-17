#include<stdio.h>
#include<stdlib.h>
struct node
{struct node *link;
int data;
struct node *prev;
}*head;
int main()
{
ddl();
}
void ddl()
{int a,n,j,b=1;
struct node *p1,*temp,*temp1;
struct node *head=(struct node *)malloc(sizeof(struct node));
temp=head;
printf("Enter head data\n");
scanf("%d",&a);
head->data=a;
head->prev=NULL;
head->link=NULL;
temp=head;
printf("enter no of nodes doubly");
scanf("%d",&n);
for(int i=0;i<n;i++)
{p1=(struct node *)malloc(sizeof(struct node));
printf("Enter data of node");
scanf("%d",&j);
p1->data=j;
p1->prev=temp;
temp->link=p1;
p1->link=NULL;
temp=temp->link;
}
temp=head;
 while(temp)
 {printf("%d\n",temp->data);
 temp=temp->link;
 }
temp=head;
printf("Enter which node to be deleted\n");
scanf("%d",&a);
if(a==1)
 {head=head->link;
  head->prev=NULL;
  temp->link=NULL;
  free(temp);
  temp=head;
 }
 else if(a!=n+1)
 {  while(b!=a)
    {temp=temp->link;
      b++;
    }
    temp->link->prev=temp->prev;
    temp->prev->link=temp->link;
    temp1=head;
    free(temp);
    temp=temp1;
 }
   else
     {
       while(b!=a-1)
       {temp=temp->link;
       b++;
       }
       temp1=temp->link;
       temp1->prev=NULL;
       temp->link=NULL;
       free(temp1);
       temp=head;
     }
 printf("New list after deletion is\n");
    while(temp)
    {printf("%d\n",temp->data);
    temp=temp->link;
    }
   }
