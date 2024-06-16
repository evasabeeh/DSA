#include<bits/stdc++.h>
using namespace std;             // if there exists an increasing triplet subsequence

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        if(nums.size()<3)
        return false;

        int a=INT_MAX, b=INT_MAX;
        for(int i: nums){
            if(i<=a)               //least small will come here
            a=i;
            else if(i<=b)          // then it will come here
            b=i;
            else                   // when third will be found, subsequence is completed;
            return true;
        }
        return false;
    }
};
int main(){
    Solution s;
    vector<int> v={2,1,5,0,4,6};         // a, b, c: 0, 4, 6
    cout<<s.increasingTriplet(v);
}