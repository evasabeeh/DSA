#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int largestRectangleArea(vector<int> &h)
    {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        int n = h.size();
        stack<int> stk;                        // monotonic stacks
        vector<int> left(n, -1), right(n, -1); // next smaller element to left and right respectively using stacks

        stk.push(-1);
        for (int i = n - 1; i >= 0; i--)
        {
            while (!stk.empty() && stk.top() != -1 && h[stk.top()] >= h[i])
                stk.pop();
            right[i] = stk.top();
            stk.push(i);
        }

        stk = stack<int>();
        stk.push(-1);
        for (int i = 0; i < n; i++)
        {
            while (!stk.empty() && stk.top() != -1 && h[stk.top()] >= h[i])
                stk.pop();
            left[i] = stk.top();
            stk.push(i);
        }

        int mx = 0;
        for (int i = 0; i < n; i++)
        {
            int breadth = 0;
            if (right[i] == -1)
                breadth = (n - 1) - left[i];
            else
                breadth = right[i] - left[i] - 1;
            mx = max(mx, breadth * h[i]);
        }
        return mx;
    }
};

int main(){
    Solution s;
    vector<int> h={2,1,5,6,2,3};

    cout << s.largestRectangleArea(h);
}

// leetcode.com/problems/largest-rectangle-in-histogram/description/