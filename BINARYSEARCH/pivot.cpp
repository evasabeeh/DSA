#include <bits/stdc++.h>
using namespace std;                        //find pivot index in sorted rotated array
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

int main()
{
    vector<int> nums = {7, 9, 1, 2, 3};
    cout << findPivot(nums);
    return 0;
}
