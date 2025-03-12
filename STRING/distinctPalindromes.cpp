https : // www.geeksforgeeks.org/problems/distinct-palindromic-substrings5141/1

        class Solution
{
public:
    bool ispalindrome(string &s)
    {
        int m = 0, n = s.size() - 1;
        while (m < n)
        {
            if (s[m] != s[n])
                return false;

            m++;
            n--;
        }
        return true;
    }
    int palindromeSubStrs(string s)
    {
        set<string> ans;         // distinct palindrome substrings in a string possible
        for (int i = 0; i < s.size(); i++)
        {
            string str = "";
            for (int j = i; j < s.size(); j++)
            {
                str += s[j];
                if (ispalindrome(str))
                    ans.insert(str);
            }
        }
        return ans.size();
    }
};