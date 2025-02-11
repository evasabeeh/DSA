// https://leetcode.com/problems/remove-all-occurrences-of-a-substring/

        class Solution
{
public:
    string removeOccurrences(string s, string part)
    {
        int m = part.size();
        for (int i = 0; i < s.size(); i++)
        {
            if (part[0] == s[i] && s.substr(i, m) == part)
                return removeOccurrences(s.substr(0, i) + s.substr(i + m), part);
        }
        return s;
    }
};