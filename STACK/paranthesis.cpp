#include<bits/stdc++.h>
using namespace std;
int main(){
    string x=")";
    stack<char>stk;

    int flag=0;
    for(int i;x[i]!='\0';i++){
        char c=x[i];
        if(c=='('||c=='{'||c=='['){
                stk.push(c);
        }
        else if(!stk.empty()){
            if(c==')'&&stk.top()=='(')
            stk.pop();
            else if(c==']'&&stk.top()=='[')
            stk.pop();
            else if(c=='}'&&stk.top()=='{')
            stk.pop();
            else{
                flag==1;
                break;
            }
        }
        else{
            flag=1;
            break;
        }
    }

    if(stk.empty()&&flag==0)
    cout<<"Balanced"<<endl;
    else
    cout<<"Imbalanced"<<endl;
    return 0;
}