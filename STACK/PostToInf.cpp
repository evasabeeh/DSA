#include<bits/stdc++.h>
using namespace std;
int main(){
    string post="ab*c+";
    stack<string> stk;
    for(int i=0;post[i]!='\0';i++){
        char c=post[i];
        if((c>=65&&c<=90)||(c>=97&&c<=122)){    //if operand, push into stack
            string m;                           //conversion for single char to string
            m+=c;
            stk.push(m);
        }
        else{                                   //if operator, pop two values, and add like (a+b)
            string a=stk.top();
            stk.pop();
            string b=stk.top();
            stk.pop();
            string str="("+b+c+a+")";
            stk.push(str);
        }
    }
    cout<<stk.top()<<endl;
    return 0;
}