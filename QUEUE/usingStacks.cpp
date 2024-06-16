#include<bits/stdc++.h>
using namespace std;           //Implement queues using two stacks

class MyQueue {
public:
    stack<int> stk;          //main stack
    stack<int> temp;         //temp stack
    MyQueue() {}
    void push(int x) {
        while(!stk.empty()){
            temp.push(stk.top());
            stk.pop();
        }
        stk.push(x);
        while(!temp.empty()){
            stk.push(temp.top());
            temp.pop();
        }
    }
    int pop() {
        if(stk.empty())
        return -1;

        int x=stk.top();
        stk.pop();
        return x;
    }
    int peek() {
        if(stk.empty())
        return -1;

        return stk.top();
    }
    bool empty() {
        return stk.empty();
    }
};
int main(){
    MyQueue q;
}