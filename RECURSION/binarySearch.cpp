#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool search(int *arr, int key, int start, int end)
    {
        if(start>end)
        return false;

        int mid = start + (end - start)/2;

        if(arr[mid] == key){
            cout<<mid<<" ";
            return true;
        }
        else if(key > arr[mid])
        return search(arr, key, mid+1, end);
        else if(key < arr[mid])
        return search(arr, key, start, mid-1);

        return 0;
    }
};
int main()
{
    Solution obj;
    int arr[] = {3, 7, 9, 10, 12};
    int n = 6, key = 10;

    cout << obj.search(arr, key, 0, n-1);
}