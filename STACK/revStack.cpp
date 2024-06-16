#include<bits/stdc++.h>
using namespace std;                   //recursion approach

void insertBottom(int a, stack<int> &stk){       //insert element to the bottom of stack
    if(stk.empty()){
        stk.push(a);
    }
    else{
        int peek=stk.top();
        stk.pop();
        insertBottom(a, stk);
        
        stk.push(peek);
    }
}
void reverse(stack<int> &stk){
    if(!stk.empty()){
        int a=stk.top();
        stk.pop();
        
        reverse(stk);
        insertBottom(a, stk);
    }
}

int main(){
    stack<int> stk;
    for(int i=6;i>=1;i--)         //original stack=1 2 3 4 5 6 
    stk.push(i);

    reverse(stk);

    while(!stk.empty()){
        cout<<stk.top()<<" ";
        stk.pop();
    }
    return 0;
}