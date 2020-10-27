#include <stdio.h>

void InsertionSort(int[],int);

int main()
{
    int n;
    printf("Enter the no. of elements : ");
    scanf("%d",&n);
    int array[n];
    for(int i=0;i<n;++i)
    {
        printf("Enter the element : ");
        scanf("%d",&array[i]);
    }
    InsertionSort(array,n);
    printf("Sorted Array :- ");
    for(int i=0;i<n;++i)
        printf("\t%d",array[i]);
    return 0;
}

void InsertionSort(int arr[],int n)
{
    for (int  i = 1; i < n; i++)
    { 
        int key = arr[i]; 
        int j = i - 1; 
  
        while (j >= 0 && arr[j] > key)
        { 
            arr[j + 1] = arr[j]; 
            j = j - 1; 
        } 
  
        arr[j + 1] = key; 
    } 
}