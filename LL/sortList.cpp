#include<bits/stdc++.h>
using namespace std;

struct node{
    struct node* next;
    int data;
};

struct node* ll=NULL;          //initialise LL

void insert(struct node** head, int idx, int x){
    struct node* newNode=new node();
    newNode->data=x;
    if(head==NULL){              //LL is empty
        *head=newNode;
        newNode->next=NULL;
    }
    else if(idx==1){             //at beginning
        newNode->next=*head;
        *head=newNode;
    }
    else{                        //at end or given position
        struct node* temp=*head;
        for(int i=2;i<idx;i++){
            if(temp->next!=NULL){
                temp=temp->next;
            }
        }
        newNode->next=temp->next;
        temp->next=newNode;
    }
}
struct node* merge(struct node* ll1, struct node* ll2) {   //recursion approach
    struct node* head=NULL;
    if(ll1==NULL)
        return ll2;
    else if(ll2==NULL)
        return ll1;

    if(ll1->data<=ll2->data){
        head=ll1;               //assign node of ll to head
        head->next=merge(ll1->next, ll2);
    }
    else{
        head=ll2;
        head->next=merge(ll1, ll2->next);
    }
    return head;
}
void printList(struct node* head){
    if(head==NULL){
        cout<<"NULL"<<endl;;
    }
    else{
        cout<<head->data<<"->";
        printList(head->next);
    }
}

int main(){
    insert(&ll, 1, 18);
    insert(&ll, 2, 90);
    insert(&ll, 3, 66);
    insert(&ll, 4, 74);

    struct node* mergedList=NULL;      //initialising a merged list
    struct node* h=merge(ll1, ll2);
    printList(h);                      //displaying sorted list
    
    return 0;
}