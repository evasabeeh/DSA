
class Solution
{
public:
    // Function to return a list of nodes visible from the top view
    // from left to right in Binary Tree.

    vector<int> topView(Node *root)
    {
        map<int, int> mp;                        // horizontal distance, value
        queue<pair<Node *, int>> q;
        vector<int> ans;

        if (root == nullptr)
            return ans;

        q.push({root, 0});
        while (!q.empty())
        {
            Node *node = q.front().first;
            int hd = q.front().second;
            q.pop();

            if (mp.find(hd) == mp.end())            // if horizontal dist is already present and because it is travelling top to bottom, first top node will be visible so map value should be not overrided that is why if value does not exist in map then only insert into map
                mp[hd] = node->data;

            if (node->left)
                q.push({node->left, hd - 1});
            if (node->right)
                q.push({node->right, hd + 1});
        }

        for (auto m : mp)
            ans.push_back(m.second);

        return ans;
    }
};
