#include <iostream>
using namespace std;

template <class T>
class stack {
    T *arr;
    int top;
    int size;
    public:
    stack(int n){
        size=n ;
        arr=new T[size];
        top=-1;
    }
    void push(T x){
        if(top==size-1)
        cout<<"Stack Overflow"<<endl;
        else
        arr[++top]=x ;
    }
    void pop(){
        if(top==-1)
        cout<<"Stack Underflow"<<endl;
        else
        --top;
    }
    bool isEmpty(){
        if(top==-1)
        return true;
        else
        return false;
    }
    bool isFull(){
        if(top==size-1)
        return true;
        else
        return false;
    }
    int peek(){
        if(top==-1){
            cout<<"Empty Stack"<<endl;
            return -1;
        }
        else
        return arr[top];
    }
};
int main() {
    stack<int> s(3);
    cout<<"21BCS8745 EVA SABEEH"<<endl<<endl;
    cout<<"Inserting 3 elements in stack with size 3"<<endl;
    s.push(40);
    s.push(80);
    s.push(120);
    cout<<"Element at top is "<<s.peek()<<endl;
    cout<<"Trying to insert element after 3: "<<endl;
    s.push(10);
    cout<<"Removing all elements from Stack "<<endl ;
    s.pop();
    s.pop();
    s.pop();
    cout<<"Trying to remove element after 3: ";
    s.pop();
    cout<<endl;
    
    if(s.isEmpty())
    cout<<"Stack is Empty"<<endl;
    else
    cout<<"Stack not Empty"<<endl;
    
    if(s.isFull())
    cout<<"Stack is full"<<endl;
    else
    cout<<"Stack is not full"<<endl;
    
    return 0;
} 
