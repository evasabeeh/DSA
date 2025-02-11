// https://leetcode.com/problems/ipo/

class Solution
{
public:
    int findMaximizedCapital(int k, int w, vector<int> &profits, vector<int> &capital)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> projects; // min heap - sorted capital, profit
        for (int i = 0; i < profits.size(); i++)
            projects.push(make_pair(capital[i], profits[i]));

        priority_queue<int> maxProfits; // max heap for profits
        while (k--)      // only k projects can be taken
        {
            while (!projects.empty() && projects.top().first <= w)
            {
                maxProfits.push(projects.top().second);
                projects.pop();
            }

            if (maxProfits.empty()) // no project can be taken
                return w;

            w += maxProfits.top();
            maxProfits.pop();
        }
        return w;
    }
};