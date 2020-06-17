#include<stdio.h>
int LinearSearch(int *a,int b,int n)
{
    for(int i=0;i<n;++i)
    {
        if(a[i] == b)
        {
            return 1;
        }
    }
    
    return 0;
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
    if(LinearSearch(arr,ind,n))
        printf("Found");
    else
        printf("Not found");
    return 0;
}