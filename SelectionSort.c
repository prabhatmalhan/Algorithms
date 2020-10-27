#include<stdio.h>

void SelectionSort(int *a,int n)
{
    for(int i=0;i<n-1;++i)
    {
        int sm = i;
        for(int j=i+1 ; j<n ; ++j)
            if(a[sm]>a[j])
              sm = j;
        int temp = a[sm];
        a[sm]=a[i];
        a[i]=temp;
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0 ; i<n ; ++i)
        scanf("%d",&arr[i]);
    SelectionSort(arr,n);
    //Sorted Array
    for(int i=0 ; i<n ; ++i)
        printf("%d ",arr[i]);
    return 0;
}
