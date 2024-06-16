#include<bits/stdc++.h>                        //sliding window
using namespace std;

void maxSum(vector<int> nums, int k){          //print max_sum of k length 
    int sum=0, maxx=INT_MIN;

    for(int i=0;i<k;i++){
        sum+=nums[i];
    }
    maxx=sum;

    for(int i=k;i<nums.size();i++){
        sum+=nums[i]-nums[i-k];                //window slides: removing first element; adding next element
        maxx=max(maxx, sum);
    }
    cout<<maxx<<endl;
}

int main(){
    vector<int> vec{6, 2, -1, 9, 2, 11, -4};
    int k=3;
    maxSum(vec, k);
    return 0;
}