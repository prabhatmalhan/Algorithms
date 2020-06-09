/*
Merge Sort follow divide and conquer technique for sorting
Best case : O(nlogn)
Medium case : O(nlogn)
Worst Case : O(nlogn)
*/

#include<stdio.h>
#include <stdlib.h>

int *a;

//merging the two arrays formed by splitting the original array from "l to m" and then "m+1 to h"
void Merge(int l,int m,int h)
{
    
    int b[h-l+1],i,j,k;
    for(i=l,j=m+1,k=0 ; i<=m && j<=h ; )
    {
        if(a[i]<a[j])
            b[k++]=a[i++];
        else
            b[k++]=a[j++];
    }
    for(;i<=m;++i)
        b[k++]=a[i];
    for(;j<=h;++j)
        b[k++]=a[j];
    for(int i=l,j=0 ; i<=h ; ++i,++j)
        a[i]=b[j];
    
    
}

//recursively calling the function for divide and conquer algorithm
//i.e to split array into smaller arrays
void MergeSort(int l,int h)
{
    if(l<h)
    {
        int mid=(l+h)/2;
        MergeSort(l,mid);
        MergeSort(mid+1,h);
        Merge(l,mid,h);
    }
}

int main()
{
    int n;
    scanf("%d",&n);
    a = (int*)malloc(n*sizeof(int));
    for(int i=0 ; i<n ; ++i)
        scanf("%d",a+i);
    MergeSort(0,n-1);
    for(int i=0 ; i<n ; ++i)
        printf("%d ",a[i]);
    return 0;
}
