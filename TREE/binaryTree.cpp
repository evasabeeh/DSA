#include<bits/stdc++.h>             //Binary Tree
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

void insert(struct Node* temp, int data){
   Node* newNode=new Node(data);    //new data inserted

   if(root==NULL){                  //tree is empty
      root=newNode;
      return;
   }

   
}
void inOrder(Node* root){
   if(root!=NULL){
      inOrder(root->left);
      cout<<root->data<<" ";
      inOrder(root->right);
   }
}

int maxDepth(TreeNode* root) {        //height of tree
   if(root==NULL)
   return 0;
        
   int count1=maxDepth(root->left)+1;
   int count2=maxDepth(root->right)+1;

   return max(count1, count2);
}
bool isBalanced(TreeNode* root) {     //to check if tree is height balanced or not
   if(root==nullptr)
   return true;

   int l=maxDepth(root->left);
   int r=maxDepth(root->right);

   if(abs(l-r)<=1 && isBalanced(root->left) && isBalanced(root->right))
   return true;

   return false;
}
int diameter(TreeNode* root, int &ans){    //diameter of tree
   if(root==nullptr)
   return 0;

   int left=diameter(root->left);       //left subtree
   int right=diameter(root->right);     //right subtree

   ans=max(ans, left+right);
   return 1+max(left, right);
}
int main(){
   insert(root,56);
   insert(root,70);
   insert(root,1);
   insert(root,55);
   insert(root,100);

   inOrder(root);
   return 0;
}