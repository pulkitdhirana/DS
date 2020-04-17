#include<stdio.h>
#include<stdlib.h>
struct node
{struct node *link;
int data;
}*head;
int main()
{create();
}
void create()
{int k,n,j,l;
struct node *temp,*temp1,*p;
head=(struct node*)malloc(sizeof(struct node));
temp1=(struct node*)malloc(sizeof(struct node));
temp=head;
temp1=head;
printf("enter head data");
scanf("%d",&k);
head->data=k;
head->link=NULL;
printf("Enter no of nodes");
scanf("%d",&n);
for(int i=0;i<n;i++)
{p=(struct node*)malloc(sizeof(struct node));
printf("Enter data of node");
scanf("%d",&j);
p->data=j;
p->link=NULL;
temp->link=p;
temp=temp->link;
}
temp=head;
while(temp)
{printf("%d\n",temp->data);
temp=temp->link;
}
temp=head;
printf("Enter which node to be deleted");
scanf("%d",&l);
if(l==1)
{head=temp->link;
free(temp);
temp=head;
}
else
{for(int i=1;i<l;i++)
  {temp1=temp1->link;
  }
  for(int i=1;i<l-1;i++)
  {
   temp=temp->link;
  }
temp->link=temp1->link;
free(temp1);
temp=head;
temp1=head;
}
while(temp1)
  {printf("%d\n",temp->data);
  temp=temp->link;
 }
}
