#include <bits/stdc++.h>                     // delete middle element of stack
using namespace std;

void solve(stack<int> &stk, int mid, int n)
{
    if (mid == 0)
    {
        stk.pop();
        return;
    }

    int num = stk.top();                   // so that after these elements can be inserted
    stk.pop();

    solve(stk, mid - 1, n);                // recursive call

    stk.push(num);
}
void deleteMiddle(stack<int> &inputStack, int N)
{
    solve(inputStack, N / 2, N);

    while(!stk.empty()){
        cout<<stk.top()<<" ";
        stk.pop();
    }
}

int main(){
    stack<int> stk={1, 2, 3, 4, 5, 6};
    deleteMiddle(stk, 6);

    return 0;
}