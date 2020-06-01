#include<stdio.h>
void main()
{int n,m=0,l=0;
printf("Enter size of array");
scanf("%d",&n);
int A[n];
printf("Enter elements in array : ");
    for(m=0; m<n; m++)
    {
    scanf("%d", &A[m]);
    }
for(int j=0;j<n-1;j++)
{for(int k=0;k<n-1;k++)
   { if(A[k]>A[k+1])
     {
     swap(&A[k],&A[k+1]);
     }
   }
}
printf("Sorted list is");
for(;l<n;l++)
{printf("%d",A[l]);
}
}
void swap(int *x ,int *y)
{int temp;
 temp=*x;
 *x=*y;
 *y=temp;
}
