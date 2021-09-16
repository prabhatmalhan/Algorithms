#include <bits/stdc++.h>

using namespace std;

void heapify(int arr[], int n, int i)
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
        heapify(arr, n, max);
    }
}

void buildHeap(int arr[], int n)
{
    for (int i = n / 2; i >= 0; --i)
        heapify(arr, n, i);
}

void printarr(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    printarr(arr, n);
    buildHeap(arr, n);
    printarr(arr, n);
    return 0;
}