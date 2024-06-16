#include<bits/stdc++.h>
using namespace std;
string postfixToPrefix(string &s){
    stack<string> stk;
    string ans;
    for(char c: s){
        if((c>=65&&c<=90)||(c>=97&&c<=122))
        stk.push(string(1, c));
        else{
            string a=stk.top();
            stk.pop();
            string b=stk.top();
            stk.pop();
            stk.push(c+b+a);
        }
    }
    ans=stk.top();
    return ans;
}
int main(){
    string str="ab+cd-*";
    cout<<postfixToPrefix(str);
}