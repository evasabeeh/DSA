class Solution
{
public:
    int getSum(int a, int b)
    {
        while (b != 0)
        {
            int sum = a ^ b;
            int carry = a & b;
            carry = carry << 1;

            a = sum;
            b = carry;
        }
    }
};

// https://leetcode.com/problems/sum-of-two-integers/