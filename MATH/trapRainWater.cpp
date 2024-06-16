#include<bits/stdc++.h>
using namespace std;            //Trapping Rain Water
                                //an elevation map where the width of each bar is 1, compute how much water it can trap after raining
class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int> left(n, 0);
        vector<int> right(n, 0);

        int mx=0, my=0;
        for(int i=0, j=n-1;i<n && j>=0;i++, j--){    //to store prefix and postfix max heights for each bar 
                                                     //prefix: till the ith index and postfix: from ith index till last
            mx=max(mx, height[i]);
            my=max(my, height[j]);
            left[i]=mx;
            right[j]=my;
        }

        int ans=0;
        for(int i=0;i<n;i++)
        ans+=(min(left[i], right[i])-height[i]);

        return ans;
    }
};
int main(){
    Solution s;
    vector<int> height={0,1,0,2,1,0,1,3,2,1,2,1};
    cout<<s.trap(height);
}

//O(n)


