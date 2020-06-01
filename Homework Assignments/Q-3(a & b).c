#include<stdio.h>
#include<string.h>
 void main()
 {    char s1[]="Polynomial";
     char s2[]="Test case";
     int len=strlen(s1);
     printf("%s is sorted: ",s1);
     merging(s1,0,len-1);
     printf("%s\n",s1);
     printf("%s is sorted: ",s2);
     len=strlen(s2);
      merging(s2,0,len-1);
       printf("\"%s\"\n",s2);
 }
 void merging(char str1[],int left,int right)
 {   char A[right-left];
     if(right>left)
     {  int mid=(left+right)/2;
         merging(str1,left,mid);
         merging(str1,mid+1,right);
         merge(str1,A,left,mid,right);
         copy(str1,A,left,right);
     }
 }
 void merge(char array1[],char array2[],int left,int mid,int right)
 { int k=0;
 int middle=mid+1;
   while(left<=mid && middle<=right)
   {
       if(array1[left]<array1[middle])
       {array2[k]=array1[left];
           left++;
       }
       else
       {array2[k]=array1[middle];
        middle++;
       }
       k++;
   }
 if(left>mid)
  while(middle<=right){
     array2[k]=array1[middle];
     middle++;k++;}
 else
  { while(left<=mid)
   {array2[k]=array1[left];
    left++;
    k++;
   }
  }
 }
void copy(char array1[],char array2[],int left,int right)
{ int k=0;
    for(int a=left;a<=right;a++)
    {  array1[a]=array2[k];
        k++;
    }
}
