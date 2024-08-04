
class Solution
{
public:
    int kthLargest(vector<int> &arr, int N, int K)
    {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 0; i < N; i++)
        {
            int sum = 0;
            for (int j = i; j < N; j++)
            {
                sum += arr[j];

                if (pq.size() < K)
                    pq.push(sum);
                else if (sum > pq.top())
                {
                    pq.pop();
                    pq.push(sum);
                }
            }
        }
        return pq.top();
    }
};

// https://www.geeksforgeeks.org/problems/k-th-largest-sum-contiguous-subarray/1