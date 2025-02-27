// https://leetcode.com/problems/find-unique-binary-string

// Cantor’s Diagonalization - This approach constructs a binary string that is guaranteed to be different from all strings innumsusing Cantor’s diagonalization technique. O(n)

// it works by constructing a new number that is guaranteed to not be in a given list of numbers by systematically changing each digit on the diagonal of the list, essentially creating a number that differs from every number in the list. list is of length n only which is a length of each number also

class Solution
{
public: // Cantor’s Diagonalization
    string findDifferentBinaryString(vector<string> &nums)
    {
        string ans = "";
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i][i] == '0')
                ans += "1";
            else
                ans += "0";
        }
        return ans;
    }
};