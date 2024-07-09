#include<bits/stdc++.h>
using namespace std;

struct node{
    struct node* next;
    int data;
};

struct node* head=NULL;          //initialise LL

void insertNode(int idx, int x){
    struct node* newNode=new node();
    newNode->data=x;
    if(head==NULL){              //LL is empty
        head=newNode;
        newNode->next=NULL;
    }
    else if(idx==1){             //at beginning
        newNode->next=head;
        head=newNode;
    }
    else{                        //at end or given position
        struct node* temp=head; 
        for(int i=2;i<idx;i++){
            if(temp->next!=NULL){
                temp=temp->next;
            }
        }
        newNode->next=temp->next;
        temp->next=newNode;
    }
}
void deleteNode(int idx){
    if(head==NULL){                       //LL is empty
        return; 
    }
    else if(idx==1){                      //head node
        head=head->next;
    }
    else{                                 //delete node at idx
        struct node* temp=head;
        for(int i=2;i<idx;i++){
            if(temp->next!=NULL){
                temp=temp->next;
            }
        }
        temp->next=temp->next->next;
    }
}
void deleteNodeVal(int value) {
    while(head!=NULL&&head->data==value)     //when head value is to be deleted
    head=head->next;

    node* curr=head;                  //current node
    node* prev=NULL;                  //previous node
    while(curr!=NULL){  
        if(curr->data==value){             //delete node value
            prev->next=curr->next;
        }
        else
        prev=curr;
        
        curr=curr->next;
    }
}
struct node* reverseList(){
    if(head==NULL||head->next==NULL)
    return head;

    struct node* curr=head;                //current node
    struct node* prev=NULL;                //previous node
        
    while(curr!=NULL){
        struct node* forw=curr->next;      //next node
        curr->next=prev;
        prev=curr;
        curr=forw;
    }
    head=prev;
    return head;
}
bool hasCycle() {                //check if LL has loop, if it will have somewhere ptr1 and ptr2 will coincide
    node* ptr1=head;             //slow ptr
    node* ptr2=head;             //fast ptr
    while(ptr2!=NULL&&ptr2->next!=NULL){
        ptr1=ptr1->next;
        ptr2=ptr2->next->next;                   //Tortoise and hare algo
        if(ptr1==ptr2)
        return true;
    }
    return false;
}
void printList(){
    struct node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
}

int main(){
    insertNode(1, 4);
    insertNode(2, 66);
    insertNode(3, 72);
    insertNode(4, 90);
    insertNode(3, 31);
    deleteNode(2);
    deleteNodeVal(72);
    head=reverseList();
    bool loop=hasCycle();
    cout<<"It has loop: "<<loop<<endl;
    printList();
    return 0;
}






/*     Recusive reverse
void reverse(Node* &head, Node* curr, Node* prev){
    if(curr == NULL){
        head = prev;
        return;
    }

    reverse( head, curr->next, curr);
    curr -> next = prev;
}
*/