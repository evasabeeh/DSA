class Solution
{
public:
    long long trappingWater(int arr[], int n)
    {
        vector<int> left, right;

        int mx = 0, my = 0;
        for (int i = 0, j = n - 1; i < n && j >= 0; i++, j--)
        {
            mx = max(mx, arr[i]);
            my = max(my, arr[j]);
            left.push_back(mx);
            right.push_back(my);
        }
        reverse(right.begin(), right.end());

        long long ans = 0;
        for (int i = 0; i < n; i++)
            ans += (min(left[i], right[i]) - arr[i]);

        return ans;
    }
};