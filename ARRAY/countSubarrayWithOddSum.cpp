// https://leetcode.com/problems/number-of-sub-arrays-with-odd-sum/

class Solution
{
public:
    int numOfSubarrays(vector<int> &arr)
    {
        int odd = 0, even = 1, sum = 0, count = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            sum += arr[i];

            if (sum % 2 == 1)
            { // even + odd = odd
                count = (count + even) % 1000000007;
                odd++;
            }
            else
            { // odd + odd && even + even = even
                count = (count + odd) % 1000000007;
                even++;
            }
        }
        return count;
    }
};