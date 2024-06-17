#include <bits/stdc++.h>
using namespace std;                   //find first & last occurence of k in sorted array
void firstAndLastPosition(vector<int> &arr, int n, int k)
{
    int start = 0, end = n - 1;
    int mid = (start + end) / 2;
    int left = -1, right = -1;

    while (start <= end)                     //first occurence
    {
        if (arr[mid] == k)
        {
            left = mid;
            end = mid - 1;
        }
        else if (arr[mid] > k)
            end = mid - 1;
        else
            start = mid + 1;

        mid = (start + end) / 2;
    }
    start = 0;
    end = n - 1;
    mid = (start + end) / 2;

    while (start <= end)                        //last occurence
    {
        if (arr[mid] == k)
        {
            right = mid;
            start = mid + 1;
        }
        else if (arr[mid] > k)
            end = mid - 1;
        else
            start = mid + 1;

        mid = (start + end) / 2;
    }
    cout<<left<<" "<<right;
}
int main(){
    vector<int> nums={1, 2, 3, 3, 3, 3, 6, 7, 9, 13};
    firstAndLastPosition(nums, 10, 3);
    return 0;
}




// total occurences = right-left+1               edge case for 0 occurence