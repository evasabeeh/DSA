class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        if (s.size() != t.size())
            return false;

        map<char, char> mp1, mp2; // mp1 : mapping from s to t and mp2 : mapping from t to s
        for (int i = 0; i < s.size(); i++)
        {
            if (mp1.find(s[i]) != mp1.end())
            {
                if (mp1[s[i]] != t[i]) // mapping already done with some other char then false
                    return false;
            }
            else // make mapping when no mapiing is done
                mp1[s[i]] = t[i];

            if (mp2.find(t[i]) != mp2.end())
            {
                if (mp2[t[i]] != s[i])
                    return false;
            }
            else
                mp2[t[i]] = s[i];
        }
        return true;
    }
};

// https://leetcode.com/problems/isomorphic-strings/