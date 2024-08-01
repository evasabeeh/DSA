#include<bits/stdc++.h>
using namespace std;            //implementation of stack using queue

class MyStack
{
    queue<int> q;

public:
    MyStack() {}

    bool empty()
    {
        return q.size() == 0;
    }
    void push(int x)
    {
        if (empty())
            q.push(x);
        else
        {
            int n = q.size();
            q.push(x);

            while (n--)
            {
                q.push(q.front());
                q.pop();
            }
        }
    }
    int pop()
    {
        if (empty())
            return -1;

        int x = q.front();
        q.pop();
        return x;
    }
    int top()
    {
        if (empty())
            return -1;

        return q.front();
    }
};