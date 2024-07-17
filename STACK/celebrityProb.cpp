#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to find if there is a celebrity in the party or not.
    bool know(vector<vector<int>> &M, int a, int b)
    {
        if (M[a][b])
            return true;

        return false;
    }
    int celebrity(vector<vector<int>> &M, int N)
    {
        stack<int> stk;
        for (int i = 0; i < N; i++)
            stk.push(i);

        while (stk.size() > 1)
        {
            int a = stk.top();
            stk.pop();
            int b = stk.top();
            stk.pop();

            if (know(M, a, b))
                stk.push(b);
            else
                stk.push(a);
        }

        int cand = stk.top();

        int zeroCount = 0, oneCount = 0;
        for (int i = 0; i < N; i++)
        {
            if (M[cand][i] == 0)
                zeroCount++;

            if (M[i][cand] == 1)
                oneCount++;
        }

        if (oneCount == N - 1 && zeroCount == N) // N-1 because diagnol elements are ignored
            return cand;

        return -1;
    }
};

int main()
{
    vector<vector<int>> M = {{0 1 0},
                             {0 0 0},
                            {0 1 0}};

    Solution ob;
    cout << ob.celebrity(M, 3);
}