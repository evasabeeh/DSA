#include <bits/stdc++.h>
using namespace std;
int search(vector<int> &nums, int k){
    int start = 0, end = nums.size() - 1;
    int mid = (end - start) / 2 + start;                    // because int range 2^31 + 2^31 can not be added 
    while (start <= end){
        if(nums[mid]==k)
        return mid;
        else if(nums[mid]>k)
        end=mid-1;
        else
        start=mid+1;

        mid = (end - start) / 2 + start;
    }
    return -1;
}

int main()
{
    vector<int> nums = {24, 69, 100, 99, 79, 78, 67, 36, 26, 19};
    cout << search(nums, 79);
    return 0;
}


//O(log n)