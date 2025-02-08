#include <bits/stdc++.h>
using namespace std;
                                      //array contains  1 to n-1 elements at least once, find the element occured twice
int main()
{
    vector<int> arr={4,5,3,7,4,1,2,6};
    int ans=0;
    for(int i=0;i<arr.size()-1;i++){
        ans = ans^arr[i]^(i+1);
    }
    ans = ans^arr[arr.size()-1];                 // duplicate element will be left in ans
    cout<<ans;
}