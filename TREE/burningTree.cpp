class Solution
{
public:
    // create mapping from node to parent and returns start node
    Node *createMapping(Node *root, map<Node *, Node *> &mp, int target)
    {
        if (root == nullptr)
            return nullptr;

        queue<Node *> q;
        q.push(root);

        Node *start = nullptr;

        while (!q.empty())
        {
            Node *node = q.front();
            q.pop();

            if (node->data = target)
                start = node;

            if (node->left)
            {
                mp[node->left] = node;
                q.push(node->left);
            }
            if (node->right)
            {
                mp[node->right] = node;
                q.push(node->right);
            }
        }
        return start;
    }
    
    int minTime(Node *root, int target)
    {
        map<Node *, Node *> mp;
        Node *start = createMapping(root, mp, target);

        int time = 0;

        queue<Node *> q;
        map<Node *, bool> vis;

        q.push(start);
        vis[start] = true;

        while (!q.empty())
        {
            int size = q.size();
            bool flag = false;

            while (size--)
            {
                Node *node = q.front();
                q.pop();

                if (node->left && !vis[node->left])
                {
                    flag = true;
                    q.push(node->left);
                    vis[node->left] = true;
                }
                if (node->right && !vis[node->right])
                {
                    flag = true;
                    q.push(node->right);
                    vis[node->right] = true;
                }
                if (mp[node] && !vis[mp[node]])
                { // for parent node
                    flag = true;
                    q.push(mp[node]);
                    vis[mp[node]] = true;
                }
            }
            if (flag)
                time++;
        }

        return time;
    }
};


// https://www.geeksforgeeks.org/problems/burning-tree/1