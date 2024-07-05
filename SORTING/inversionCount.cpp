#include <bits/stdc++.h>
using namespace std; 

// how far (or close) the array is from being sorted. If the array is already sorted, then the inversion count is 0, but if the array is sorted in reverse order, the inversion count is the maximum.

int merge(int *arr, int start, int mid, int end)
{
    int m[end - start + 1];
    int i1 = start;
    int i2 = mid + 1;
    int x = 0, count = 0;

    while (i1 <= mid && i2 <= end)
    {
        if (arr[i1] <= arr[i2])
            m[x++] = arr[i1++];
        else{
            m[x++] = arr[i2++];

            count += (mid - i1 + 1);                 // arr[i] > arr[j]
        }
    }
    while (i1 <= mid)
    {
        m[x++] = arr[i1++];
    }
    while (i2 <= end)
    {
        m[x++] = arr[i2++];
    }

    for (int i : m)
        arr[start++] = i;

    return count;
}

int divide(int *arr, int start, int end)
{
    int count = 0;

    if (start >= end)
    {
        return count;
    }
    int mid = (start + end) / 2;

    count += divide(arr, start, mid); 
    count += divide(arr, mid + 1, end);

    count += merge(arr, start, mid, end);

    return count;
}

int main()
{
    int arr[] = {1, 20, 6, 4, 5};

    cout << divide(arr, 0, 5);

    return 0;
}