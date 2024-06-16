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
struct Node* bstFromPreorder(vector<int>& preorder) {         //preorder to BST
    struct Node* root=new Node(preorder[0]);                  //first element is made to be root

    if(preorder.size()==1)
    return root;

    for(int i=1;i<preorder.size();i++){
        root=insert(root, preorder[i]);
    }
    return root;
}
/*struct Node* bstFromInorder(vector<int>& inorder) {         //inorder to BST
    
    return root;
}*/
void preOrder(Node* root){
   if(root!=NULL){
      cout<<root->data<<" ";
      preOrder(root->left);
      preOrder(root->right);
   }
}
void postOrder(Node* root){
   if(root!=NULL){
      postOrder(root->left);
      postOrder(root->right);
      cout<<root->data<<" ";
   }
}
void inOrder(Node* root){    //inOrder in BST always gives ascending order
   if(root!=NULL){
      inOrder(root->left);
      cout<<root->data<<" ";
      inOrder(root->right);
   }
}

int main(){
   vector<int> preorder{8,5,1,7,10,12};
   root=bstFromPreorder(preorder);
   preOrder(root);
   vector<int> postorder{};
   /*vector<int> inorder{};
   root=bstFromInorder(inorder);
   inOrder(root);*/
   return 0;
}