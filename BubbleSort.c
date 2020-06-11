#include<stdio.h>

void BubbleSort(int *a,int n)
{
    for(int i=0 ; i<n-1 ; ++i)
    {
        for(int j=0 ; j<n-i-1 ; ++j)
        {
            if(*(a+j)>*(a+j+1))
            {
                int t=*(a+j);
                *(a+j)=*(a+j+1);
                *(a+j+1)=t;
            }
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
    BubbleSort(arr,n);
    for(int i=0 ; i<n ; ++i)
        printf("%d ",arr[i]);
    return 0;
}