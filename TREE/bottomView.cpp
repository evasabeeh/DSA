// same as top view
// the map can override value

class Solution
{
public:

    vector<int> bottomView(Node *root)
    {
        map<int, int> mp; // horizontal distance, value
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
