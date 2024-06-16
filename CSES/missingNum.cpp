                                       //find missing number
#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int> nums={1, 0, 3};

    int xor1=0, n=nums.size();

    for(int i=0;i<n;i++)
    xor1=xor1^nums[i]^i;

    xor1=xor1^n;           // for highest no. n

    cout<<xor1;

    return 0;
}


// xor of same numbers = 0
// xor of 0 and n = n