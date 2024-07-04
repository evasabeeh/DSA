#include <bits/stdc++.h>
using namespace std;                  // Check if array is sorted 

class Solution
{
public:
    bool isSorted(int *arr, int n){
        if(n==0 || n==1)
        return true;

        if(arr[0]>arr[1])
        return false;

        return isSorted(arr+1, n-1);
    }
};
int main()
{
    Solution obj;
    int arr[]={3, 7, 9, 5, 10, 12};
    int n=5;

    cout<<obj.isSorted(arr, n);
}