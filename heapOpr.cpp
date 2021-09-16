#include <bits/stdc++.h>

using namespace std;

int n;

void heapify(int arr[], int i)
{
    int c1 = 2 * i + 1, c2 = 2 * i + 2, max = i;
    if (c1 < n && arr[c1] > arr[max])
        max = c1;
    if (c2 < n && arr[c2] > arr[max])
        max = c2;
    if (max != i)
    {
        int t = arr[i];
        arr[i] = arr[max];
        arr[max] = t;
        heapify(arr, max);
    }
}

int Extract_Max(int arr[])
{
    int t = arr[0];
    arr[0] = arr[n - 1];
    arr[n - 1] = t;
    n--;
    heapify(arr, 0);
    return arr[n];
}

void add_Element(int arr[], int e)
{
    arr[n] = e;
    int nn=n++;
    int p = floor((nn*1.0  - 1)/ 2);
    while (p >= 0)
    {
        heapify(arr, p);
        nn=p;
        p = floor((nn*1.0  - 1)/ 2);
    }
}

void printarr(int arr[])
{
    if(n==0)
        cout<<"empty heap";
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int x;
    cin >> x;
    int arr[100];
    n = 0;
    for (int i = 0; i < x; ++i)
    {
        int t;
        cin >> t;
        add_Element(arr, t);
        printarr(arr);
    }
    for (int i = 0; i < x; ++i)
    {
        cout << Extract_Max(arr) << endl;
        printarr(arr);
    }
    return 0;
}