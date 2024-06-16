#include<bits/stdc++.h>
using namespace std;

int main(){                        //Kadane's Algo used to determine subarray with max product
                                   //here it is assumed that the product is never 0
    vector<int> nums={2, 3, -2, 4};

    int maxEndHere=1, maxx=INT_MIN;
    for(int i: nums){
        maxEndHere*=i;

        if(maxEndHere>maxx)
        maxx=maxEndHere;

        if(maxEndHere==0)
        maxEndHere=1;
    }

    maxEndHere=1;
    reverse(nums.begin(), nums.end());
    for(int i: nums){
        maxEndHere*=i;

        if(maxEndHere>maxx)
        maxx=maxEndHere;

        if(maxEndHere==0)
        maxEndHere=1;
    }
    cout<<maxx<<endl;

    return 0;
}