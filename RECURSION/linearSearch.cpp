#include <bits/stdc++.h>
using namespace std;    

class Solution
{
public:
    bool search(int *arr, int n, int key)
    {
        if(n==0)                 // no element found as size becomes 0
        return false;

        if(arr[0]==key)
        return true;

        return search(arr+1, n-1, key);        // arr keeps on shrinking as it is a pointer
    }
};
int main()
{
    Solution obj;
    int arr[] = {3, 7, 9, 5, 10, 12};
    int n = 6, key = 7;

    cout << obj.search(arr, n, key);
}