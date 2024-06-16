#include<bits/stdc++.h>
using namespace std;

int main(){                        //Kadane's Algo used to determine subarray with max sum; print that max subarray too
                                   //here it is assumed that the sum is a positive sum value, ie, sum is never negative
    vector<int> nums={-1, 2, 9, 4, -5, -8, 4, 6};
    int currSum=0, maxx=INT_MIN;
    int start=-1, end=-1, idx=-1;

    for(int i=0;i<nums.size();i++){
        if(currSum==0)
        idx=i;

        currSum+=nums[i];

        if(currSum>maxx){
            maxx=currSum;
            start=idx;
            end=i;
        }

        if(currSum<0)
        currSum=0;
    }
    cout<<maxx<<" "<<start<<" "<<end;
}