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
    }
    else{
        newNode->next=head;
        head=newNode;
    }
}
void insertEnd(int x){
    struct node* newNode=new node();
    newNode->data=x;

    if(head==NULL){
        head=newNode;
    }
    else{
        struct node* temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newNode;
    }
}
void deleteStart(){
    if(head!=NULL)
    head=head->next;
}
void deleteEnd(){
    if(head!=NULL){
        struct node* temp=head;

        while(temp->next->next!=NULL){
            temp=temp->next;
        }
        temp->next=NULL;
    }
}
void printList(){
    struct node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}

int main(){
    cout<<"21BCS8745  EVA SABEEH\n\n";
    insertStart(7);
    insertStart(4);
    insertStart(3);
    insertEnd(1);
    deleteStart();
    insertEnd(2);
    deleteEnd();
    printList();
    return 0;
}