#include<stdio.h>
void main()
{int n,temp,i=0,j;
printf("Enter array size");
scanf("%d",&n);
int A[n];
for(int a=0;a<n;a++)
{scanf("%d",&A[a]);
}
for(;i<n;i++)
{temp=A[i];
j=i-1;
while(j>=0 && A[j]>temp)
{A[j+1]=A[j];
j--;
}
A[j+1]=temp;
}
printf("Sorted array is ");
for(int k=0;k<n;k++)
{printf("%d",A[k]);
}
}
