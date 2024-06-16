#include<bits/stdc++.h>
using namespace std;
int main(){
    char arr[]={'A','*','(','B','+','C',')','/','D'};
    string post="";
    stack<char> stk;
    for(int i=0;i<9;i++){
        char c=arr[i];
        if(c>=65&&c<=90){    //if operand, add to exp
            post+=c;
        }
        else if(c=='('){
            stk.push('(');
        }
        else if(c==')'){
            while(!stk.empty()&&stk.top()!='('){
                int x=stk.top();
                stk.pop();
                post+=x;
            }
            if(stk.top()=='(')
            stk.pop();
        }
        else{              //if operator, add to stack
            stk.push(c);
        }
    }
    while(!stk.empty()){
        int x=stk.top();
        stk.pop();
        post+=x;
    }
    cout<<post<<endl;
    return 0;
}