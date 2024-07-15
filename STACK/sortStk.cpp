#include<bits/stdc++.h>
using namespace std;
 
void stkInsertSorted(stack<int> &stk, int num)          // insert element in stack in sorted manner
{
    if (stk.empty() || stk.top() < num)
    {
        stk.push(num);
        return;
    }
    int x = stk.top();
    stk.pop();

    stkInsertSorted(stk, num);

    stk.push(x);
}
void sortStack(stack<int> &stack)
{
    if (stk.empty())
        return;

    int num = stk.top();
    stk.pop();

    sortStack(stk);

    stkInsertSorted(stk, num);
}

int main(){
    stack<int> stk={7, 9, 1, 2, 8, 5};
    sortStack(stk, 6);

    while(!stk.empty()){
        cout<<stk.top()<<" ";
        stk.pop();
    }

    return 0;
}