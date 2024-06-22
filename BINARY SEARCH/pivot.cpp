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



/* check if array is sorted and rotated

int count=0;
for(int i=1;i<n;i++){
if(arr[i]<arr[i-1])
count++;
}
if(arr[n-1]>arr[0])
count++;

return count<=1;
*/