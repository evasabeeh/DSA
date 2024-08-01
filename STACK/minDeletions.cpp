// https://leetcode.com/problems/minimum-deletions-to-make-string-balanced/

class Solution
{
public:
    int minimumDeletions(string s)
    {
        stack<char> stk;
        int count = 0;
        stk.push(s[0]);

        for (int i = 1; i < s.size(); i++)
        {
            if (!stk.empty() && (stk.top() == 'b' && s[i] == 'a'))
            {
                stk.pop(); // a can't be after b so we need to pop out
                count++;
            }
            else
                stk.push(s[i]); // else keep on adding
        }
        return count;
    }
};