#include<bits/stdc++.h>
using namespace std;                 // final health points after collision

class Solution
{
public:
    vector<int> survivedRobotsHealths(vector<int> &positions vector<int> &healths, string directions)
    {
        int n = positions.size();
        vector<int> id;

        for (int i = 0; i < n; i++)
            id.push_back(i);

        auto compare = [&](int id1, int id2)
        {
            return positions[id1] <= positions[id2];
        };
        sort(id.begin(), id.end(), compare);

        stack<int> stk;
        for (int i : id)
        {
            if (directions[i] == 'R')
                stk.push(i);
            else
            {
                while (!stk.empty() && healths[i] > 0)
                {
                    if (healths[i] < healths[stk.top()])
                    {
                        healths[i] = 0;
                        healths[stk.top()]--;
                    }
                    else if (healths[i] > healths[stk.top()])
                    {
                        healths[i]--;
                        healths[stk.top()] = 0;
                        stk.pop();
                    }
                    else
                    {
                        healths[i] = 0;
                        healths[stk.top()] = 0;
                        stk.pop();
                    }
                }
            }
        }
        vector<int> ans;
        for (int h : healths)
        {
            if (h > 0)
                ans.push_back(h);
        }

        return ans;
    }
};

int main(){
    vector<int> positions = {3, 5, 2, 6};
    vector<int> healths = {10, 10, 15, 12};
    vector<char> directions = {'R', 'L', 'R', 'L'};

    Solution s;
    cout << s.survivedRobotsHealths(positions, healths, directions);

    return 0;
}

// https://leetcode.com/problems/robot-collisions/