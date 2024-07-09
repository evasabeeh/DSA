#include <bits/stdc++.h>
using namespace std;

class Node
{
    public:
    Node *next;
    int data;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

void insertNode(Node* &head, int val){                 // node is passed by reference to make their changes without returning

}

void insertAtTail(Node* &tail, int val){               // tail always points to last node
    Node* newNode = new Node(val);
    tail->next = newNode;
    tail = tail -> next;
}

int main(){
    Node *head = new Node(1);
    cout<<head->data<<" "<<head->next<<endl;

    insertNode(head, 9);

    return 0;
}