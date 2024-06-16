#include<bits/stdc++.h>
using namespace std;

class Node{                     //dynamic-size stack
public:
    int data;
    Node* next;
};

Node* head=NULL;                //initialise stack

bool isEmpty(){                 //if stack ll is empty or not
    if(head==NULL)
    return true;
    else
    return false;
}
void push(int data){
    Node* stkNode=new Node();
    stkNode->data=data;
    stkNode->next=head;                       // 4 -> 3 -> 2 -> 1    //adding to beginning of ll
    
    head=stkNode;
}
int pop(){
    Node* stkNode=head;
    if(!isEmpty()){
        head=head->next;
        return head->data;
    }
    else
    return -1;
}
int peek(){
    if(isEmpty()){
        return INT_MIN;
    }
    else{
        return head->data;
    }
}
void display(){
    while(!isEmpty()){
        int top=peek();
        int m=pop();
        cout<<top<<" ";
    }
}

int main(){
    push(5);
    push(6);
    push(1);
    pop();
    int top=peek();
    cout<<"Top element: "<<top<<endl;
    push(2);
    display();
    return 0;
}