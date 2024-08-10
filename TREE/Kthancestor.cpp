int ans=-1;
bool flag=false;           // to determine we have reached node
void solve(Node* root, int k, int node){
    if(root==nullptr)
    return;

    if(root->data == node){
        flag=true;
        return;
    }

    if(!flag)
    solve(root->left, k, node);
    if(!flag)
    solve(root->right, k, node);

    if(flag) {       // if found
        k--;

        if(k==0)         // as soon as we found k nodes... kth anscestor is found
        ans = root->data;
    }
}

// https://www.geeksforgeeks.org/kth-ancestor-node-binary-tree/