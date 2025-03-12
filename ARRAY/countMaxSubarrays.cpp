// https://www.geeksforgeeks.org/problems/count-of-subarrays5922/0

class Solution
{
public:
    // #define ll long long

    ll countSubarray(int arr[], int n, int k)
    {
        ll position = 0, ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] > k)
                position = i + 1;
            ans += position;
        }
        return ans;
    }
};