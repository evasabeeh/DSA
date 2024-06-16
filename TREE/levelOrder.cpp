#include<bits/stdc++.h>             //Binary Search Tree
using namespace std;

struct Node
{
   int data;
   struct Node *left;
   struct Node *right;

   //vector<Node*> children;         (N-ary tree)

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
//Level order using Queue
vector<vector<int>> levelOrder(struct Node* root) {   //level wise from left to right and top to bottom
    vector<vector<int>> vec;
    queue<Node*> q;

    if(root==NULL)
    return vec;

    q.push(root);

    int height=0;
    while(!q.empty()){
        vector<int> v;
        int n=q.size();

        height++;                            //height of tree

        while(n--){
            struct Node* node=q.front();
            v.push_back(node->data);         //front element of queue
            q.pop();

            if(node->left!=NULL)             //front element's left child and right child
            q.push(node->left);
            if(node->right!=NULL)
            q.push(node->right);

            /*
            N-ary tree
            for(Node*& child: node->children){         each node will have vector associated containing children 
                q.push(child);
            }
            */
        }
        vec.push_back(v);
    }
    cout<<"Height of Tree: "<<height<<endl;
    return vec;
}

int main(){
    root=insert(root, 8);
    root=insert(root, 5);
    root=insert(root, 1);
    root=insert(root, 7);
    root=insert(root, 12);
    root=insert(root, 75);

    vector<vector<int>> vec=levelOrder(root);

    for(int i=0;i<vec.size();i++){
        cout<<"[";
        for(int j=0;j<vec[0].size();j++){
            cout<<vec[i][j]<<", ";
        }
        cout<<"]";
    }
   return 0;
}