#include<bits/stdc++.h>
using namespace std;              //no. of permutations = n!
                                  //duplicates allowed
void permute(string s, string ans){
    if(s.length()==0){
        cout<<ans<<endl;
    }
    for(int j=0;j<s.length();j++){
        string left=s.substr(0, j);
        string right=s.substr(j+1);
        string res=left+right;
        permute(res, ans+s[j]);
    }
}
int main(){
    string s="ABC";
    string ans="";
    permute(s, ans);
    cout<<s.substr(0, 0)<<endl;
    return 0;
}                         