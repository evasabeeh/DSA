#include<bits/stdc++.h>
using namespace std;
#define MAX 100

int stk[MAX];
int top=-1;

void peek(){
    cout<<stk[top]<<endl;
}
void isEmpty(){
    if(top==-1){
        cout<<"Stack is empty"<<endl;
    }
    else{
        cout<<"Stack is not empty"<<endl;
    }
}
void push(int val){
    if(top==MAX-1){
        cout<<"Overflow"<<endl;
    }
    else{
        top++;
        stk[top]=val;
    }
}
void pop(){
    if(top==-1){
        cout<<"Underflow"<<endl;
    }
    else{
        top--;
    }
}
void display(){
    for(int i=top;i>=0;i--){
        cout<<stk[i]<<" ";
    }
}
int main(){
    push(5);
    push(6);
    push(1);
    pop();
    peek();
    push(2);
    display();
    return 0;
}
