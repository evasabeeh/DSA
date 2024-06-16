#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int> arr={5, 2, 1, 2, 6, 7, 8, 0};
    int n=8;
    vector<int> ans(n, -1);
    stack<int> stk;

    for(int i=n-1;i>=0;i--){
        while(!stk.empty()){
            if(arr[i]<stk.top()){
                ans[i]=stk.top();
                break;
            }
            stk.pop();
        }
        stk.push(arr[i]);
    }
    for(int i: ans)
    cout<<i<<" ";
    return 0;
}