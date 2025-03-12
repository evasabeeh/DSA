// https://leetcode.com/problems/check-if-number-is-a-sum-of-powers-of-three/description/?envType=daily-question&envId=2025-03-04

class Solution
{
public:
    bool checkPowersOfThree(int n)
    {
        vector<int> three(16, 0); // maximum 3^15 is possible since 3^16 exceeds the usual integer limit
        for (int i = 0; i < 16; i++)
            three[i] = pow(3, i);

        for (int i = 15; i >= 0; i--)
        {
            if (three[i] <= n) // checking for highest powers first and then moving to smaller powers
                n -= three[i];

            if (n == 0)
                return true;
        }
        return false;
    }
};