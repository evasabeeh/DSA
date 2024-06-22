#include <bits/stdc++.h>
using namespace std;                         // search k in rotated sorted array

int findPivot(vector<int> &nums)
{
    int start = 0, end = nums.size() - 1;
    int mid = (end - start) / 2 + start;
    while (start < end)
    {
        if (nums[mid] >= nums[0])
            start = mid + 1;
        else
            end = mid;

        mid = (end - start) / 2 + start;
    }
    return start;
}
int binarySearch(vector<int> &nums, int start, int end, int k)
{
    int mid = (end - start) / 2 + start;
    while (start <= end)
    {
        if (nums[mid] == k)
            return mid;
        else if (nums[mid] > k)
            end = mid - 1;
        else
            start = mid + 1;

        mid = (end - start) / 2 + start;
    }
    return -1;
}
int search(vector<int> &nums, int k)
{
    int pivot = findPivot(nums);                            // find pivot first then acc to that search
    int ans = -1;
    if(k >= nums[pivot] && k <= nums[nums.size()-1])
    ans = binarySearch(nums, pivot, nums.size()-1, k);
    else
    ans = binarySearch(nums, 0, pivot-1, k);
    return ans;
}
int main(){
    vector<int> nums={7, 9, 1, 2, 3, 4};
    cout<<search(nums, 9);
    return 0;
}