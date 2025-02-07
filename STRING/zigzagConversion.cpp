// https://leetcode.com/problems/zigzag-conversion/

class Solution
{
public:
    string convert(string s, int numRows)
    {
        if (numRows == 1)
            return s;

        vector<string> zigzag(numRows, "");
        int currLine = 0;
        bool reachedEdge = false;

        for (char c : s)
        {
            if (currLine == 0 || currLine == numRows - 1)
                reachedEdge = !reachedEdge;

            zigzag[currLine] += c;

            if (reachedEdge)
                currLine++;
            else
                currLine--;
        }

        string ans = "";
        for (string s : zigzag)
            ans += s;

        return ans;
    }
};