#include<bits/stdc++.h>
using namespace std;                            //count subarrays with at most K distinct char
int kDistinctChars(int k, string arr)
{
   int start=0, end=0, ans=0;
    map<char, int> mp;
    while(end<arr.size()){
        mp[arr[end]]++;
        
        while(mp.size()>k){
            mp[arr[start]]--;
            if(mp[arr[start]]==0)
            mp.erase(arr[start]);
            start++;
        }
        ans=max(ans, end-start+1);
        
        end++;
    }
    return ans;
}
int main(){
    cout<<kDistinctChars(2, "abbbbbbc");
    return 0;
}



// total subarrays: n*(n+1)/2