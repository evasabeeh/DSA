#include<bits/stdc++.h>
using namespace std;

struct node{
    struct node* next;
    int data;
};

struct node* head=NULL;

void insertStart(int x){
    struct node* newNode=new node();
    newNode->data=x;

    if(head==NULL){
        head=newNode;
        head->next=head;
    }
    else{
        newNode->next=head->next;
        head->next=newNode;
    }
}
void insertEnd(int x){
    struct node* newNode=new node();
    newNode->data=x;

    if(head==NULL){
        head=newNode;
        head->next=head;
    }
    else{
        newNode->next=head->next;
        head->next=newNode;
        head=newNode;
    }
}
void deleteStart(){
    if(head!=NULL){
        struct node* ptr, *temp;
        ptr=head;
        while(ptr->next!=head){
            ptr=ptr->next;
        }
        temp=head;
        ptr->next=head->next;
        head=head->next;
    }
}
void deleteEnd(){
    if(head!=NULL){
        struct node* cur, *prev;
        cur=head;
        while(cur->next!=head){
            prev=cur;
            cur=cur->next;
        }
        prev->next=head;
    }
}
void printList(){
    struct node* temp=head;
    do{
        cout<<temp->data<<"->";
        temp=temp->next;
    }while(temp!=head);
    cout<<temp->data;
}

int main(){
    cout<<"21BCS8745  EVA SABEEH\n\n";
    insertStart(7);
    insertStart(4);
    deleteEnd();
    insertStart(3);
    insertEnd(1);
    deleteStart();
    insertEnd(2);
    insertEnd(5);
    printList();
    return 0;
}