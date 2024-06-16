#include<bits/stdc++.h>
using namespace std;
                                   //lowest common ancestor
struct Node
{
   int val;
   struct Node *left;
   struct Node *right;

   Node(int val){
   this->val=val;
   this->left=NULL;
   this->right=NULL;
   }
};

struct Node* root=NULL;             //BST initialisation

struct Node* insert(struct Node* root, int val){
   Node* newNode=new Node(val);    //new data inserted

   if(root==NULL){                  //tree is empty
      root=newNode;
      return root;
   }

   if(val<root->val){
       root->left=insert(root->left, val);
   }
   else
   root->right=insert(root->right, val);
   
   return root;
}
bool dfs(Node* root, Node* node, vector<Node*> &path){      //path from root to node
    if(!root)
    return false;

    path.push_back(root);

    if(root==node)
    return true;

    if(dfs(root->left, node, path)||dfs(root->right, node, path))
    return true;

    path.pop_back();
    return false;
}
Node* lca(Node* root, Node* p, Node* q) {    //lowest common ancestor
    vector<TreeNode*> pp;
    vector<TreeNode*> qq;
    dfs(root, p, pp);
    dfs(root, q, qq);

    int i=pp.size()-1;
    while(i>=0){
        if(find(qq.begin(), qq.end(), pp[i])!=qq.end())
        return pp[i]->val;
        i--;
    }
    return -1;
}
int main(){
    root=insert(root, 3);
    root=insert(root, 5);
    root=insert(root, 1);
    root=insert(root, 6);
    root=insert(root, 2);
    root=insert(root, 0);
    root=insert(root, 8);
    root=insert(root, 7);
    root=insert(root, 4);
    cout<<lca(root);
    return 0;
}