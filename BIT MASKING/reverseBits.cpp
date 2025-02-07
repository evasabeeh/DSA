class Solution
{
public:
    uint32_t reverseBits(uint32_t n)
    {
        uint32_t ans = 0;
        for (int i = 0; i < 32; i++)    // 32 bits are there in a number that is why
        {
            int bit = n & 1; // normal bit checking
            n = n >> 1;

            ans = (ans << 1) | bit; // reverse bit
        }
        return ans;
    }
};

// https://leetcode.com/problems/reverse-bits/