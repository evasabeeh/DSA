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
int sum=0;                          //store sum of right subtree
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
void inOrder(Node* root){
   if(root!=NULL){
      inOrder(root->left);
      cout<<root->data<<" ";
      inOrder(root->right);
   }
}
struct Node* sumRightBST(struct Node* root) {  //each node changes to the sum of its right subtree + its own value
    if(root!=nullptr){
        sumRightBST(root->right);
        sum+=root->data;
        root->data=sum;
        sumRightBST(root->left);
    }
    return root;
}

int main(){
   root=insert(root,56);
   root=insert(root,70);
   root=insert(root,1);
   root=insert(root,55);
   root=insert(root,100);

   root=sumRightBST(root);
   inOrder(root);
   return 0;
}