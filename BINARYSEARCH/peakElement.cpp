#include<bits/stdc++.h>
using namespace std;
                                                    //index of peak element in mountain array
int findPeakElement(vector<int> &nums){
    int start = 0, end = nums.size() - 1;
    int mid = (end - start) / 2 + start;
    while (start < end){
        if (nums[mid] < nums[mid + 1])
            start = mid + 1;
        else
            end = mid;

        mid = (end - start) / 2 + start;
    }
    return start;
}

int main(){
    vector<int> nums={24, 69, 100, 99, 79, 78, 67, 36, 26, 19};
    cout<<findPeakElement(nums);
    return 0;
}
