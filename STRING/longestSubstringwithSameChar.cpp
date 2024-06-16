                                       // longest substring with repeating chars when you can replace 'k' char
                                       // AAAABCBCA   => AAAAAABCA when k=2
#include<bits/stdc++.h>
using namespace std;

int characterReplacement(string s, int k) {
    int start=0, end=0, n=s.size(), mx=0;
    int maxFreq=0;                              //store max freq of any repeating char in the current window
    map<char, int> mp;

    while(end<n){
        mp[s[end]]++;
        maxFreq=max(maxFreq, mp[s[end]]);

        if((end-start+1-maxFreq)>k){
            mp[s[start]]--;
            start++;
        }
        mx=max(mx, end-start+1);

        end++;
    }
    return mx;
}

int main(){

    cout<<characterReplacement("ABABCBCA", 2);

    return 0;
}