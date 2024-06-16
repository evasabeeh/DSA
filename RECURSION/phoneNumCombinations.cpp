#include<bits/stdc++.h>
using namespace std;          //all combinations of digits entered on phone
class Solution {
public:
    vector<string> ans;
    void solve(int idx, string digits, string &s, vector<string> comb){
        if(idx==digits.size()){
            ans.push_back(s);
            return;
        }
        int d=digits[idx]-'0';
        string str=comb[d];                        //corresponding digit letters in phone

        for(int i=0;i<str.length();i++){
            s.push_back(str[i]);                   //add the curr element
            solve(idx+1, digits, s, comb);         //recursively generate all combinations
            s.pop_back();                          //backtrack
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.size()==0)
        return ans;

        vector<string> comb={"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        string s="";

        solve(0, digits, s, comb);
        
        return ans;
    }
};

int main(){
    Solution obj;
    vector<string> v=obj.letterCombinations("23");
    for(string s: v)
    cout<<s<<" ";

}