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
vector<Node*> vec;           //store inorder of BST
struct Node* balance(int start, int end){
    if(start>end)
    return NULL;
        
    int mid=(start+end)/2;                       //mid element is made parent and then further left and right subtree
    struct Node* root=vec[mid];
    root->left=balance(start, mid-1);
    root->right=balance(mid+1, end);
        
    return root;
}
struct Node* balanceBST(struct Node* root) {        //balance tree so that left subtree and right subtree height is max differ by 1
    return balance(0, vec.size()-1);
}
void inOrder(Node* root){    //inOrder in BST always gives ascending order or sorted form
   if(root!=NULL){
      inOrder(root->left);
      cout<<root->data<<" ";
      vec.push_back(root);
      inOrder(root->right);
   }
}
void preOrder(Node* root){
   if(root!=NULL){
      cout<<root->data<<" ";
      preOrder(root->left);
      preOrder(root->right);
   }
}
int main(){
   root=insert(root, 1);
   root=insert(root, 2);
   root=insert(root, 3);
   root=insert(root, 4);
   
   inOrder(root);
   cout<<endl;
   preOrder(root);
   cout<<endl;
   root=balanceBST(root);
   preOrder(root);
   return 0;
}