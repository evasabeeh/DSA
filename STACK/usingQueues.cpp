#include<bits/stdc++.h>
using namespace std;            //implementation of stack using queue

class Stack {
	queue<int> q;

public:
    Stack() {}

    int getSize() {
        return q.size();
    }
    bool isEmpty() {
        return q.empty();
    }
    void push(int x) {
        if(isEmpty())
        q.push(x);
        else{
            int n=q.size();
            q.push(x);

            while(n--){
                q.push(q.front());
                q.pop();
            }
        }
    }
    int pop() {
        if(isEmpty())
        return -1;

        int x=q.front();
        q.pop();
        return x;
    }
    int top() {
        if(isEmpty())
        return -1;

        return q.front();
    }
};