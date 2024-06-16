#include<bits/stdc++.h>
using namespace std;               //delete k digits and make minimal number that could be made

class Solution {
public:
    string removeKdigits(string num, int k) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        if(k==0)
        return num;
        if(num.size()<=k)
        return "0";

        string stk;          //create increasing monotonic stack till k>0, after that all chars will be added that are left more
        stk.push_back(num[0]);
        for(int i=1;i<num.size();i++){
            while(!stk.empty() && num[i]<stk.back() && k>0){
                stk.pop_back();
                k--;
            }
            if(num[i]=='0'&&stk.empty())     //so that number don't start with 0
            continue;
            stk.push_back(num[i]);
        }
        
        //if more k is left to be deleted
        while(!stk.empty() && k>0){
            stk.pop_back();
            k--;
        }
        if(stk.empty())
        return "0";
        
        return stk;
    }
};
int main(){
    Solution s;
    cout<<s.removeKdigits("1432219", 3);
}