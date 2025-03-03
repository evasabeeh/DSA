// https://leetcode.com/problems/koko-eating-bananas/

class Solution
{
public:
    bool calc(vector<int> &piles, int h, int mid)
    {
        int ans = 0; // time
        for (int p : piles)
        {
            ans += (p / mid); // dist/speed

            if (p % mid)
                ans++;
        }
        return ans <= h; // if eat bananas within h hours
    }
    int minEatingSpeed(vector<int> &piles, int h)
    {
        sort(piles.begin(), piles.end());
        int start = 1, end = piles.back(); // speed

        while (start < end)
        {
            int mid = start + (end - start) / 2;

            if (calc(piles, h, mid))
                end = mid;
            else
                start = mid + 1;
        }
        return start;
    }
};