// https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/

class Solution
{
public:
    // Function to find the vertical order traversal of Binary Tree.        based on number line concept
    vector<int> verticalOrder(Node *root)
    {
        // Horizontal dist, level, values
        map<int, map<int, vector<int>>> mp;
        // node, Horiontal dist, level
        queue<pair<Node *, pair<int, int>>> q;
        vector<int> ans;

        if (root == nullptr)
            return ans;

        q.push(make_pair(root, make_pair(0, 0)));
        while (!q.empty())
        {
            Node *node = q.front().first;
            int hd = q.front().second.first, level = q.front().second.second;
            q.pop();

            mp[hd][level].push_back(node->data);

            if (node->left)
                q.push(make_pair(node->left, make_pair(hd - 1, level + 1)));
            if (node->right)
                q.push(make_pair(node->right, make_pair(hd + 1, level + 1)));
        }

        for (auto m : mp)
        {
            for (auto i : m.second)
            {
                for (int val : i.second)
                    ans.push_back(val);
            }
        }
        return ans;
    }
};
