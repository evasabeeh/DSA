#include <bits/stdc++.h>
using namespace std; // remove all adjacent duplicates: addacb -> aacb -> cb
int main()
{
    string str = "addacb", n=6;
    string ans="";
    for(char c: str){
        if(ans.size() && ans.back()==c)
        ans.pop_back();
        else
        ans.push_back(c);
    }
    cout<<ans;
}