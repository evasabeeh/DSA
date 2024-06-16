#include<bits/stdc++.h>
using namespace std;
#define MAX 100

int q[MAX];
int front=-1, rear=-1;

void peek(){
    cout<<q[front]<<endl;
}
void isEmpty(){
    if(front==-1){
        cout<<"Queue is empty"<<endl;
    }
    else{
        cout<<"Queue is not empty"<<endl;
    }
}
void push(int val){
    if(rear==MAX-1){
        cout<<"Queue is full"<<endl;
    }
    else{
        if(front==-1)
        front=0;
        
        rear++;
        q[rear]=val;
    }
}
void pop(){
    if(rear==-1||front>rear){
        cout<<"Underflow"<<endl;
    }
    else{
        front++;
    }
}
void display(){
    for(int i=front;i<=rear;i++){
        cout<<q[i]<<" ";
    }
}
int main(){
    push(5);
    push(6);
    push(1);
    pop();
    push(2);
    pop();
    display();
    return 0;
}
