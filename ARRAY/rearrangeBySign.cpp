#include<bits/stdc++.h>
using namespace std;

int main(){                        //Rearrange elements where positive is on positive index and negatives are on odd index
                                   //no. of +ves = no. of -ves
    vector<int> nums={-1, 2, 9, 4, -5, -1, -2, -8, 4, 6};
    vector<int> ans(nums.size(), 0);
    int posIdx=0, negIdx=1;
    for(int i=0;i<nums.size();i++){
        if(nums[i]<=0){
            ans[posIdx]=nums[i];
            posIdx+=2;
        }
        else{
            ans[negIdx]=nums[i];
            negIdx+=2;
        }
    }
    for(int i: ans)
    cout<<i<<" ";
}

/*
         pos != neg
         bruter force will pe applied
*/