#include<bits/stdc++.h>
using namespace std;

struct node{
    struct node* next;
    int data;
};

struct node* head=NULL;          //initialise LL

void insertNode(int idx, int x){
    struct node* newNode=new node();
    newNode->data=x;
    if(head==NULL){              //LL is empty
        head=newNode;
        newNode->next=NULL;
    }
    else if(idx==1){             //at beginning
        newNode->next=head;
        head=newNode;
    }
    else{                        //at end or given position
        struct node* temp=head; 
        for(int i=2;i<idx;i++){
            if(temp->next!=NULL){
                temp=temp->next;
            }
        }
        newNode->next=temp->next;
        temp->next=newNode;
    }
}
struct node* swap(int k){
    struct node* curr=head;         //traverse LL
    struct node* left=head;         //first kth node
    struct node* right=head;        //last kth node

    int count=1;
    while(curr!=NULL){
        if(count<k)
        left=left->next;             //stop on kth node

        if(count>k)
        right=right->next;           //start after first kth node is find so count-k node will be found

        count++;
        curr=curr->next;
    }
    swap(left->data, right->data);

    return head;
}
void printList(){
    struct node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
}

int main(){
    insertNode(1, 4);
    insertNode(2, 66);
    insertNode(3, 72);
    insertNode(4, 90);
    insertNode(3, 31);
    insertNode(2, 11);
    insertNode(2, 1);
    insertNode(4, 66);

    head=swap(3);

    printList();
    return 0;
}

// https://leetcode.com/problems/swap-nodes-in-pairs/