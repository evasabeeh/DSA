#include<bits/stdc++.h>
using namespace std;

int main(){                   //increasing monotonic stack
    stack<int> stk;
    int arr[]={4, 8, 1, 90, 22, 65};

    vector<int> popped;
    
    for(int i:arr){
        if(stk.empty()){
            stk.push(i);
        }
        else{
            while(!stk.empty()&&(stk.top()<i)){
                int x=stk.top();
                stk.pop();
                popped.push_back(x);
            }
            stk.push(i);
            reverse(popped.begin(), popped.end());
            for(int i=0;i<popped.size();i++){
                stk.push(popped[i]);
            }
            popped.clear();
        }
    }
    while(!stk.empty()){
        int x=stk.top();
        stk.pop();
        cout<<x<<" ";
    }
    return 0;
}