#include<stdio.h>
#include <math.h>

int jumpSearch(int arr[],int key,int l,int n,int j)
{
    if(l>=n)
        return 0;
    else
    {
        int x = l+j;
        if(x>n)
            x=n;
        if(arr[x]>key)
        {
            for(int i=l;i<x;++i)
                if(arr[i]==key)
                    return 1;
            return 0;
        }
    }
    jumpSearch(arr,key,l+j,n,j);
}

int main()
{
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0 ; i<n ; ++i)
        scanf("%d",&arr[i]);
    int k;
    scanf("%d",&k);
    if(jumpSearch(arr,k,0,n,sqrt(n)))
        printf("Found");
    else
        printf("Not found");
    return 0;
}
