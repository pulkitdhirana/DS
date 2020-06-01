#include<stdlib.h>
#include<stdio.h>
void merge(int A[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
    int L[n1], R[n2];
    for (i = 0; i < n1; i++)
        L[i] = A[l + i];
    for (j = 0; j < n2; j++)
        R[j] = A[m + 1+ j];
   i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            A[k] = L[i];
            i++;
        }
        else
        {
            A[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        A[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        A[k] = R[j];
        j++;
        k++;
    }
}
void mergeSort(int A[], int l, int r)
{
    if (l < r)
    {
        int m = l+(r-l)/2;
        mergeSort(A, l, m);
        mergeSort(A, m+1, r);
        merge(A, l, m, r);
    }
}

void printAay(int A[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}
int main()
{int n;
 printf("Enter Array size");
 scanf("%d",&n);
 int A[n];
for(int k=0;k<n;k++)
{
    scanf("%d",&A[k]);
}
    printf("Given Array is \n");
    printAay(A,n);
    mergeSort(A, 0,n - 1);
    printf("\nSorted Array is \n");
    printAay(A,n);
    return 0;
}
