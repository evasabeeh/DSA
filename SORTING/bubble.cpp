#include <bits/stdc++.h>         //optimized bubble sort - swapped var will tell you that array is sorted, no need to go for another pass
using namespace std;            //stable

int main()
{
    int arr[] = {6, 3, 12, 1, 25, 2, 9};
    int n = 7;

    for (int i = 0; i < n - 1; i++)
    {
        bool swapped=false;
        for (int j = 0; j < n; j++)
        {
            if (arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
                swapped=true;
            }
        }
        if(!swapped)         //sorted
        break;
    }
    for (int i : arr)
    cout << i << " ";

    return 0;
}