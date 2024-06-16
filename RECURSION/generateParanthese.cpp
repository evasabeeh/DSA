#include<bits/stdc++.h>
using namespace std;                          //Generate all combinations of n pair of paranthese

class Solution {
public:
    vector<string> ans;
    void solve(int open, int close, int n, string s){     //open: count of opening brackets
        if(open==n&&close==n){                //complete pairs
            ans.push_back(s);
            return;
        }
        if(open<n){
            s.push_back('(');
            solve(open+1, close, n, s);
            s.pop_back();
        }
        if(close<open && close<n){                     //open = close
            s.push_back(')');
            solve(open, close+1, n, s);
            s.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        solve(0, 0, n, "");
        return ans;
    }
};
int main(){
    Solution obj;
    vector<string> t=obj.generateParenthesis(3);
    for(string s: t)
    cout<<s<<" ";
}