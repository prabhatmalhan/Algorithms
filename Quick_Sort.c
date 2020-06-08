#include <stdio.h>
int partition(int arr[],int l,int h)
{
    int pivot = arr[l] , i=l , j=h;
    while(i<j)
    {
        do
        {
            i++;
        } while (pivot>=arr[i]);
        
        do
        {
            j--;
        } while (pivot<arr[j]);

        if(i<j)
        {
            int t = arr[i];
            arr[i] = arr[j];
            arr[j] = t;
        }        
    }
    arr[l] = arr[j];
    arr[j] = pivot;
    return j;
}

void QuickSort(int arr[],int l,int h)
{
    if(l<h)
    {
        int j = partition(arr,l,h);
        QuickSort(arr,l,j);
        QuickSort(arr,j+1,h);
    }
}

int main()
{
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0 ; i<n ; ++i)
        scanf("%d",&arr[i]);
    QuickSort(arr,0,n-1);
    for(int i=0 ; i<n ; ++i)
        printf("%d ",arr[i]);
    return 0;
}