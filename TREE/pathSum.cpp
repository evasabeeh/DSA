#include<bits/stdc++.h>
using namespace std;

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
bool summ(struct Node* root, int sum, int target){
    if(root==nullptr)
    return false;
    if(root->left==nullptr&&root->right==nullptr){
        sum=sum+root->val;
        if(sum==target)
        return true;
    }
    return summ(root->left, sum+root->val, target)||summ(root->right, sum+root->val, target);
}
void hasPathSum(struct Node* root, int targetSum) {      //adding all values from root to leaf == targetsum
    cout<<summ(root, 0, targetSum);
}
void inOrder(Node* root){
   if(root!=NULL){
      inOrder(root->left);
      cout<<root->val<<" ";
      inOrder(root->right);
   }
}

int main(){
    root=insert(root, 3);
    root=insert(root, 1);
    root=insert(root, 2);
    inOrder(root);
    hasPathSum(root, 5);
    return 0;
}