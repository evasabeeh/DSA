#include<bits/stdc++.h>                  // mistake
using namespace std;

void heapify(int arr[], int n, int i)
{
    int largest = i;
    int left = 2 * i + 1, right = 2 * i + 2;

    if (left < n && arr[largest] < arr[left])
        largest = left;

    if (right < n && arr[largest] < arr[right])
        largest = right;

    if (largest != i)
    {
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n){
    for (int i = n / 2 + 1; i >= 0; i--)
        heapify(arr, n, i);
        
    int size = n-1;
    while (size > 0)
    {
        swap(arr[size], arr[0]);
        size--;

        heapify(arr, size, 0);
    }
}

int main(){
    int n=5;

    int arr[5]={56, 51, 21, 43, 77};

    heapSort(arr, n);

    for (int i = 0; i < n; i++) // after sorting
        cout << arr[i] << " ";
}

// comparison based sorting algo, non recursive method that uses binary tree to sort an array


// build heap
// swap arr[first] with arr[last]      and size-- (last element is sorted)
// bring root to correct position      (heapify)
// O(N log N)