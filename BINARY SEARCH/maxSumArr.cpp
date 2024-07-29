class Solution
{
public:
    bool check(int n, int i, int mx, int mid)
    {
        long long right = n - i - 1,
                  left = i;                   // number of elements to right of given index and left of given index
        
        long long sum = 0;
        sum += mid;

        if (sum > mx)
            return false;

        // for right side
        if (mid - right > 0)
        {                                                 // means there are inc values to right
            sum += (mid - 1) * mid / 2;                   // sum of inc values till mid
            sum -= (mid - right - 1) * (mid - right) / 2; // - sum inc values till mid-right
        }
        else
        { // means no inc values
            sum += right - mid + 1;
            sum += (mid - 1) * mid / 2;
        }

        // for left side
        if (mid - left > 0)
        {
            sum += (mid - 1) * mid / 2;
            sum -= (mid - left - 1) * (mid - left) / 2;
        }
        else
        {
            sum += left - mid + 1;
            sum += (mid - 1) * mid / 2;
        }

        return sum <= mx;
    }

    int maxValue(int n, int index, int maxSum)
    {
        int low = 1, high = maxSum;
        int ans = 1;

        while (low <= high)
        {
            int mid = (high - low) / 2 + low;

            if (check(n, index, maxSum, mid))
            {
                ans = mid;
                low = mid + 1;
            }
            else
                high = mid - 1;
        }
        return ans;
    }
};

// https://leetcode.com/problems/maximum-value-at-a-given-index-in-a-bounded-array/description/