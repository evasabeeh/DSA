#include<bits/stdc++.h>
using namespace std;    

void printSub(int i, string str, string &ans){
    if(i>=str.size() && ans.size()>0){
        cout<<ans<<endl;
        return;
    }

    // include
    ans.push_back(str[i]);
    printSub(i+1, str, ans);

    //exclude
    ans.pop_back();
    printSub(i+1, str, ans);
}
int main(){
    string str="abc", ans="";
    printSub(0, str, ans);
}