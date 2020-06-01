#include<stdio.h>
void swap(int* a, int* b)
{    int temp = *a;
    *a = *b;
    *b = temp;
}
int part (int A[], int l, int h)
{   int key = A[h];
    int i = (l - 1);
    for (int j = l; j <= h- 1; j++)
    {if (A[j] < key)
        {      i++;
            swap(&A[i], &A[j]);
        }
    }
    swap(&A[i + 1], &A[h]);
    return (i + 1);
}
void quickSort(int A[], int l, int h)
{
    if (l < h)
    {
        int pi = part(A, l, h);
        quickSort(A, l, pi - 1);
        quickSort(A, pi + 1, h);
    }
}
void printArray(int A[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}
void main()
{int n;
printf("Enter size of array");
scanf("%d",&n);
int A[n];
for(int k=0;k<n;k++)
{scanf("%d",&A[k]);
}
    quickSort(A, 0, n-1);
    printf("Sorted Array: ");
    printArray(A, n);
}
