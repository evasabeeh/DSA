#include<bits/stdc++.h>             //Binary Search Tree
using namespace std;

struct Node
{
   int data;
   struct Node *left;
   struct Node *right;

   Node(int data){
   this->data=data;
   this->left=NULL;
   this->right=NULL;
   }
};

struct Node* root=NULL;             //tree initialisation

struct Node* insert(struct Node* root, int data){
   Node* newNode=new Node(data);    //new data inserted

   if(root==NULL){                  //tree is empty
      root=newNode;
      return root;
   }

   if(data<root->data){
       root->left=insert(root->left, data);
   }
   else
   root->right=insert(root->right, data);
   
   return root;
}
void flatten(Node* root){                    //flatten tree into list in preorder
    if(!root)
    return;

    TreeNode* orgRoot=root->right;           //store original right subtree;
    root->right=root->left;
    root->left=NULL;

    TreeNode* temp=root->right;
    while(temp->right){
        temp=temp->right;
    }
    temp->right=orgRoot;

    flatten(root->right);
}

int main(){
   root=insert(root, 1);
   root=insert(root, 4);
   root=insert(root, 2);
   root=insert(root, 3);

   dfs(root);

   return 0;
}