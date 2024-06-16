#include<bits/stdc++.h>
using namespace std;

int main(){
    char arr[]={'2','3','1','*','+','9','-'};
    stack<int> stk;

    for(char i:arr){
        if(i>=48&&i<=57){          //if operand, push into stack
            i-=48;
            stk.push(i);
        }
        else{                      //if operator, pop ttwo elements from stack and apply operation on it
            int a=stk.top();
            stk.pop();
            int b=stk.top();
            stk.pop();
            int c=0;
            if(i=='+'){
                c=a+b;
            }
            else if(i=='-'){
                c=b-a;
            }
            else if(i=='*'){
                c=a*b;
            }
            else if(i=='/'){
                c=b/a;
            }
            stk.push(c);
        }
    }
    cout<<stk.top()<<endl;
    return 0;
}