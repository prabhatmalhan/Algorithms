#include<stdio.h>
#define min(i,n) i<n?i:n
int BinarySearch(int *arr,int k,int b,int e)
{
    while(b<=e)
    {
        int mid=(b+e)/2;
        if(arr[mid] == k)
        {
            return 1;
        }
        else if(arr[mid] < k)
        {
            b=mid+1;
        }
        else
        {
            e=mid-1;
        }
    } 
    return 0;   
}

int ExponentialSearch(int arr[],int k,int n)
{
    if(arr[0]==k)
        return 1;
    else
    {
        int i=1;
        while (i<n && arr[i]<=k)
            i*=2;
        return BinarySearch(arr,k,i/2,min(i,n));
    }
}

int main()
{
    int n;
    scanf("%d",&n);
    int arr[n];
    //array should be compulsorily sorted
    for(int i=0 ; i<n ; ++i)
        scanf("%d",&arr[i]);
    int k;
    scanf("%d",&k);
    if(ExponentialSearch(arr,k,n))
        printf("Found");
    else
        printf("Not found");
    return 0;
}
