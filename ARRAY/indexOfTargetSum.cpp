// find two indices which sum up to target

#include<bits/stdc++.h>
using namespace std;

int main(){                       
    vector<int> nums={2, 3, -2, 4, 6, 1, 0};
    sort(nums.begin(), nums.end());
    int target=7
    int i=0, j=nums.size()-1;
    while(i<j){
        int x=nums[i]+nums[j];
        if(x==target)
        break;
        else if(x<target)
        i++;
        else
        j--;
    }

    cout<<i<<" "<<j<<endl;
    return 0;
}