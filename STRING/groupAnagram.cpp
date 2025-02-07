// https://leetcode.com/problems/group-anagrams/

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        map<string, vector<string>> mp;
        for (string s : strs)
        {
            string str = s;
            sort(str.begin(), str.end()); // sort word and then map
            mp[str].push_back(s);
        }
        vector<vector<string>> ans;
        for (auto v : mp)
            ans.push_back(v.second);

        return ans;
    }
};