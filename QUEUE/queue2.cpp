#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    struct node* next;
};
struct node* front=NULL;
struct node* rear=NULL;

void peek(){
    cout<<front->data<<endl;
}
void isEmpty(){
    if(front==rear&&rear==NULL){
        cout<<"Queue is empty"<<endl;
    }
}
void push(int val){     //enqueue
    struct node* newNode=new node();      //new node
    newNode->data=val;
    newNode->next=NULL;

    if(rear==NULL){
        front=rear=newNode;
    }
    else{
        rear->next=newNode;
        rear=newNode;
    }
}
void pop(){             //deque
    if(front==NULL)
    return;
    else{
        struct node* temp=front;   //to delete it later
        front=front->next;

        if(front==NULL)
        rear=NULL;

        delete(temp);        //free node
    }
}
void display(){
    cout<<"Front: "<<front->data<<endl;
    cout<<"Rear: "<<rear->data;
}
int main(){
    push(5);
    push(6);
    push(1);
    push(7);
    pop();
    push(2);
    pop();
    display();
    return 0;
}
