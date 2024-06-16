#include<bits/stdc++.h>
using namespace std;

struct node{
    struct node* prev;
    struct node* next;
    int data;
};

struct node* head=NULL;

void insertFront(int val){
    struct node* newNode=new node();
    newNode->data=val;
    newNode->prev=NULL;

    if(head==NULL)
    head=newNode;
    else{
        newNode->next=head;
        head->prev=newNode;
        head=newNode;
    }
}
void insertEnd(int val){
    struct node* newNode=new node();
    newNode->data=val;
    newNode->next=NULL;

    if(head==NULL){
        newNode->prev=NULL;
        head=newNode;
    }
    else{
        struct node* temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newNode;
        newNode->prev=temp;
    }
}
void insertAt(int val, int idx){
    struct node* newNode=new node();
    newNode->data=val;

    if(head==NULL)
    head=newNode;
    else if(idx==1){
        head->prev=newNode;
        newNode->next=head;
        head=newNode;
    }
    else{
        struct node* temp=head;
        for(int i=2;i<idx;i++){
            if(temp->next!=NULL){
                temp=temp->next;
            }
        }
        newNode->next=temp->next;
        newNode->prev=temp;
        temp->next=newNode;
    }
}
void deletel(int idx){
    if(head==NULL){                       //LL is empty
        return head; 
    }
    else if(idx==1){                      //head node
        head=head->next;
        head->prev=NULL;
    }
    else{                                 //delete node at idx
        struct node* temp=head;
        for(int i=2;i<idx;i++){
            if(temp->next!=NULL){
                temp=temp->next;
            }
        }
        if(temp->next->next==NULL){       //avoid null ptr access
            temp->next=NULL;
        }
        else{
            temp->next=temp->next->next;
            struct node* curr=temp;
            temp=temp->next;
            temp->prev=curr;
        }
    }
}
void reverseOrder(){
    struct node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    while(temp!=NULL){
        cout<<temp->data<<"<->";
        temp=temp->prev;
    }
    cout<<"NULL"<<endl;
}
void display(){
    struct node* temp=head;
    cout<<"NULL"<<"<->";
    while(temp!=NULL){
        cout<<temp->data<<"<->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}

int main(){
    insertFront(9);
    insertFront(7);
    insertEnd(21);
    insertEnd(35);
    insertAt(70, 2);
    deletel(3);
    display();
    return 0;
}