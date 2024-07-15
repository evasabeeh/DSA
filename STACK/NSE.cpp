#include <bits/stdc++.h>
using namespace std;

void nextSmallerElement(vector<int> &arr, int n)
{
    stack<int> stk;
    vector<int> ans(n, -1);

    stk.push(-1);
    for (int i = n - 1; i >= 0; i--)
    {
        while (stk.top() >= arr[i])
            stk.pop();

        ans[i] = stk.top();
        stk.push(arr[i]);
    }
    
    for(int x: ans)
    cout<<x<<" ";
}

int main(){
    vector<int> arr={3, 4, 7, 3, 0, 2, 7, 4};
    nextSmallerElement(arr, 8);
}