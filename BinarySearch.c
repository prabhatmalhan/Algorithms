#include<stdio.h>
int BinarySearch(int *arr,int k,int n)
{
    int b=0,e=n-1;
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
        
    
}
int main()
{
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0 ; i<n ; ++i)
        scanf("%d",&arr[i]);
    int ind;
    scanf("%d",&ind);
    if(BinarySearch(arr,ind,n))
        printf("Found");
    else
        printf("Not found");
    return 0;
}