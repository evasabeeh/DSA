#include<bits/stdc++.h>
using namespace std;                     //minimum window substring of S such that every character in T (including duplicates) is included in the window.

class Solution {
public:
    string minWindow(string s, string t) {
        int n=t.size(), m=s.size();
        if(m<n)
        return "";

        map<char, int> mp;
        for(int i=0;i<n;i++)
        mp[t[i]]++;

        int left=0, right=0, start=0, minLen=INT_MAX;
        while(right<m){
            if(mp[s[right]]>0)
            n--;

            mp[s[right]]--;

            while(n==0){
                int len=right-left+1;
                if(len<minLen){
                    minLen=len;
                    start=left;
                }
                mp[s[left]]++;
                if(mp[s[left]]>0)
                n++;
                left++;
            }
            right++;
        }
        if(minLen==INT_MAX)
        return "";
        
        return s.substr(start, minLen);
    }
};
int main(){
    Solution obj;
    cout<<obj.minWindow("ADOBECODEBANC", "ABC");
}