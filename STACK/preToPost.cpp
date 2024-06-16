#include<bits/stdc++.h>
using namespace std;
string preToPost(string s) {
    stack<string> stk;
    string ans;
    reverse(s.begin(), s.end());
    for(char c: s){
        if((c>=65&&c<=90)||(c>=97&&c<=122))
        stk.push(string(1, c));
        else{
            string a=stk.top();
            stk.pop();
            string b=stk.top();
            stk.pop();
            stk.push(a+b+c);
        }
    }
    ans=stk.top();
    return ans;
}
int main(){
    string str="-/A+BC*DE";
    cout<<prefixToPostfix(str);
}