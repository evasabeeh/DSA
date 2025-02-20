// https://leetcode.com/problems/container-with-most-water/

class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int maxx = 0;
        int left = 0, right = height.size() - 1;
        while (left < right)
        {
            int area = (right - left) * min(height[left], height[right]);
            maxx = max(maxx, area);

            if (height[left] < height[right])
                left++;
            else
                right--;
        }
        return maxx;
    }
};