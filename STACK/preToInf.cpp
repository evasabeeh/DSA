#include<bits/stdc++.h>
using namespace std;
string prefixToInfixConversion(string &s){
	string res="";
	reverse(s.begin(), s.end());
    stack<string> stk;
	
	for(char c: s){
        if((c>=48&&c<=57)||(c>=65&&c<=90)||(c>=97&&c<=122)){    //if operand, add to exp
            stk.push(string(1, c));
        }
        else{              //if operator, add to stack
            string a=stk.top();
			stk.pop();
			string b=stk.top();
			stk.pop();
            stk.push("("+a+c+b+")");
        }
    }
	res=stk.top();
	return res;
}
int main(){
    string str="*-a/bc-/dkl";
    cout<<prefixToInfixConversion(str);
}
