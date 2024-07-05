#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void sortArray(vector<int> &arr, int n){
        if(n==0 || n==1)
        return;
        
        bool swapped = false;
        for(int j=0;j<n-1;j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if(!swapped)
        return;

        sortArray(arr, n-1);
    }
};
int main()
{
    Solution obj;
    vector<int> arr={4, 10, 1, 3, 2, 6, 2, 4, 5};
    int n=9;

    obj.sortArray(arr, n);
    for(int i: arr)
    cout<<i<<" ";

    return 0;
}