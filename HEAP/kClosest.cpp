// https://www.geeksforgeeks.org/find-k-closest-elements-given-value/


class Solution
{
public:
    vector<int> printKClosest(vector<int> arr, int n, int k, int x)
    {
        priority_queue<vector<int>> pq;
        
        for (int i = 0; i < n; i++)
        {
            if (arr[i] == x)
                continue;

            int sum = abs(arr[i] - x);

            if (pq.size() < k)
                pq.push({sum, -1 * arr[i]});              // -1 so that always greater value is preferred
            else if (sum < pq.top()[0])
            {
                pq.pop();
                pq.push({sum, -1 * arr[i]});
            }
        }
        vector<int> ans;
        while (!pq.empty())
        {
            ans.push_back(-1 * pq.top()[1]);
            pq.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
